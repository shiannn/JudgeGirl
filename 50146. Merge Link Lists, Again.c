#include "merge2.h"
#include <stdio.h>

Node *merge(Node *list[], int K){
    #ifdef ZIGZAG
    Node*ptr=NULL,*head=NULL;
    int stop=K;
    for(int i=0;i<K;i++){
        if(list[i]==NULL)stop--;
    }
    while(stop>0){
        for(int i=0;i<K;i++){
            if(list[i]!=NULL){
                if(ptr==NULL){
                    if(head==NULL)head=list[i];
                    ptr=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                }
                else{
                    ptr->next=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                    ptr=ptr->next;
                }
            }
        }
        if(stop==0)break;
        for(int i=K-1;i>=0;i--){
            if(list[i]!=NULL){
                if(ptr==NULL){
                    if(head==NULL)head=list[i];
                    ptr=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                }
                else{
                    ptr->next=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                    ptr=ptr->next;
                }
            }
        }
    }
    return head;
    #endif
    #ifdef TOPDOWN
    Node*ptr=NULL,*head=NULL;
    int stop=K;
    for(int i=0;i<K;i++){
        if(list[i]==NULL)stop--;
    }
    while(stop>0){
        for(int i=0;i<K;i++){
            if(list[i]!=NULL){
                if(ptr==NULL){
                    if(head==NULL)head=list[i];
                    ptr=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                }
                else{
                    ptr->next=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                    ptr=ptr->next;
                }
            }
        }
    }
    return head;
    #endif
    #ifdef BOTTOMUP
    Node*ptr=NULL,*head=NULL;
    int stop=K;
    for(int i=0;i<K;i++){
        if(list[i]==NULL)stop--;
    }
    while(stop>0){
        for(int i=K-1;i>=0;i--){
            if(list[i]!=NULL){
                if(ptr==NULL){
                    if(head==NULL)head=list[i];
                    ptr=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                }
                else{
                    ptr->next=list[i];
                    list[i]=list[i]->next;
                    if(list[i]==NULL)stop--;
                    ptr=ptr->next;
                }
            }
        }
    }
    return head;
    #endif
}