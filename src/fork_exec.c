#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child Process Executing ls -l\n");
        execl("/bin/ls", "ls", "-l", NULL);
    }
    else if (pid > 0)
    {
        printf("Parent Process Waiting...\n");
        wait(NULL);
        printf("Child Completed.\n");
    }
    else
    {
        printf("Fork Failed\n");
    }

    return 0;
}
