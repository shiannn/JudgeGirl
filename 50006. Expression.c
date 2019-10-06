//#include "eval.h"
#include <stdio.h>

#define maxLen 100000
#define Add 1
#define minus 0
int clearformula [maxLen]; 

int eval(int exp[]) {
    /* add your code */
    int length = exp[0];
    int TempMultiDivide=exp[1];
    int Total = 0;
    /*remember current is add or minus*/
    int AddORMinus = Add;
    for(int i=2;i<1+length;i+=2){
        //printf("TempMultiDivide == %d\n",TempMultiDivide);
        //printf("Total == %d\n",Total);
        if(exp[i] == 3){
            TempMultiDivide *= exp[i+1];
        }
        else if(exp[i] == 4){
            if(exp[i+1]==0){
                return -2147483647;
            }
            TempMultiDivide /= exp[i+1];
        }
        else if(exp[i] == 1){
            if(AddORMinus == Add){
                Total += TempMultiDivide;
            }
            else if(AddORMinus == minus){
                Total -= TempMultiDivide;
            }
            AddORMinus = Add;
            TempMultiDivide=exp[i+1];
        }
        else if(exp[i] == 2){
            if(AddORMinus == Add){
                Total += TempMultiDivide;
            }
            else if(AddORMinus == minus){
                Total -= TempMultiDivide;
            }
            AddORMinus = minus;
            TempMultiDivide=exp[i+1];
        }
        else{
            return -2147483646;
        }
    }
    if(AddORMinus == Add){
        Total += TempMultiDivide;
    }
    else if(AddORMinus == minus){
        Total -= TempMultiDivide;
    }
    return Total;
}
int main(){
    int formula[]={11,1, 1, 2, 3, -3, 1, 4, 4, 5, 3, 6};
    int formula2[]={7, 1, 1, 4, 3, 3, 4, 2};
    int formula3[]={3,1, 0, 3};
    int formula4[]={3, 1, 4, 0};

    int ans = eval(formula4);
    printf("%d\n",ans);
}