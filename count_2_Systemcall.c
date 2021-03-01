#include <fcntl.h> 
#include<stdio.h>
int main() 
{ 
  int file_descriptor, size; 
  char *s = (char *) calloc(100, sizeof(char)); 
  
  file_descriptor = open("foo.txt", O_RDONLY); 
  if (file_descriptor < 0) 
  {
     perror("r1"); exit(1);
  } 
  
  size = read(file_descriptor, s, 100); 
  s[size] = '\0'; 
 //printf("file data: % s\n", s); 
 int words=0,line=0,j=0;
 int inword;
 for(j=0;j<strlen(s);j++)
 {
         if(s == ' ' || s == '\t' || s == '\n' || s == '\0')
        {
            if(inword)
            {
                inword=0;
                words++;
            }
        }
     if(s[j]=='\n')
        line++;
    else 
        inword=1;


 }
    printf("\ntotal no lines %d\ntotal no of words %d\ntotal no of characters: %d\n",line,words,j);
    close(file_descriptor);
}