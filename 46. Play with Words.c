#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[100000];
char operation[20];
char second[20];
int countAppear[500];
int vis[500];
int N = 0;
int main(){
    while(scanf("%s",operation)!=EOF){
        if(strcmp(operation,"insert")==0){
            char toInsert[20];
            scanf("%s%s",second,toInsert);
            if(strcmp(second,"left")==0){
                memmove(string+1,string,N);
                string[0] = toInsert[0];
            }
            else if(strcmp(second,"right")==0){
                strcat(string,toInsert);
            }
            else{
                int k = atoi(second);
                memmove(string+k,string+k-1,N-k+1);
                string[k-1] = toInsert[0];
            }
            N++;
        }
        if(strcmp(operation,"delete")==0){
            scanf("%s",second);
            if(strcmp(second,"left")==0){
                memmove(string,string+1,N-1);
            }
            else if(strcmp(second,"right")==0){
                string[N-1]='\0';
            }
            else{
                int k = atoi(second);
                memmove(string+k-1,string+k,N-k);
            }
            string[N-1]='\0';
            N--;
        }
        #ifdef debug
        printf("check == %s\n",string);
        #endif
    }
    char prev = 32;
    int tempMax=0,globalMax=0;
    for(int i=0;i<N;i++){
        if(string[i]==prev){
            tempMax++;
        }
        else{
            tempMax = 1;
        }
        if(tempMax>globalMax)globalMax=tempMax;
        prev = string[i];
    }
    prev = 32;
    tempMax=0;
    for(int i=0;i<N;i++){
        if(string[i]==prev){
            tempMax++;
        }
        else{
            tempMax = 1;
        }
        if(tempMax == globalMax)printf("%c ",string[i]);
        prev = string[i];
    }
    printf("%d\n",globalMax);
}