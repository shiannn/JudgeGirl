#include <stdio.h>
#include "BuildTree.h"

//odd   01234   (5-1)/2 == 2
//even  0123    (4-1)/2 == 1
//only 1        (1-1)/2 == 0

int countList(Node* list){
    int N=0;
    for(Node* ptr=list;ptr!=NULL;ptr=ptr->left){
        //printf("counting val==%d\n",ptr->val);
        N+=1;
    }
    return N;
}
Node* getidx(Node* list,int idx){
    Node* ret = list;
    for(int i=1;i<=idx;i++){
        //move right idx-1 times
        ret = ret->left;
    }
    return ret;
}

Node* BuildTree(Node* list1, Node* list2){
    if(list1==NULL && list2==NULL){
        return NULL;
    }
    else if(list1!=NULL && list2==NULL){
        return list1;
    }
    else if(list1==NULL && list2!=NULL){
        return list2;
    }
    else if(list1!=NULL && list2!=NULL){
        //printf("lst1==%d lst2==%d\n",list1->val,list2->val);
        int N1,N2;
        Node * root;
        Node *oneLeft,*oneRight;
        Node *TwoLeft,*TwoRight;
        Node *oneH,*TwoH;
        if(list1->val < list2->val){
            root = list1;
            oneH = list1->left;
            TwoH = list2;
        }
        else if(list2->val < list1->val){
            root = list2;
            oneH = list1;
            TwoH = list2->left;
        }
        
        //printf("here oneH==%d TwoH==%d\n",oneH->val,TwoH->val);
        N1 = countList(oneH);
        N2 = countList(TwoH);
        //被拿走可能變成0 oneLeft==NULL oneRight==NULL
        //printf("N1==%d N2==%d\n",N1,N2);

        oneLeft = oneH;
        TwoLeft = TwoH;
        //determine Right
        if(N1==0 && N2==0){
            oneRight=NULL;
            TwoRight=NULL;
        }
        else if(N1!=0 && N2==0){
            Node*temp1 = getidx(oneH,(N1-1)/2);
            oneRight = temp1->left;
            
            temp1->left = NULL;
            TwoRight=NULL;
        }
        else if(N1==0 && N2!=0){
            oneRight=NULL;

            Node*temp2 = getidx(TwoH,(N2-1)/2);
            TwoRight = temp2->left;
            temp2->left = NULL;
        }
        else if(N1!=0 && N2!=0){
            Node*temp1 = getidx(oneH,(N1-1)/2);
            oneRight = temp1->left;
            temp1->left = NULL;

            Node*temp2 = getidx(TwoH,(N2-1)/2);
            TwoRight = temp2->left;
            temp2->left = NULL;
        }
        //printf("root==%d\n",root->val);
        root -> left = BuildTree(oneLeft,TwoLeft);
        root -> right = BuildTree(oneRight,TwoRight);
        return root;
    }
}