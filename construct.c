#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

int getPivot(int T[], int N){
    for(int i=0;i<N;i++){
        //printf("%d ",T[i]);
        int sum1=0,sum2=0;
        for(int j=0;j<=i-1;j++){
            sum1 += T[j]*abs(j-i);
        }
        for(int k=i+1;k<=N-1;k++){
            sum2 += T[k]*abs(k-i);
        }
        //printf("sum1 == %d sum2 == %d\n",sum1,sum2);
        if(sum1 == sum2){
            return i;
        }
    }
    return -1;
}

Node *ConstructTree(int T[], int N){
    if(N==0){
        return NULL;
    }
    else if(N==1){
        Node * tempPtr = (Node *)malloc(sizeof(Node));
        tempPtr -> value = T[0];
        tempPtr -> left = NULL;
        tempPtr -> right = NULL;
        return tempPtr;
    }
    else if(N==2){
        Node *head = NULL;
        for(int i=0;i<N;i++){
            Node* temp = (Node*)malloc(sizeof(Node));
            temp -> left = head;
            temp -> value = T[i];
            head = temp;
        }
        return head;
    }
    else{//N >= 3
        int ret = getPivot(T,N);
        //printf("ret == %d\n",ret);
        if(ret == -1){
            //link each with left
            Node *head = NULL;
            for(int i=0;i<N;i++){
                Node* temp = (Node*)malloc(sizeof(Node));
                temp -> left = head;
                temp -> value = T[i];
                head = temp;
            }
            return head;
        }
        else{
            //recursive
            Node *mid = (Node*)malloc(sizeof(Node));
            mid -> value = T[ret];
            mid -> left = ConstructTree(T,ret);
            mid -> right = ConstructTree(T+ret+1,N-ret-1);
            return mid;
        }
    }
    
    //printf("%d\n",ret);
    //return NULL;
}