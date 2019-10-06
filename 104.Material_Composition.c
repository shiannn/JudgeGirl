#include <stdio.h>
#include <stdlib.h>
void solve(int n);
int available(int a,int b,int c);
int DA,DB,DC,EA,EB,EC,FA,FB,FC;
int main()
{
    //int DA,DB,DC,EA,EB,EC,FA,FB,FC;
    int n;
    //int a,b,c;//material
    scanf("%d %d %d %d %d %d %d %d %d",&DA,&DB,&DC,&EA,&EB,&EC,&FA,&FB,&FC);
    scanf("%d",&n);
    solve(n);
    //printf("Hello world!\n");
    return 0;
}
void solve(int n){
    //printf("n==%d",n);
    if(n==0)return;
    int a,b,c;//material
    scanf("%d %d %d",&a,&b,&c);
    if(available(a,b,c))printf("yes\n");
    else{
    	printf("no\n");
    }
    solve(n-1);
}
int available(int a,int b,int c){
    if(a<0||b<0||c<0)return 0;
    else if(a==0&&b==0&&c==0)return 1;
    else{
        int temp1=available(a-DA,b-DB,c-DC);
        int temp2=available(a-EA,b-EB,c-EC);
        int temp3=available(a-FA,b-FB,c-FC);
        return (temp1||temp2||temp3);
    }
}

