#include <fcntl.h> 
#include<string.h>
int main(int arg,char* argc[]) 
{ 
  int file_descriptor, size; 
  char *n = (char *) calloc(100, sizeof(char)); 
  printf("\n%s\n%s",argc[1],argc[2]);
  file_descriptor = open(argc[1], O_RDONLY); 
  if (file_descriptor < 0) { 
    perror("r1"); 
  exit(1); 
  }
  
  size = read(file_descriptor, n, 100); 
  n[size] = '\0'; 
  printf("file data: % s\n", n); 
   
  int file_descriptor1 = open(argc[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
  printf("file is created\n");

   int k=write(file_descriptor1,n,strlen(n));

  // printf("data written\n");
  free(n);
   close(file_descriptor);
}

