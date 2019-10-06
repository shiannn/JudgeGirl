#include <stdio.h>
#include <string.h>

#define maxUser 40
#define maxlength 40
#define EARN "earns"
#define SPEND "spends"
#define GIVE "gives"
#define BECOME "becomes"    

int Nuser;
long long int balance[maxUser];
char userName[maxUser][maxlength];

int getUserIndex(char name[]){
    for(int i=0;i<Nuser;i++){
        if(strcmp(name,userName[i])==0)return i;
    }
    return -1;
}
int main(){
    scanf("%d",&Nuser);
    for(int i=0;i<Nuser;i++){
        scanf("%s%lld",userName[i],&balance[i]);
    }
    char tempUser1[maxlength];
    char tempUser2[maxlength];
    char instruction[maxlength];
    long long int amount;
    char trash[500];
    while(scanf("%s%s",tempUser1,instruction)!=EOF){
        int User1Index = getUserIndex(tempUser1);
        if(User1Index == -1){
            fgets(trash,500,stdin);
            continue;
        }
        int User2Index;
        if(strstr(instruction,EARN)!=NULL){
            scanf("%lld",&amount);
            balance[User1Index]+=amount;
        }
        else if(strstr(instruction,SPEND)!=NULL){
            scanf("%lld",&amount);
            if(balance[User1Index]>=amount){
                balance[User1Index]-=amount;
            }
        }
        else if(strstr(instruction,GIVE)!=NULL){
            scanf("%s",tempUser2);
            User2Index = getUserIndex(tempUser2);
            if(User2Index==-1){
                fgets(trash,500,stdin);
                continue;
            }
            scanf("%lld",&amount);
            if(balance[User1Index]>=amount){
                balance[User1Index]-=amount;
                balance[User2Index]+=amount;
            }
        }
        else if(strstr(instruction,BECOME)!=NULL){
            scanf("%lld",&amount);
            balance[User1Index]=amount;
        }
        else{
            fgets(trash,500,stdin);
            continue;
        }
    }
    for(int i=0;i<Nuser;i++){
        printf("%s %lld\n",userName[i],balance[i]);
    }
}
int main01(){
    char a[]="aaaRaybbb";
    int ret = strstr(a,"Raya");
    printf("%p\n",ret);
}
//strncmp
/*
TGdamLdlInSBCpDpcysgHgKKYYr 77
EemMhPYuSMcfEDjTgzygtEOzoaxOrF 2515
lWHsLiMDUqlyvu 111
vUkOyYQo 1217
cSWkphgXztHNWBdJBy 88
CbRMsRmi 283
zigwUwDCVFVCU 1494
AdIYJicKZqEteoytOizMcxpEswbw 2964
Dtam 200
WWVVOAQTOpme 939
QcLIiFekcXhh 1843
tMQp 856
NYNfReuFiuvBYIjgnPSRpZZhIUTyMd 998
*/