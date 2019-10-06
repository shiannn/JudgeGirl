#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define maxlength 100010
//#define debug
 
char SingleInput[maxlength];
char Result[maxlength];
char ptr[maxlength];
 
void merge(char*Result,char*SingleInput,char*Save){
    int i,j;
    for(i=0,j=0;Result[i]!='\0'&&SingleInput[j]!='\0';){
        #ifdef debug
        printf("res==%s sing==%s\n",res,sing);
        #endif
        if(strncmp(Result+i,SingleInput+j,3)<0){
            strncpy(Save+i+j,Result+i,3);
            i+=3;
        }
        else if(strncmp(Result+i,SingleInput+j,3)>=0){
            strncpy(Save+i+j,SingleInput+j,3);
            j+=3;
        }
        #ifdef debug
        printf("Save == %s\n",Save);
        #endif
    }
    if(SingleInput[j]!='\0'){
        strcpy(Save+i+j,SingleInput+j);
    }
    if(Result[i]!='\0'){
        strcpy(Save+i+j,Result+i);
    }
    #ifdef debug
        printf("Save == %s\n",Save);
    #endif
}
int main(){
    char* temp;
    scanf("%s",Result);
    while(scanf("%s",SingleInput)!=EOF){
        merge(Result,SingleInput,ptr);
        strcpy(Result,ptr);
        printf("%s\n",Result);
    }
}