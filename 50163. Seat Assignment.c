#include <stdio.h>

int cars[1002][22][7];

int main(){
    int n;
    int request;
    int oneCar=1,oneRow=1,oneCol=1;
    int twoCar=1,twoRow=1,twoCol=1;
    scanf("%d",&n);
    while(scanf("%d",&request)!=EOF){
        if(request==1){
            int flag=0;
            int i,j,k;
            for(i=oneCar;i<=n;i++){
                for(j=(i==oneCar)?oneRow:1;j<=20;j++){
                    for(k=(j==oneRow)?oneCol:1;k<=5;k++){
                        if(cars[i][j][k]==0){
                            cars[i][j][k]=1;
                            printf("%d %d %d\n",i,j,k);
                            flag=1;
                        }
                        if(flag==1)break;
                    }
                    if(flag==1)break;
                }
                if(flag==1)break;
            }
            if(flag==1){
                oneCar = i;
                oneRow = j;
                oneCol = k;
            }
        }
        else if(request==2){
            int flag=0;
            int i,j,k;
            for(i=twoCar;i<=n;i++){
                for(j=(i==twoCar)?twoRow:1;j<=20;j++){
                    for(k=(j==twoRow)?twoCol:1;k<=5;k++){
                        if(k==1||k==2||k==4){
                            if(cars[i][j][k]==0&&cars[i][j][k+1]==0){
                                cars[i][j][k]=1;
                                cars[i][j][k+1]=1;
                                printf("%d %d %d %d %d %d\n",i,j,k,i,j,k+1);
                                flag=1;
                            }
                        }
                        if(flag==1)break;
                    }
                    if(flag==1)break;
                }
                if(flag==1)break;
            }
            if(flag==1){
                twoCar = i;
                twoRow = j;
                twoCol = k+1;
            }
            else if(flag==0){
                flag=0;
                for(i=oneCar;i<=n;i++){
                    for(j=(i==oneCar)?oneRow:1;j<=20;j++){
                        for(k=(j==oneRow)?oneCol:1;k<=5;k++){
                            if(cars[i][j][k]==0){
                                cars[i][j][k]=1;
                                printf("%d %d %d",i,j,k);
                                flag=1;
                            }
                            if(flag==1)break;
                        }
                        if(flag==1)break;
                    }
                    if(flag==1)break;
                }
                oneCar = i;
                oneRow = j;
                oneCol = k;
                flag=0;
                for(i=oneCar;i<=n;i++){
                    for(j=(i==oneCar)?oneRow:1;j<=20;j++){
                        for(k=(j==oneRow)?oneCol:1;k<=5;k++){
                            if(cars[i][j][k]==0){
                                cars[i][j][k]=1;
                                printf(" %d %d %d\n",i,j,k);
                                flag=1;
                            }
                            if(flag==1)break;
                        }
                        if(flag==1)break;
                    }
                    if(flag==1)break;
                }
                oneCar = i;
                oneRow = j;
                oneCol = k;
            }
        }
    }
}