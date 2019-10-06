#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}employee;

int n;
employee employeeArray[40];
int getIdx(char firstName[],char lastName[]){
    for(int i=0;i<n;i++){
        if(strcmp(firstName,employeeArray[i].first_name)==0&&strcmp(lastName,employeeArray[i].last_name)==0){
            return i;
        }
    }
    return -1;
}
int getBossIdx(int BossId){
    for(int i=0;i<n;i++){
        if(employeeArray[i].id==BossId){
            return i;
        }
    }
    return -1;
}

int disjointSet[40];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%s%s%d",&employeeArray[i].id,employeeArray[i].first_name,employeeArray[i].last_name,&employeeArray[i].boss_id);
    }
    for(int i=0;i<n;i++){
        disjointSet[i] = getBossIdx(employeeArray[i].boss_id);
    }
    #ifdef debug
    for(int i=0;i<n;i++){
        printf("i==%d dis==%d\n",i,disjointSet[i]);
    }
    #endif
    int m;
    scanf("%d",&m);
    char firstName1[40];
    char lastName1[40];
    char firstName2[40];
    char lastName2[40];
    for(int i=0;i<m;i++){
        scanf("%s%s%s%s",firstName1,lastName1,firstName2,lastName2);
        int idx1 = getIdx(firstName1,lastName1);
        int idx2 = getIdx(firstName2,lastName2);
        int subordinate=0,supervisor=0,colleague=0,unrelated=0;
        for(int par1=idx1;;par1=disjointSet[par1]){
            //printf("%s\n",employeeArray[par1].first_name);
            if(employeeArray[par1].id == employeeArray[idx2].id){
                subordinate=1;
            }
            if(disjointSet[par1]==par1)break;
        }
        //printf("++\n");
        for(int par2=idx2;;par2=disjointSet[par2]){
            //printf("%s\n",employeeArray[par2].first_name);
            if(employeeArray[par2].id == employeeArray[idx1].id){
                supervisor=1;
            }
            if(disjointSet[par2]==par2)break;
        }
        for(int par1=idx1;;par1=disjointSet[par1]){
            for(int par2=idx2;;par2=disjointSet[par2]){
                if(employeeArray[par2].id == employeeArray[par1].id){
                    colleague = 1;
                }
                if(disjointSet[par2]==par2)break;
            }
            if(disjointSet[par1]==par1)break;
        }
        if(supervisor==1){
            printf("supervisor\n");
        }
        else if(subordinate==1){
            printf("subordinate\n");
        }
        else if(colleague==1){
            printf("colleague\n");
        }
        else{
            printf("unrelated\n");
        }
        //printf("--\n");
    }
}