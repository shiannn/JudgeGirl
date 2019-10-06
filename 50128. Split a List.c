#include <stdio.h>
#include <stdlib.h>
#define maxNum 100010


int *tail[maxNum];
void split(int A[], int *a[], int *head[], int k){
    //get the number of elements of A
    int N=0;
    while(a[N++]);
    printf("N==%d\n",N);
    //for(int i=0;a[i]!=NULL;i++){
    //    N++;
    //}N++;
    //go through all the elements of A and connect the tail
    for(int i=0;i<N;i++){
        if(tail[A[i]%k]==0){
            head[A[i]%k] = &A[i];
            tail[A[i]%k] = &A[i];
        }
        else{
            a[tail[A[i]%k]-A] = &A[i];
            tail[A[i]%k] = &A[i];
        }
        a[tail[A[i]%k]-A] = NULL;
    }
    //cut the end with NULL
}
 
int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    int *a[N], *head[k];
    for (int i = 0; i < N-1; ++i)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for (int i = 0; i < k; ++i)
        head[i] = NULL;
    split(A, a, head, k);
    for (int i = 0; i < k; ++i) {
        if (head[i] == NULL)
            printf("NULL\n");
        else {
            int *tmp = head[i];
            printf("%d", *tmp);
            tmp = *(tmp-A+a);
            while (tmp != NULL) {
                printf(" %d", *tmp);
                tmp = *(tmp-A+a);
            }
            printf("\n");
        }
    }
    return 0;
}