#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("stdout_1.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    printf("%d\n", STDOUT_FILENO); // 1
    printf("%d\n", fd); // 3
    dup2(fd, STDOUT_FILENO); // Redirect stdout to the file (so that the file is written to instead of the terminal)
    close(fd); // close the file descriptor (it is no longer needed) cuz it is duplicated to STDOUT_FILENO (1)

    printf("%d\n", STDOUT_FILENO); // 1
    printf("%d\n", fd); // -1 (closed)

    printf("Hello, world!\n"); // This will be written to the file
    write(STDOUT_FILENO, "Hello, world!\n", 14); // This will also be written to the file

    return 0;
}