#include <stdio.h>
#include <stdlib.h>

#define maxSide 1010
#define max(x,y) (x>y?x:y)

//#define debugInput

int Matrix[maxSide][maxSide];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&Matrix[i][j]);
        }
    }
    #ifdef debugInput
    printf("\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
    #endif
    int RowOne=0,ColumnOne=0,DiagonalOne=0;
    int temp;
    for(int i=0;i<N;i++){
        temp = 0;
        for(int j=0;j<N;j++){
            if(Matrix[i][j]==1){
                temp++;
            }
            else{
                temp=0;
            }
            if(temp>RowOne){
               RowOne = temp;
            }
        }
    }
    for(int j=0;j<N;j++){
        temp = 0;
        for(int i=0;i<N;i++){
            if(Matrix[i][j]==1){
                temp++;
            }
            else{
                temp=0;
            }
            if(temp>ColumnOne){
                ColumnOne = temp;
            }
        }
    }
    //printf("%d\n",max(ColumnOne,RowOne));
    
    //diagonal
    for(int k=0;k<N;k++){
        temp = 0;
        for(int i=k,j=0;i<N && j<N;i++,j++){
            if(Matrix[i][j]==1){
                temp++;
            }
            else{
                temp=0;
            }
            if(temp>DiagonalOne){
               DiagonalOne = temp;
            }
        }
    }
    for(int k=0;k<N;k++){
        temp = 0;
        for(int i=0,j=k;i<N && j<N;i++,j++){
            if(Matrix[i][j]==1){
                temp++;
            }
            else{
                temp=0;
            }
            if(temp>DiagonalOne){
               DiagonalOne = temp;
            }
        }
    }
    
    if(ColumnOne>RowOne){
        if(DiagonalOne>ColumnOne){
            printf("%d\n",DiagonalOne);
        }
        else{
            printf("%d\n",ColumnOne);
        }
    }
    else{
        if(DiagonalOne>RowOne){
            printf("%d\n",DiagonalOne);
        }
        else{
            printf("%d\n",RowOne);
        }
    }
    
    return 0;
}