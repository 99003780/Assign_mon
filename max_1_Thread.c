#include <stdio.h> 
#include <pthread.h> 
  
// size of array 
#define MAXIMUM 16 
  
// maximum number of threads 
#define MAXIMUM_THREAD 4 
  
int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 }; 
int sum[4] = { 0 }; 
int part = 0; 
  int N;
void* sum_array(void* arg) 
{ 
  
    // Each thread computes sum of 1/4th of array 
    int thread_part = part++; 
    printf("\n thread part:%d",thread_part);
    for (N = thread_part * (MAXIMUM / 4); N < (thread_part + 1) * (MAXIMUM / 4); N++) 
        sum[thread_part] += a[N];
        printf("\nindex value:%d",N-1);
}
// Driver Code 
int main() 
{ 
  
    pthread_t threads[MAXIMUM_THREAD]; 
  
    // Creating 4 threads 
    for (int N = 0; N < MAXIMUM_THREAD; N++) 
        pthread_create(&threads[N], NULL, sum_array, (void*)NULL); 
  
    // joining 4 threads i.e. waiting for all 4 threads to complete 
    for (int N = 0; N < MAXIMUM_THREAD; N++) 
        pthread_join(threads[N], NULL); 
  
    // adding sum of all 4 parts 
    int total_sum = 0; 
    for (int N = 0; N < MAXIMUM_THREAD; N++) 
        total_sum += sum[N]; 
  
    printf("\nsum of array: %d",total_sum);
  
    return 0; 
} 