#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char key;
    int idx;
    struct Node* left,right;
}Node;

Node *newNode(char item){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}
Node *insert(Node* node, char key){
    if(node == NULL)return newNode(key);
    if(key < node->key)
        node -> left = insert(node -> left, key);
    if(key > node->key)
        node -> right = insert(node -> right, key);
    return node;
}
int main(){
    Node* root = NULL;
    char operation[15];
    char second[10];
    while(scanf("%s",operation)!=EOF){
        if(strcmp(operation, "print")==0){

        }
        else{
            int n;
            char x[5];
            Node* ptr = root;
            scanf("%s%s%d",second,x,&n);
            if(strcmp(second, "left")==0){
                while(ptr != NULL){
                    ptr = ptr->left;
                }
                insert(ptr, x)
            }
            else if(strcmp(second, "right")==0){
                
            }
            else{
                //k
                int k = atoi(second);
            }
        }
    }
}