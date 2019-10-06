#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxlen 15
//#define debug_input 

char first[maxlen];
char second[maxlen];
char third[maxlen];
int value[256];
int isassigned[256];
int l1,l2,l3;

int check();
void dfs(const char string[],int length,int idx,int string_num);
int main(){
    scanf("%s %s %s",first,second,third);
    l1=strlen(first);
    l2=strlen(second);
    l3=strlen(third);
#ifdef debug_input
    printf("%s\n%s\n%s\n",first,second,third);
#endif
    //value of every alphabet 26 value['A'] value['B']
    dfs(first,l1,0,0); 

    return 0;
    //dfs len1+len2+len3 layers
    //check
}
void dfs(const char string[],int length,int idx,int string_num){
    //printf("%s %d\n",string,idx);
    if(idx==length){
        if(string_num==0){
            //first
            dfs(second,l2,0,1);
        }
        else if(string_num==1){
            //second
            dfs(third,l3,0,2);
        }
        else if(string_num==2){
            //third
            //check
            if(check()==1){
                //printf("%d x %d = %d\n",A,B,C);
                int j;
                for(j=0;j<l1;j++){
                    printf("%d",value[first[j]]);
                }
                printf(" x ");
                for(j=0;j<l2;j++){
                    printf("%d",value[second[j]]);
                }
                printf(" = ");
                for(j=0;j<l3;j++){
                    printf("%d",value[third[j]]);
                }
                printf("\n");
                exit(0);
            }
            return;
        }
    }
    else{
        int i;
        if(isdigit(string[idx])){
            value[string[idx]]=string[idx]-'0';
            dfs(string,length,idx+1,string_num);
        }
        else if(isassigned[string[idx]]==0){//not yet assigned
            isassigned[string[idx]]=1;
            for(i=0;i<=9;i++){
                value[string[idx]]=i;//value['A']=2
                dfs(string,length,idx+1,string_num);
            }
            isassigned[string[idx]]=0;
            //value[string[idx]]=0;
        }
        else{ 
            dfs(string,length,idx+1,string_num);
        }
    }
}
int check(){
    //value['A','F','G','H']
    int i,first_value=0,second_value=0,third_value=0;
    for(i=0;i<l1;i++){
        first_value=10*first_value+value[first[i]]; 
    }
    for(i=0;i<l2;i++){
        second_value=10*second_value+value[second[i]]; 
    }
    for(i=0;i<l3;i++){
        third_value=10*third_value+value[third[i]]; 
    }
    //printf("first_value is %d\n",first_value);
    //printf("second_value is %d\n",second_value);
    //printf("third_value is %d\n",third_value);
    if(first_value*second_value==third_value)return 1;
    else return 0;
}
