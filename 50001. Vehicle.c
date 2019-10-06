#include <stdio.h>
#include <stdlib.h>

//#define debug

struct point{
    int x,y;
};
typedef struct point point;
struct CountGold{
    int c,d,e;
};
typedef struct CountGold CountGold;
struct decideDir{
    int a,b;
};
typedef struct decideDir decideDir;

int decideMoveDir(decideDir Dircoeff,point Current){
    return (abs(Dircoeff.a*Current.x+Dircoeff.b*Current.y)%4);
}
int getGold(point Current,CountGold Goldcoeff){
    //printf("%d %d %d %d %d\n",Goldcoeff.c,Current.x,Goldcoeff.d,Current.y,Goldcoeff.e);
    return (abs(Goldcoeff.c*Current.x+Goldcoeff.d*Current.y)%Goldcoeff.e);
}


int main1(){
    point trans1,trans2,start,Current;
    CountGold Goldcoeff; 
    decideDir Dircoeff;
    int Fuel;
    scanf("%d %d %d %d %d",&Dircoeff.a,&Dircoeff.b,&Goldcoeff.c,&Goldcoeff.d,&Goldcoeff.e);
    scanf("%d %d %d %d",&trans1.x,&trans1.y,&trans2.x,&trans2.y);
    scanf("%d %d %d",&start.x,&start.y,&Fuel);
    Current = start;

    int test = decideMoveDir(Dircoeff,Current);
    int get = getGold(Current,Goldcoeff);
    printf("%d\n",get);
}
int main(){

    point trans1,trans2,start,Current;
    CountGold Goldcoeff; 
    decideDir Dircoeff;
    int Fuel;
    scanf("%d %d %d %d %d",&Dircoeff.a,&Dircoeff.b,&Goldcoeff.c,&Goldcoeff.d,&Goldcoeff.e);
    scanf("%d %d %d %d",&trans1.x,&trans1.y,&trans2.x,&trans2.y);
    scanf("%d %d %d",&start.x,&start.y,&Fuel);
#ifdef debug
    printf("%d %d %d %d %d\n",Dircoeff.a,Dircoeff.b,Goldcoeff.c,Goldcoeff.d,Goldcoeff.e);
    printf("%d %d %d %d\n",trans1.x,trans1.y,trans2.x,trans2.y);
    printf("%d %d %d\n",start.x,start.y,Fuel);
#endif
    Current = start;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    int TotalGold = getGold(Current,Goldcoeff);
    while(Fuel>0){
        int MyDir = decideMoveDir(Dircoeff,Current);
        Current.x += dx[MyDir];
        Current.y += dy[MyDir];
        if(Current.x == trans1.x && Current.y == trans1.y){
            Current = trans2;
        }
        else if(Current.x == trans2.x && Current.y == trans2.y){
            Current = trans1;
        }
        else{
            int get = getGold(Current,Goldcoeff);
            TotalGold += get;
        }
        Fuel -= 1;
    }
    printf("%d\n",TotalGold);
    printf("%d %d\n",Current.x,Current.y);
    
    return 0;
}