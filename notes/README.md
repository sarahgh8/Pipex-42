# Pipex Project Checklist

## 📝 General Guidelines
- [✅] Ensure the project is written in C and adheres to the 42 Norm.
- [ ] Avoid unexpected quits (e.g., segmentation fault, bus error, double free).
- [ ] Handle memory management properly to avoid leaks.
- [✅] Create and test a Makefile:
  - [✅] Includes `NAME`, `all`, `clean`, `fclean`, and `re` rules.
  - [✅] Uses `cc` with `-Wall`, `-Wextra`, and `-Werror` flags.
  - [✅] Does not relink unnecessarily.
- [ ] Submit all required files: `Makefile`, `.c` files, `.h` files.
- [✅] Test thoroughly to ensure compliance with requirements.

## 🔨 Mandatory Part Implementation

### 1️⃣ Understand Requirements
- [ ] Program must be executable as: `./pipex file1 cmd1 cmd2 file2`.
- [✅] Simulate the shell command: `< file1 cmd1 | cmd2 > file2`.
- [ ] Use only the allowed functions:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.

### 2️⃣ Program Structure
- [ ] Parse command-line arguments:
  - [ ] Validate the number of arguments.
  - [ ] Extract `file1`, `file2`, `cmd1`, and `cmd2`.
- [ ] Handle file operations:
  - [ ] Open `file1` for reading.
  - [ ] Open or create `file2` for writing with proper permissions.
  - [ ] Handle errors during file operations (e.g., file not found, permission denied).
- [ ] Create a pipeline:
  - [ ] Use `pipe()` to set up communication between commands.
  - [ ] Fork processes for `cmd1` and `cmd2`.
  - [ ] Redirect:
    - `cmd1`'s `stdin` from `file1` and `stdout` to the pipe.
    - `cmd2`'s `stdin` from the pipe and `stdout` to `file2`.
- [ ] Execute commands using `execve()`:
  - [ ] Parse commands and their arguments.
  - [ ] Handle command not found or execution errors.
- [ ] Manage file descriptors:
  - [ ] Close unused descriptors in child processes.
  - [ ] Ensure descriptors are closed after use in the parent process.

### 3️⃣ Error Handling
- [ ] Check return values of all system calls.
- [ ] Print meaningful error messages using `perror()` or custom messages.
- [ ] Ensure the program exits gracefully on errors.

### 4️⃣ Memory Management
- [ ] Allocate memory carefully for dynamic operations.
- [ ] Free all allocated memory in error cases and upon program termination.

### 5️⃣ Testing
- [ ] Test various valid cases:
  - Example: `./pipex infile "ls -l" "wc -l" outfile`.
  - Example: `./pipex infile "grep a1" "wc -w" outfile`.
- [ ] Test edge cases:
  - Invalid files (`infile` not found, `outfile` permission denied).
  - Invalid commands (`cmd1` or `cmd2` not found).

## 🌟 Bonus Part (Optional)
- [ ] Implement multiple commands (e.g., `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`).
  - Simulate shell behavior: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`.
- [ ] Add support for `here_doc` syntax:
  - Example: `./pipex here_doc LIMITER cmd cmd1 file`.
  - Simulate: `cmd << LIMITER | cmd1 >> file`.

## 📚 Submission
- [ ] Verify all required files are in the repository.
- [ ] Double-check filenames and structure for correctness.
- [ ] Ensure the mandatory part is perfect before submitting bonuses.
- [ ] Use tests to defend your project during evaluations.

## ✅ Final Checklist
- [✅] Compile with `make` and ensure no errors or warnings.
- [ ] Pass all tests for the mandatory part.
- [ ] Bonus features work without breaking mandatory functionality.
- [ ] Submit to the git repository before the deadline.

## 📝 VERY IMPORTANT NOTES!
MY QUESTION IS: 

`oh so i'm changing the stdout file to be the output.txt file right ?`

ChatGPT said:

Exactly! 🎯

  When you redirect stdout to output.txt, you are essentially telling the program:

    "Hey, instead of sending all the output meant for the terminal (stdout) to the screen, send it to this file (output.txt) instead."

In technical terms:

    You're not "changing" the output.txt file itself.
    Instead, you're making stdout (file descriptor 1) point to output.txt so that any program output written to stdout ends up in output.txt.

MY QUESTION IS:

`okay so when i use < to redirect the stdin to point to another file, i basically take its content and pass it to the input of a specific command, and then i take the output of this command and using > i redirect the stdout to point to another file right ?`

ChatGPT said:

Yes, exactly! You've got it! 🎯

Let’s summarize the process in clear steps:

    < file: This redirects the content of file to the standard input (stdin) of the command.
        Instead of reading input from the terminal, the command will read from the file.

    Command (e.g., cmd1): This command receives the content from the file as its input (from stdin) and processes it.

    | (Pipe): If there's a pipe, the output of cmd1 becomes the input for the next command (cmd2).

    > file: This redirects the output of the final command (e.g., cmd2) to a file (file), instead of displaying it on the terminal.
        The result is saved in the specified file, either overwriting it or creating it if it doesn't exist.

Example for clarification:

$> < input.txt grep "pattern" | sort > output.txt

    < input.txt: The contents of input.txt are redirected as input to grep.
    grep "pattern": grep looks for lines containing the word "pattern" in the input (which is the content of input.txt).
    | sort: The lines found by grep are passed through the pipe (|) to sort, which arranges them alphabetically.
    > output.txt: The sorted lines from sort are redirected to output.txt (instead of showing them on the terminal).

In essence:

    < changes input to come from a file.
    > changes output to go into a file.

This is how you can manipulate data in Unix/Linux, combining reading, processing, and saving it in a single line of code!

If you need more details or examples, just let me know! 😊

```css
- what happens if we fork twice:

       Parent (original)
          /     \
   Parent'     Child1
    /   \        /   \
P'1    C1     P'2   C2
```
