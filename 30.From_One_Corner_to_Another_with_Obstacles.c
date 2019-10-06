#include <stdio.h>
#include <stdlib.h>
#define max_rc 13

int road[max_rc][max_rc];
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int i,j;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&road[i][j]);
        }
    }
    int ans=count(r,1,r,c);

    printf("%d\n",ans);
    return 0;
}
int count(int now_r,int now_c,int r,int c){
    if(road[now_r][now_c]==0)return 0;
    if(now_r<1||now_c>c)return 0;
    if(now_r==1&&now_c==c)return 1;
    return (count(now_r-1,now_c,r,c)+count(now_r,now_c+1,r,c));
}
