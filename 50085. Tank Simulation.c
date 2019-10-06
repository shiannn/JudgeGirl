#include <stdio.h>

//#define debug
int map[520][520];
int N,M,L,W;

void printMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
}
int safe(int posm,int posn){
    int left=posn,up=posm;
    int right = posn+W-1, down=posm+L-1;
    if(left>=0&&left<M&&right>=0&&right<M&&up>=0&&up<N&&down>=0&&down<N){
        return 1;
    }
    return 0;
}
int countStone(int op, int posM,int posN){
    int count=0;
    if(op==1){
        for(int i=posM;i<posM+L;i++){
            if(map[i][posN+W]==2){
                count++;
            }
        }
    }
    if(op==2){
        for(int i=posN;i<posN+W;i++){
            if(map[posM+L][i]==2){
                count++;
            }
        }    
    }
    if(op==3){
        for(int i=posM;i<posM+L;i++){
            if(map[i][posN-1]==2){
                count++;
            }
        }    
    }
    if(op==4){
        for(int i=posN;i<posN+W;i++){
            if(map[posM-1][i]==2){
                count++;
            }        
        }   
    }
    if(op==5){
        for(int i=posN+1;i<posN+1+W;i++){
            if(map[posM+L][i]==2){
                count++;
            }        
        }  
        for(int i=posM+1;i<posM+L;i++){
            if(map[i][posN+W]==2){
                count++;
            }
        }
    }
    return count;
}
int dirM[]={200,0,1,0,-1,1};
int dirN[]={200,1,0,-1,0,1};
int main(){
    int O;
    scanf("%d%d%d%d",&N,&M,&L,&W);
    for(int i=0;i<L;i++){
        for(int j=0;j<W;j++){
            map[i][j] = 1;
        }
    }
    scanf("%d",&O);
    int On,Om;
    for(int i=0;i<O;i++){
        scanf("%d%d",&On,&Om);
        map[Om][On]=2;
    }
    int op;
    int posM=0,posN=0,canGo;
    while(scanf("%d",&op)!=EOF){
        canGo = 1;
        if(op==0){
            printMap();
        }
        if(op==1){
            //right
            if(safe(posM,posN+1)==0)canGo=0;
            if(countStone(op,posM,posN)>=2)canGo=0;
            if(canGo == 1){
                //go
                for(int i=posM;i<posM+L;i++){
                    map[i][posN]=0;
                    map[i][posN+W]=1;
                }
            }
        }
        if(op==2){
            //down
            if(safe(posM+1,posN)==0)canGo=0;
            if(countStone(op,posM,posN)>=2)canGo=0;
            if(canGo == 1){
                //go
                for(int i=posN;i<posN+W;i++){
                    map[posM][i]=0;
                    map[posM+L][i]=1;
                }
            }
        }
        if(op==3){
            //left
            if(safe(posM,posN-1)==0)canGo=0;
            if(countStone(op,posM,posN)>=2)canGo=0;
            if(canGo == 1){
                //go
                for(int i=posM;i<posM+L;i++){
                    map[i][posN-1]=1;
                    map[i][posN+W-1]=0;
                }
            }
        }
        if(op==4){
            //up
            if(safe(posM-1,posN)==0)canGo=0;
            if(countStone(op,posM,posN)>=2)canGo=0;
            if(canGo == 1){
                //go
                for(int i=posN;i<posN+W;i++){
                    map[posM+L-1][i]=0;
                    map[posM-1][i]=1;
                }
            }
        }
        if(op==5){
            //右下
            if(safe(posM,posN+1)==0)canGo=0;
            if(safe(posM+1,posN)==0)canGo=0;
            if(countStone(op,posM,posN)>=2)canGo=0;
            if(canGo == 1){
                //go
                for(int i=posN;i<posN+W;i++){
                    map[posM][i]=0;
                }
                for(int i=posM;i<posM+L;i++){
                    map[i][posN]=0;   
                }
                for(int i=posN+1;i<posN+1+W;i++){
                    map[posM+L][i]=1;
                }
                for(int i=posM+1;i<posM+1+L;i++){
                    map[i][posN+W]=1;   
                }
            }
        }
        if(op!=0 && canGo == 1){
            posM+=dirM[op];
            posN+=dirN[op];
        }
    }
    #ifdef debug
    printf("N==%d M==%d\n",N,M);
        printMap();
    #endif
}