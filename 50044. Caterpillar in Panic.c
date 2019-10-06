#include <stdio.h>

int map[1010][1010];
int main(){
    
    {int N,M;}
    int N,M;
    scanf("%d%d",&N,&M);
    int SX,SY,EX,EY;
    scanf("%d%d%d%d",&SX,&SY,&EX,&EY);
    int row[1020];
    int col[1020];
    int cate;
    if(SX==EX){
        if(SY<EY){
            cate=0;
            for(int i=SY;i<=EY;i++,cate++){
                map[SX][i]=1;
                row[cate]=SX;
                col[cate]=i;
            }    
        }
        else{
            cate=0;
            for(int i=SY;i>=EY;i--,cate++){
                map[SX][i]=1;
                row[cate]=SX;
                col[cate]=i;
            }    
        }
    }
    else if(SY==EY){
        if(SX<EX){
            cate=0;
            for(int i=SX;i<=EX;i++,cate++){
                map[i][SY]=1;
                row[cate]=i;
                col[cate]=SY;
            }     
        }
        else{
            cate=0;
            for(int i=SX;i>=EX;i--,cate++){
                map[i][SY]=1;
                row[cate]=i;
                col[cate]=SY;
            }  
        }
    } 
    int length = cate;
    int head=0,tail=length-1;
    #ifdef debug
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
        printf("head==%d tail=%d len==%d\n",head,tail,length);
        for(int i=0;i<length;i++){
            printf("%d",row[i]);
        }
        printf("\n");
        for(int i=0;i<length;i++){
            printf("%d",col[i]);
        }
        printf("\n");
    #endif
    //更新1.map 2.row col 3.head tail 
    //先收尾巴
    //撞壁 撞到自己
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        int dir;
        scanf("%d",&dir);
        if(dir==0){
            //down
            if(row[head]+1 >= N)break;
            if(map[row[head]+1][col[head]]==1){
                if(!(row[head]+1==row[tail] && col[head]==col[tail]))break;
            }
            map[row[tail]][col[tail]] = 0;
            map[row[head]+1][col[head]] = 1;
            row[tail] = row[head]+1;
            col[tail] = col[head];
            head = tail;
            if(tail==0)tail = length-1;
            else tail-=1;
        }
        if(dir==1){
            //up
            if(row[head]-1<0)break;
            if(map[row[head]-1][col[head]]==1){
                if(!(row[head]-1==row[tail] && col[head]==col[tail]))break;
            }
            map[row[tail]][col[tail]] = 0;
            map[row[head]-1][col[head]] = 1;
            row[tail] = row[head]-1;
            col[tail] = col[head];
            head = tail;
            if(tail==0)tail = length-1;
            else tail-=1;
        }
        if(dir==2){
            //right
            if(col[head]+1>=M)break;
            if(map[row[head]][col[head]+1]==1){
                if(!(row[head]==row[tail] && col[head]+1==col[tail]))break;
            }
            map[row[tail]][col[tail]] = 0;
            map[row[head]][col[head]+1] = 1;
            row[tail] = row[head];
            col[tail] = col[head]+1;
            head = tail;
            if(tail==0)tail = length-1;
            else tail-=1;
        }
        if(dir==3){
            //left
            if(col[head]-1<0)break;
            if(map[row[head]][col[head]-1]==1){
                if(!(row[head]==row[tail] && col[head]-1==col[tail]))break;
            }
            map[row[tail]][col[tail]] = 0;
            map[row[head]][col[head]-1] = 1;
            row[tail] = row[head];
            col[tail] = col[head]-1;
            head = tail;
            if(tail==0)tail = length-1;
            else tail-=1;
        }
        #ifdef debugMap
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                printf("%d",map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        #endif
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
}