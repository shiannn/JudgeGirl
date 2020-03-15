#include <stdio.h>

int Light[4][4];
int press[20];
int Totalmin = 30;
int pressAns[20];

void printLight(int backup[4][4],int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",backup[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void printPress(int Lend){
    int already = 0;
    for(int i=0;i<Lend;i++){
        if(press[i]==1){
            if(already!=0)printf(" ");
            printf("%d",i);
            already = 1;
        }
    }
    printf("\n");
}

int inverse(int a){
    if(a==1)return 0;
    else if(a==0)return 1;
}
int checkLight(int N,int Lend){
    int backup[4][4];
    int sumLight = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            backup[i][j] = Light[i][j];
            if(Light[i][j]==1){
                sumLight += 1;
            }
        }
    }
    //printf("ordSumLight == %d\n",sumLight);
    //return 1;
    //for 4 direction
    int dy[] = {0,1,0,-1,0};
    int dx[] = {0,0,1,0,-1};
    for(int k=0;k<Lend;k++){
        if(press[k]==1){
            int m = k / N;
            int n = k % N;
            //printf("m==%d n==%d\n",m,n);
            for(int dir=0;dir<5;dir++){
                int newy = m+dy[dir];
                int newx = n+dx[dir];
                if(newy<0 || newy>=N ||newx<0 || newx>=N)continue;
                if(backup[newy][newx]==1){
                    sumLight -= 1;
                }
                else if(backup[newy][newx]==0){
                    sumLight += 1;
                }
                backup[newy][newx]=inverse(backup[newy][newx]);
            }
            //printLight(backup,N);
        }
    }
    //printf("newSumLight == %d\n",sumLight);
    if(sumLight==0){
        return 1;
    }
    else if(sumLight==1){
        return 0;
    }
}
void dfs(int idx,int Lend,int N){
    if(idx == Lend){
        if(checkLight(N,Lend) == 1){
            int ones=0;
            for(int i=0;i<Lend;i++){
                if(press[i]==1)ones += 1;
            }
            if(ones<Totalmin){
                Totalmin = ones;
                for(int i=0;i<Lend;i++){
                    pressAns[i]=press[i];
                }
                //printPress(Lend);
            }
        }
    }
    else{
        //pressed
        press[idx] = 1;
        dfs(idx+1,Lend,N);
        press[idx] = 0;
        dfs(idx+1,Lend,N);
    }
}
int main(){
    int N,ignite;
    scanf("%d",&N);
    while(scanf("%d",&ignite)!=EOF){
        int i = ignite / N;
        int j = ignite % N;
        Light[i][j] = 1;
    }
#ifdef debug
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",Light[i][j]);
        }
        printf("\n");
    }
#endif
    int Lend = N*N;
    dfs(0,Lend,N);
    
    int already = 0;
    for(int i=0;i<Lend;i++){
        if(pressAns[i]==1){
            if(already!=0)printf(" ");
            printf("%d",i);
            already = 1;
        }
    }
    printf("\n");
}