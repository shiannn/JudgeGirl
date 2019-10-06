#include <stdio.h>
#include <stdlib.h>
#define max_numbers 10

int numbers[max_numbers];

int main()
{
    int N;
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&numbers[i]);
    }
    sort(numbers,N);
    //print(numbers,N);
    int ans[max_numbers]={0};
    int use[max_numbers]={0};
    permutation(numbers,N,0,ans,use);
    //printf("Hello world!\n");
    return 0;
}
void permutation(int array[],int N,int index,int ans[],int use[]){
    if(index==N){
        print(ans,N);
        return;
    }
    int i;
    for(i=0;i<N;i++){
        if(use[i]==0){
            ans[index]=array[i];
            use[i]=1;
            permutation(array,N,index+1,ans,use);
            use[i]=0;
        }
    }

}
void print(int array[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void sort(int array[],int N){
    int i,j;
    for(i=N-1;i>=1;i--){
        for(j=0;j<=i-1;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

