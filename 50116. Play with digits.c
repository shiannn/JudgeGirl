#include <stdio.h>

int main(){
    int numOfDigits, isEven, numOfZero=0, isEleven;
    int digit,count=0,odd=0,even=0;
    while(scanf("%d",&digit)!=EOF){
        if(digit == 0){
            numOfZero++;
        }
        count++;
        odd += (count%2==1)? digit:0;
        even += (count%2==0)? digit:0;
    }
    numOfDigits = count;
    isEven = (digit%2==0)? 1:0;
    isEleven = (abs(odd-even)%11==0)?1:0;

    //printf("count == %d digit == %d\n",count,digit);
    printf("%d\n%d\n%d\n%d\n",numOfDigits,isEven,numOfZero,isEleven);
}
int main2(){
    int a = 0;
    printf("%d\n",a/11);
}