#include<stdio.h>
#include<unistd.h>
int main()
{
    int ret;
    
    char *N="gcc";
    char *N2="test.c";
    char *N3="test.o";
    char *N4="-o p2.out";
    
    ret=fork();
    if(ret<0)
    {
        printf("error in creating child process\n");
        exit(0);
    }

    if(ret==0)
    {
        int k=execlp(N,N,N2,"-c",NULL);
        if(k<0)
        {
            printf("error in exec\n");
        }
    }
    else
    {
        int status=waitpid(-1,&status,NULL);
        printf("in main");
        int ret2=fork();
        if(ret2==0)
        {
            int L=execlp(N,N,N3,N4,NULL);
              if(L<0)
        {
            printf("error in exec\n");
        }
        }
        else
        {

        }
    }
}