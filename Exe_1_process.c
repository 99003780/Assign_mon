#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t return_;
	printf("welcome...pid=%d\n",getpid());
    char s1[100]="ls",s2[100],s3[100]="-l",s4[100],s5[100];
     printf(" 1 command\n");
       gets(s1);
       gets(s3);
	   gets(s4);
	   gets(s5);
	   	return_=fork();
	if(return_<0)
	{
		perror("fork");
		exit(1);
	}
	if(return_==0) 
	{
		printf("child-1-hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		int i=execlp(strcpy(s2,s1), strcpy(s2,s1),NULL);
		if(i<0)
		{
            printf("\nerror\n");
			perror("execv");
			exit(1);
		}
	}
	else		
	{
		printf("parent--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
				int return1=fork();
		if(return1==0)
		{
		printf("child-2-hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		int i=execlp(strcpy(s2,s3), strcpy(s2,s3),NULL);
		if(i<0)
		{
            printf("\nerror\n");
			perror("execv");
			exit(1);
			}
		}
		else
		{
			if(fork()==0)
			{
				int i=execlp(strcpy(s2,s4), strcpy(s2,s4),NULL);
				if(i<0)
				{
            		printf("\nerror\n");
					perror("execv");
					exit(1);
				}
			}
			else{
				if(fork()==0)
				{
					int i=execlp(strcpy(s2,s5), strcpy(s2,s5),NULL);
				if(i<0)
				{
            		printf("\nerror\n");
					perror("execv");
					exit(1);
				}
				}
				else{
					printf("\nEnter the fourth ccommand\n");
				}
				printf("\n Enter  the third command\n");
			}
		}
		}
	printf("Tnk u pid=%d\n",getpid());
	return 0;
}