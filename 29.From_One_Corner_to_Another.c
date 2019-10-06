#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int ans=count(r,c,1,1);
    printf("%d\n",ans);
    return 0;
}
int count(int r,int c,int now_r,int now_c){
    if(now_r==r&&now_c==c)return 1;
    if(now_r>r||now_c>c)return 0;
    return count(r,c,now_r+1,now_c)+count(r,c,now_r,now_c+1);
}
