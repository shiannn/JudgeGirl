#include <stdio.h>

#define MAX(A,B) ((A)>=(B)? (A):(B))
#define MIN(A,B) ((A)<=(B)? (A):(B))

int min(int a,int b){
    return (a<=b)?a:b;
}
int max(int a,int b){
    return (a>=b)?a:b;
}
int cross(int a1,int a2,int b1,int b2){
    int determinant = a1*b2 - a2*b1;
    return determinant;
}
int isIntriangle(int a,int b, int x1,int y1,int x2,int y2,int x3,int y3){
    int v1x = x1-a,v1y = y1-b ,v2x = x2-a ,v2y = y2-b ,v3x = x3-a,v3y = y3-b;

    if(cross(v1x,v1y,v2x,v2y)>=0 &&cross(v2x,v2y,v3x,v3y)>=0 &&cross(v3x,v3y,v1x,v1y)>=0){
        return 1;
    }
    if(cross(v1x,v1y,v2x,v2y)<=0 &&cross(v2x,v2y,v3x,v3y)<=0 &&cross(v3x,v3y,v1x,v1y)<=0){
        return 1;
    }
    return 0;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    //int minX = min(min(x1,x2),x3);
    //int maxX = max(max(x1,x2),x3);
    //int minY = min(min(y1,y2),y3);
    //int maxY = max(max(y1,y2),y3);
    int minX = MIN(MIN(x1,x2),x3);
    int maxX = MAX(MAX(x1,x2),x3);
    int minY = MIN(MIN(y1,y2),y3);
    int maxY = MAX(MAX(y1,y2),y3);
    #ifdef debug
    printf("minX == %d maxX == %d minY == %d maxY == %d\n",minX,maxX,minY,maxY);
    #endif
    int count = 0;
    for(int x=minX;x<=maxX;x++){
        for(int y=minY;y<=maxY;y++){
            if(isIntriangle(x,y,x1,y1,x2,y2,x3,y3)==1){
                if(isIntriangle(x+1,y,x1,y1,x2,y2,x3,y3)==1&&isIntriangle(x,y+1,x1,y1,x2,y2,x3,y3)==1&&isIntriangle(x+1,y+1,x1,y1,x2,y2,x3,y3)==1){
                    count += 1;
                }
            }
        }
    }
    printf("%d\n",count);
}