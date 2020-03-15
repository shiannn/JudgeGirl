#include "lights.h"
#include <stdio.h>

void init(Lights *l){
    l->numOfBright = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            l->LightCells[i][j] = 0;
        }
    }
}
int numOfLights(Lights *l,int N){
    return l->numOfBright;
}
void flip(Lights *l,int i,int N){
    int m = i / N;
    int n = i % N;
    l -> numOfBright += (l -> LightCells[m][n]==1)?-1:1;
    l -> LightCells[m][n] = (l -> LightCells[m][n]==1)?0:1;
    if(m-1 >= 0){
        l -> numOfBright += (l -> LightCells[m-1][n]==1)?-1:1;
        l -> LightCells[m-1][n] = (l -> LightCells[m-1][n]==1)?0:1;
    }
    if(m+1 <= N-1){
        l -> numOfBright += (l -> LightCells[m+1][n]==1)?-1:1;
        l -> LightCells[m+1][n] = (l -> LightCells[m+1][n]==1)?0:1;
    }
    if(n-1 >= 0){
        l -> numOfBright += (l -> LightCells[m][n-1]==1)?-1:1;
        l -> LightCells[m][n-1] = (l -> LightCells[m][n-1]==1)?0:1;
    }
    if(n+1 <= N-1){
        l -> numOfBright += (l -> LightCells[m][n+1]==1)?-1:1;
        l -> LightCells[m][n+1] = (l -> LightCells[m][n+1]==1)?0:1;
    }
}
void printLights(Lights *l,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j!=0)printf(" ");
            printf("%d",l->LightCells[i][j]);
        }
        printf("\n");
    }
}