#include <stdio.h>
#include <stdlib.h>

struct point{
    int x,y;
};
typedef struct point point;
int main()
{
    int l,m;
    scanf("%d %d",&l,&m);
    point init;
    while(l/2>=m){
        init.x=l-l/2;
        init.y=l-l/2;
        tiles(l/2,init,1);
        l=l/2;
    }


    return 0;
}
void tiles(int m,point mid,int direction){
    if(m==1){
        printf("%d %d %d\n",direction,mid.x,mid.y);
        return;
    }
    if(direction==1){
        tiles(m/2,mid,direction);
        point temp;

        temp.x=mid.x-m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,direction);

        temp.x=mid.x+m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,2);


        temp.x=mid.x-m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,4);
    }
    if(direction==2){
        tiles(m/2,mid,direction);
        point temp;

        temp.x=mid.x+m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,direction);

        temp.x=mid.x-m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,1);


        temp.x=mid.x+m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,3);
    }
    if(direction==3){
        tiles(m/2,mid,direction);
        point temp;

        temp.x=mid.x+m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,direction);

        temp.x=mid.x+m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,2);


        temp.x=mid.x-m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,4);
    }
    if(direction==4){
        tiles(m/2,mid,direction);
        point temp;

        temp.x=mid.x-m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,direction);

        temp.x=mid.x+m/2;
        temp.y=mid.y+m/2;
        tiles(m/2,temp,3);


        temp.x=mid.x-m/2;
        temp.y=mid.y-m/2;
        tiles(m/2,temp,1);
    }
}
