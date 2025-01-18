### notes:
- `<` this symbol redirects the content of a file to the stdin of a command. so the command will get its input from the fil
e.
- `|` this symbol is a pipe, it takes the output of the command on the left and passes it as input to the command on the right. 


- `>` this symbol redirects the stdout of a command to a file. so the output of the command will be written to the file instead of the terminal.

- Let's combine them together: 
    - we have a text file `file.txt` that contains: `hi sarah` if we do `< file.txt grep "sarah"` the output will be `hi sarah` cuz we're passing that file for the stdin of `grep`, now if we do `<file.txt grep "sarah" | wc -w` we pass the output of grep as the input of `wc -w` so the output will be `2` cuz there are 2 words in the output of `grep "sarah"` which is `hi sarah`, now if we do `<file.txt grep "sarah" | wc -w > output.txt` we're redirecting the output of `wc -w` to the file `output.txt` so the output of the command will be written to the file instead of the terminal.

### Functions:

- access: checks the permissions of a file, returns 0 if the file exists and the user has the permission to read it, otherwise returns -1.

```c
#include <unistd.h>
#include <stdio.h>

int main()
{
    if (access("readfile", R_OK) == 0)
        printf("readfile is accessible in reading mode\n");
    if (access("writefile", W_OK) == 0)
        printf("writefile is accessible in writing mode\n");
    if (access("executefile", X_OK) == 0)
        printf("executefile is accessible in execution mode\n");
    if (access("rwfile", R_OK|W_OK) == 0)
        printf("rwfile is accessible in writing and reading mode\n");
}


In this example, we use the access function multiple times.

The first time we check whether the program can read readfile or not.

The second time we check whether the program can write in writefile or not.

The third time we check whether the program can execute executefile or not.

The fourth time is an example using the bitwise OR operator to check whether the file rwfile is accessible in read AND write mode or not.
```

- dup2: duplicates a file descriptor, it takes two arguments, the first one is the file descriptor that we want to duplicate, and the second one is the file descriptor that we want to duplicate it to.

```
Example in Real Life:

Think of dup2() like making a duplicate key for a door:

        oldfd is your original key.
        newfd is the duplicate key.
        Both keys can now unlock the same door 
        (representing the file or resource).
```
```c
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char *av[], char *env[])
{
    (void) ac;
    (void) av;
    int in;
    int out;
    char *grep_args[] = {"grep", "Lausanne", NULL};
    
    // open input and output files (assuming both files exist)
    in = open("in", O_RDONLY);
    out = open("out", O_WRONLY); 
    
    // replace standard input with input file
    dup2(in, 0);
    // close unused file descriptors
    close(in);
    close(out);
    
    // execute grep
    execve("grep", grep_args, env);
}

In this example, first we open both in and out file, in reading and writing mode respectively.

Then we use dup2() to replace the stdin file descriptor by the in file descriptor.
This way, whatever the command that comes after will read from the stdin will be whatever the content of in is since the stdin file descriptor now "points" to the in file.

Then, we can close in and out, we don't use them anymore, right ?

We set the stdin file descriptor to be the same as in, so now we only use stdin, in and out are not used anymore, we can close them.

Now, we use the execve() function to execute the grep shell command (this is explained below on this page). When grep is launched without any argument, it reads text from the standard input before executing. What will happen then ? 

Remember we replaced the stdin file descriptor by in, so grep will read from the standard input, the standard input now reads from the in file, so grep will execute on whatever the content of the in file is.
```

- pipe: creates a pipe, it takes an array of two integers, the first one is the file descriptor for the read end of the pipe, and the second one is the file descriptor for the write end of the pipe.

```c
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char *av[], char *env[])
{
    (void) ac;
    (void) av;
    int pipefd[2];
    int pid;
    
    char *cat_args[] = {"/bin/cat", "infile", NULL};
    char *grep_args[] = {"/usr/bin/grep", "Lausanne", NULL};
    
    // make a pipe
    // fds go in pipefd[0] and pipefd[1]
    pipe(pipefd);
    
    if (pid == 0)
    {
        // child process gets here and handles "grep Lausanne"
        // replace standard input with input part of the pipe
        dup2(pipefd[0], 0);
        
        // close unused half of the pipe
        close(pipefd[1]);
        
        // execute grep
        execve("/usr/bin/grep", grep_args, env);
    }
    else
    {
        // parent process gets here and handles "cat scores"
        // replace standard output with output part of pipe
        dup2(pipefd[1], 1);
        
        // close unused half of the pipe
        close(pipefd[0]);
        
        // execute cat
        execve("/bin/cat", cat_args, env);
    }
    // close unused pipe
    close(pipefd[0]);
    close(pipefd[1]);
    
    // wait for the child process to finish
    waitpid(pid);
}
```
