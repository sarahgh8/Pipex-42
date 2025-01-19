#include "pipex.h"

int main()
{
    if(fork() == 0)
        exit(1);
    sleep(100);
    



    return 0;
}