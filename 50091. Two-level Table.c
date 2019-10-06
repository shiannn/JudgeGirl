#include <stdio.h>
#include <stdlib.h>

int ***constructTable(const int A[],int B[]){
    //malloc sum(A) 個 int**
    int count=0;
    for(int i=0;A[i]!=0;i++){
        count++;
    }
    
    int ***firstLevelPtr = (int***)malloc((count+1)*sizeof(int**));
    firstLevelPtr[count] = NULL;

    int *ptr = &B[0];
    //printf("count==%d\n",count);
    for(int i=0;i<=count;i++){
        //printf("i==%d A[i]==%d\n",i,A[i]);
        firstLevelPtr[i] = (int**)malloc((A[i]+1)*sizeof(int*));
        //firstLevelPtr[i][A[i]+1] = NULL;
        for(int j=0;j<A[i];j++){   
            firstLevelPtr[i][j] = ptr;
            while(*ptr != 0){
                ptr++;
            }
            ptr++;
        }
        firstLevelPtr[i][A[i]] = NULL;
    }
    return firstLevelPtr;
}
int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}