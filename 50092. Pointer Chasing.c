#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include "chasing.h"

int myisdigit(char a[]){
    for(int i=0;a[i]!='\0';i++){
        if(isdigit(a[i])==0){
            return 0;
        }
    }
    return 1;
}
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    char raw[100];
    for(int i=0;i<a;i++){
        A[i] = NULL;
    }
    for(int i=0;i<b;i++){
        B[i] = NULL;
    }
    while(fgets(raw,100,stdin)!=NULL){
        //printf("%s",input);
        char AA[5];
        char A0[5];
        char BB[5];
        char B0[5];
        char trash[10];
        if(sscanf(raw,"%s%s%s%s%s",AA,A0,BB,B0,trash)!=4){
            printf("0\n");
            continue;
        }
        //printf("my %d %d\n",myisdigit(A0)==1,myisdigit(B0)==1);
        if(strlen(AA)==1&&strlen(BB)==1\
        && myisdigit(A0)==1\
        && myisdigit(B0)==1\
        &&((AA[0]=='A'&&BB[0]=='B')||(AA[0]=='B'&&BB[0]=='C'))
        ){  
            //printf("%s %s %s %s\n",AA,A0,BB,B0);            
            if(AA[0]=='A'){
                if((atoi(A0)) < a && atoi(B0) < b){
                    A[atoi(A0)] = &B[atoi(B0)];
                    printf("1\n");
                }
                else{
                    printf("0\n");
                }
            }
            else if(AA[0]=='B'){
                if((atoi(A0)) < b && atoi(B0) < c){
                    B[atoi(A0)] = &C[atoi(B0)];
                    printf("1\n");
                }
                else{
                    printf("0\n");
                }
            }
        }
        else{
            printf("0\n");
        }
    }
}
int main01(){
    chasing(NULL,0,NULL,0,NULL,0);
}
int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}