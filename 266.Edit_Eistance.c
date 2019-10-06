#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define max_strings 100
#define max_chars 11

char string_array[max_strings][max_chars];
int main()
{
    int k=0;
    while(scanf("%s",string_array[k])!=EOF){
        k++;
    }
    int min=INT_MAX;
    int temp;
    int i,j,ID1,ID2;
    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            int temp=distance(string_array[i],string_array[j]);
            if(temp<min){
                ID1=i;
                ID2=j;
                min=temp;
            }
            else if(temp==min){
                if(1000*i+j<1000*ID1+ID2){
                    ID1=i;
                    ID2=j;
                    min=temp;
                }
                else if(1000*i+j==1000*ID1+ID2){
                    //if(strcmp(string[i]))
                }
            }
        }
    }
    ID1++;
    ID2++;
    printf("%d %d %d\n",min,ID1,ID2);
    return 0;
}
int distance(char string1[],char string2[]){
    if(strlen(string1)==0)return strlen(string2);
    if(strlen(string2)==0)return strlen(string1);
    if(string1[0]==string2[0]){
        return distance(string1+1,string2+1);
    }
    else{
        return (1+min(distance(string1+1,string2),\
                   distance(string1,string2+1)));
    }
}
int min(int a,int b){
    if(a<b)return a;
    return b;
}
