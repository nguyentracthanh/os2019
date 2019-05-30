#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();
    if (pid)
    {
        // you are parent
        printf("Main process, first child process has id: %d\n",pid);
        wait(NULL);
        printf("Finishing executed first child process!\n");
        pid = fork();
        if(pid)
        {
            printf("Main process, second child process id: %d\n",pid);
            wait(NULL);
            printf("Finishing executed second child process!\n");
        }
    else if (pid == 0)
    {
        // you are child 2
        printf("child process 2 begin run:\n");
        char *arg[]={"/bin/free","-h",NULL};
        execvp(arg[0],arg);
    }
    else printf("error can not fork second child\n");
    }
  else if (pid == 0)
    {
        // you are child 1
        printf("child process 1 begin run:\n");
        char *arg[]={"/bin/ps","-ef",NULL};
        execvp(arg[0],arg);
    }
  else printf("error can not fork anything\n");
  return 0;
}
