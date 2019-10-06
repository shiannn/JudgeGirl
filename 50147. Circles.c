#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x,y;
}point;

point pointArray[1000200];

int cmp(const void* p1,const void* p2){
    point*ptr1=(point*)p1;
    point*ptr2=(point*)p2;
    point myp1=*ptr1;
    point myp2=*ptr2;
    int r1r1 = myp1.x*myp1.x+myp1.y*myp1.y;
    int r2r2 = myp2.x*myp2.x+myp2.y*myp2.y;
    if(r1r1 > r2r2){
        return 1;
    }
    else if(r1r1 == r2r2){
        return 0;
    }
    else if(r1r1 < r2r2){
        return -1;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&pointArray[i].x,&pointArray[i].y);
    }
    qsort(pointArray,N,sizeof(point),cmp);
    int currentMax = 1, TotalMax = 0, TotalRadius;
    int curRadius = pointArray[0].x*pointArray[0].x+pointArray[0].y*pointArray[0].y;
    for(int i=1;i<N;i++){
        //printf("curRadius==%d\n",curRadius);
        if(pointArray[i].x*pointArray[i].x+pointArray[i].y*pointArray[i].y==curRadius){
            currentMax += 1;
        }
        else{
            if(currentMax>=TotalMax){
                TotalMax = currentMax;
                TotalRadius = curRadius;
            }
            currentMax = 1;
            curRadius = pointArray[i].x*pointArray[i].x+pointArray[i].y*pointArray[i].y;
        }
    }
    //最後再一次
    if(currentMax>=TotalMax){
        TotalMax = currentMax;
        TotalRadius = curRadius;
    }
    printf("%d\n",TotalRadius);
}