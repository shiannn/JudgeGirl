#include <stdio.h>

#define paper 0
#define scissor 1
#define stone 2
#define xWin 0
#define yWin 1
int a,b,c,d,e,f;

int main(){
    int X,Y,N;
    scanf("%d%d%d%d",&X,&a,&b,&c);
    scanf("%d%d%d%d",&Y,&d,&e,&f);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        //do something to X Y
        int w,k=1;
        while((X%3) == (Y%3)){
            //printf("X==%d Y==%d\n",X,Y);
            X=(a*X+b)%c;
            Y=(d*Y+e)%f;
            k++;
        }
        int x = (X%3),y = (Y%3);
        if(x == paper){
            if(y==scissor){
                w=yWin;
            }
            if(y==stone){
                w=xWin;
            }
        }
        if(x == scissor){
            if(y==paper){
                w=xWin;
            }
            if(y==stone){
                w=yWin;
            }
        }
        if(x == stone){
            if(y==paper){
                w=yWin;
            }
            if(y==scissor){
                w=xWin;
            }
        }
        printf("%d %d\n",w,k);   
        X=(a*X+b)%c;
        Y=(d*Y+e)%f;
    }
}