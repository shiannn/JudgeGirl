//對角線的 m+n是一樣的
#include <stdio.h>
#include <stdlib.h>

#define maxSide 1010

int mysquare[maxSide][maxSide];

int main(){
    int NSquare,kfirstNumber,m,n;
    scanf("%d %d %d %d",&NSquare,&kfirstNumber,&m,&n);
    while(kfirstNumber!=1){
        m+=1;
        n-=1;
        if(n<0){
            n=NSquare-1;
        }
        if(m>=NSquare){
            m=0;
        }
        kfirstNumber--;
    }

    int Total = NSquare*NSquare;
    int preM=m,preN=n;
    for(int i=1;i<=Total;i++){
        //printf("i==%d\n",i);
        //printf("m==%d n==%d\n",m,n);
        mysquare[m][n] = i;
        m-=1;
        n+=1;
        while((m<0||m>=NSquare || n>=NSquare || mysquare[m][n]!=0)&&i!=Total){
            if(m<0){
                m=NSquare-1;
            }
            if(m>=NSquare){
                m=0;
            }
            if(n>=NSquare){
                n=0;
            }
            if(mysquare[m][n]!=0){
                m=preM+1;
                n=preN;
            }
        }
        preM = m;
        preN = n;
        /*
        for(int ii=0;ii<NSquare;ii++){
            for(int jj=0;jj<NSquare;jj++){
                if(jj!=0){
                   printf(" ");
                }
                printf("%d",mysquare[ii][jj]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    for(int ii=0;ii<NSquare;ii++){
        for(int jj=0;jj<NSquare;jj++){
            if(jj!=0){
                printf(" ");
            }
            printf("%d",mysquare[ii][jj]);
        }
        printf("\n");
    }
    
    return 0;
}