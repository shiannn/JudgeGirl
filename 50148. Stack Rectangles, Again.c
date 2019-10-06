#include <stdio.h>

typedef struct rectangle{
    int l,w;
}rectangle;
rectangle rectangleArray[150];

int maxNumber=-1,maxArea=-1,minArea=5000000;

int safe(rectangle top,rectangle cur){
    #ifdef LARGEONSMALL
    if((cur.l>=top.l&&cur.w>=top.w)||(cur.l>=top.w&&cur.w>=top.l)){
        return 1;
    }
    else{
        return 0;
    }
    #endif
    #ifdef SMALLONLARGE
    if((cur.l<=top.l&&cur.w<=top.w)||(cur.w<=top.l&&cur.l<=top.w)){
        return 1;
    }
    else{
        return 0;
    }
    #endif
}

void dfs(int idx,int N,int prev,int sumArea){//prev底盤
    if(idx>maxNumber){
        maxArea=sumArea;
        minArea=sumArea;
        maxNumber=idx;
    }
    else if(idx==maxNumber){
        if(sumArea>maxArea)maxArea=sumArea;
        if(sumArea<minArea)minArea=sumArea;
    }
    for(int i=prev+1;i<N;i++){
        rectangle top=rectangleArray[prev];
        if(safe(top,rectangleArray[i])){
            dfs(idx+1,N,i,sumArea+rectangleArray[i].w*rectangleArray[i].l);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&rectangleArray[i].l,&rectangleArray[i].w);
    }
    #ifdef debug
    for(int i=0;i<n;i++){
        printf("%d %d\n",rectangleArray[i].l,rectangleArray[i].w);
    }
    #endif
    //每個人都來當底盤for
    for(int i=0;i<n;i++){
        dfs(1,n,i,rectangleArray[i].l*rectangleArray[i].w);
    }
    #ifdef MAXAREASUM
        printf("%d %d\n",maxNumber,maxArea);
    #elif MINAREASUM
        printf("%d %d\n",maxNumber,minArea);
    #endif
}