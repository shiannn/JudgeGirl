#include <stdio.h>
#include <stdlib.h>

#define maxSide 110
#define min(x,y) (x<=y?x:y)
#define max(x,y) (x>=y?x:y)
int Graph[maxSide][maxSide];

int main(){
    int Line,X,Y;
    scanf("%d %d %d",&Line,&Y,&X);
    int n,preX=-1,preY=-1,curX,curY;
    for(int i=0;i<Line;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d %d",&curX,&curY);
            //printf("%d %d",curA,curB);
            if(j==0){
                Graph[Y-curY-1][curX]=1;
                preX = curX;
                preY = curY;
                continue;
            }
            if((curX<0 || curX>=X)||(curY<0 || curY>=Y)){
                printf("ERROR %d %d\n",i+1,j+1);
                return 0;
            }
            if(curX==preX && curY != preY){
                //vertical
                for(int idx = min(curY,preY);idx<=max(curY,preY);idx++){
                    Graph[Y-1-idx][curX]=1;
                }
                
            }
            else if(curX !=preX && curY == preY){
                //horizon
                for(int idx = min(curX,preX);idx<=max(curX,preX);idx++){
                    Graph[Y-1-curY][idx]=1;
                }
            }
            else if(curX !=preX && curY != preY){
                //printf("CurX==%d CurY==%d\n",curX,curY);
                if(abs(curX-preX) != abs(curY-preY)){
                    printf("ERROR %d %d\n",i+1,j+1);
                    return 0;
                }
                else{
                    if(curX>preX && curY>preY){
                        for(int idx =curX,idy =curY;idx>=preX;idx--,idy--){
                            Graph[Y-1-idy][idx]=1;
                        }
                    }
                    else if(curX>preX && curY<preY){
                        for(int idx =curX,idy =curY;idx>=preX;idx--,idy++){
                            Graph[Y-1-idy][idx]=1;
                        }
                    }
                    else if(curX<preX && curY>preY){
                        for(int idx =curX,idy =curY;idx<=preX;idx++,idy--){
                            Graph[Y-1-idy][idx]=1;
                        }
                    }
                    else if(curX<preX && curY<preY){
                        for(int idx =curX,idy =curY;idx<=preX;idx++,idy++){
                            Graph[Y-1-idy][idx]=1;
                        }
                    }
                }
            }
            preX = curX;
            preY = curY;
        }
    }
    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            printf("%d",Graph[i][j]);
        }
        printf("\n");
    }
}