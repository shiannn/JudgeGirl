#include "calArea.h"

int s1 = 0;
int s2 = 0;
int deltaRight = 1;
int deltaDown = 0;

void RightShrink(NODE* head, int shrink){
    if(head->rightPtr!=NULL && head->downPtr==NULL){
        //go right, then keep minus
        deltaRight += 1;
        s1 += shrink;
        RightShrink(head->rightPtr,shrink);
    }
    else if(head->downPtr!=NULL && head->rightPtr==NULL){
        //go down, then shrink
        deltaDown += 1;
        RightShrink(head->downPtr,shrink+1);
    }
    else if(head->downPtr==NULL && head->rightPtr==NULL){
        return;
    }
}
void DownShrink(NODE* head, int shrink){
    if(head->rightPtr!=NULL && head->downPtr==NULL){
        //go right, then shrink
        DownShrink(head->rightPtr,shrink+1);
    }
    else if(head->downPtr!=NULL && head->rightPtr==NULL){
        //go down, then keep minus
        s2 += shrink;
        DownShrink(head->downPtr,shrink);
    }
    else if(head->downPtr==NULL && head->rightPtr==NULL){
        return;
    }
}
int calArea(NODE* head){
    //down and right two boundary linklist
    RightShrink(head->rightPtr,0);
    //printf("s1==%d\n",s1);
    DownShrink(head->downPtr,0);
    //printf("s2==%d\n",s2);
    //printf("deltaRight==%d deltaDown==%d\n",deltaRight,deltaDown);
    //respectly calculate the shrink
    int ans = (deltaRight*deltaDown-s1-s2);
    return ans;
}