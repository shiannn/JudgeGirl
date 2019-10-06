#include <stdio.h>
#include <stdlib.h>

#define maxNM 510

int Map[maxNM][maxNM];
void printMap(int N,int M){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(j!=0)printf(" ");
            printf("%d",Map[i][j]);
        }
        printf("\n");
    }
}
int Prow,Pcol,Penergy;
long long sumWeight = 0;
void move(int dir,int N,int M){
    int closest = -1;
    if(dir == 1){
        for(int j=M-1;j>=Pcol+1;j--){
            sumWeight += Map[Prow][j];
            if(Map[Prow][j] == 0){
                closest = j;
                sumWeight = 0;
            }
        }
        if(closest != -1 && Penergy >= sumWeight){
            for(int j=closest;j>=Pcol+1;j--){
                Map[Prow][j] = Map[Prow][j-1];     
            }
            Map[Prow][Pcol] = 0;
            Penergy -= sumWeight;
            Map[Prow][Pcol+1] = Penergy;
            Pcol++;
        }
    }
    if(dir == 2){
        for(int i=N-1;i>=Prow+1;i--){
            sumWeight += Map[i][Pcol];
            if(Map[i][Pcol] == 0){
                closest = i;
                sumWeight = 0;
            }
        }
        if(closest != -1 && Penergy >= sumWeight){
            for(int i=closest;i>=Prow+1;i--){
                Map[i][Pcol] = Map[i-1][Pcol];
            }
            Map[Prow][Pcol] = 0;
            Penergy -= sumWeight;
            Map[Prow+1][Pcol] = Penergy;
            Prow++;
        }
    }
    if(dir == 3){
        for(int j=0;j<=Pcol-1;j++){
            sumWeight += Map[Prow][j];
            if(Map[Prow][j] == 0){
                closest = j;
                sumWeight = 0;
            }
        }
        if(closest != -1 && Penergy >= sumWeight){
            for(int j=closest;j<=Pcol-1;j++){
                Map[Prow][j] = Map[Prow][j+1];
            }
            Map[Prow][Pcol] = 0;
            Penergy -= sumWeight;
            Map[Prow][Pcol-1] = Penergy;
            Pcol--;
        }
    }
    if(dir == 4){
        for(int i=0;i<=Prow-1;i++){
            sumWeight += Map[i][Pcol];
            if(Map[i][Pcol] == 0){
                closest = i;
                sumWeight = 0;
            }
        }
        if(closest != -1 && Penergy >= sumWeight){
            for(int i=closest;i<=Prow-1;i++){
                Map[i][Pcol] = Map[i+1][Pcol];
            }
            Map[Prow][Pcol] = 0;
            Penergy -= sumWeight;
            Map[Prow-1][Pcol] = Penergy;
            Prow--;
        }
    }
    sumWeight = 0;
    //printf("closest == %d\n",closest);
    //printf("Prow==%d Pcol==%d\n",Prow,Pcol);
}
int main(){
    int N,M,numStone,Stonerow,Stonecol,StoneWeight;
    scanf("%d%d",&N,&M);
    scanf("%d%d%d",&Prow,&Pcol,&Penergy);
    scanf("%d",&numStone);
    Map[Prow][Pcol] = Penergy;
    for(int i=0;i<numStone;i++){
        scanf("%d%d%d",&Stonerow,&Stonecol,&StoneWeight);
        Map[Stonerow][Stonecol] = StoneWeight;
    }
    int instruction;
    while(scanf("%d",&instruction)!=EOF){
        if(instruction == 0){
            printMap(N,M);
        }
        if(instruction == 1){
            //right
            move(instruction,N,M);
        }
        if(instruction == 2){
            //down
            move(instruction,N,M);
        }
        if(instruction == 3){
            //left
            move(instruction,N,M);
        }
        if(instruction == 4){
            //up
            move(instruction,N,M);
        }
    }
}