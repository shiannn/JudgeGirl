#include <stdio.h>

int weight[18][18];
int Image[18][18];

void inputImage(int Image[18][18],int M){
    for(int j=0;j<M;j++)for(int k=0;k<M;k++)scanf("%d",&Image[j][k]);
}
void initialize(int weight[18][18],int M){
    for(int i=0;i<M;i++)for(int j=0;j<M;j++)weight[i][j]=1;
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    initialize(weight,M);
    for(int i=0;i<N;i++){
        int label;
        scanf("%d",&label);
        inputImage(Image,M);
        //train
        int sum=0;
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                //printf("%d ",Image[j][k]);
                sum += weight[j][k]*Image[j][k];
            }
        }
        int Threshlod = 2*M*M;
        if(sum>=Threshlod){
            //accept
            if(label==0){
                for(int j=0;j<M;j++){
                    for(int k=0;k<M;k++){
                        if(Image[j][k]!=0){
                            weight[j][k]/=2;
                            if(weight[j][k]==0)weight[j][k]=1;
                        }
                    }
                }
            }
        }
        else{
            //reject
            if(label==1){
                for(int j=0;j<M;j++){
                    for(int k=0;k<M;k++){
                        if(Image[j][k]!=0){
                            weight[j][k]*=2;
                        }
                    }
                }
            }
        }
    }
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        int sum=0;
        int Threshlod = 2*M*M;
        inputImage(Image,M);
        for(int j=0;j<M;j++)
            for(int k=0;k<M;k++)
                sum += weight[j][k]*Image[j][k];
        if(sum>=Threshlod)
            printf("1\n");
        else 
            printf("0\n");
    }
}