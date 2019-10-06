#include <stdio.h>

int main(){
    int N,M;scanf("%d%d",&N,&M);
    int m=0,n=0,insturction;
    printf("%d\n%d\n",n,m);
    while(scanf("%d",&insturction)!=EOF){
        #ifdef debug
            printf("[de] ins==%d\n",insturction);
        #endif
        int dir = insturction%5;
        if(dir==0)continue;
        if(dir==1){
            if(n+insturction<=N-1)n+=insturction;
            else continue;
        }
        else if(dir==2){
            if(n-insturction>=0)n-=insturction;
            else continue;
        }
        else if(dir==3){
            if(m+insturction<=M-1)m+=insturction;
            else continue;
        }
        else if(dir==4){
            if(m-insturction>=0)m-=insturction;
            else continue;
        }
        printf("%d\n%d\n",n,m);
    }
    return 0;
}