#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    unsigned int H,TotalHeight=0;
    scanf("%d%d",&n,&m);
    int TotalRowIdx,TotalColIdx;
    for(int i=0;i<n;i++){
        int maxColIndex1=-1,maxColIndex2=-1;
        unsigned int maxheight1=0;
        unsigned int maxheight2=0;
        for(int j=1;j<=m;j++){
            scanf("%u",&H);
            if(H >= maxheight1){
                maxheight2 = maxheight1, maxColIndex2 = maxColIndex1;
                maxColIndex1 = j, maxheight1 = H;
            }
            else{
                if(H >= maxheight2){
                    maxColIndex2 = j, maxheight2 = H;
                }
            }
        }
        printf("%d %d\n",maxColIndex1,maxColIndex2);
        if(maxheight1 >= TotalHeight){
            TotalRowIdx = i+1;
            TotalColIdx = maxColIndex1;
            TotalHeight = maxheight1;
        }
    }
    printf("%d %d\n",TotalRowIdx,TotalColIdx);
}