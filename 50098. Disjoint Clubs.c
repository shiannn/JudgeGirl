#include <stdio.h>
#include <stdlib.h>

long long int clubs[105];
int choose[105];
long long int allmember = 0;

void print(int K){
    for(int i=0;i<K;i++){
        printf("%d\n",choose[i]);
    }
    //printf("\n");
}

void dfs(int K_disjoints,int idx,int N_clubs,int prev){
    if(idx == K_disjoints){
        print(K_disjoints);
        exit(0);
    }
    else{
        for(int i=prev+1;i<N_clubs;i++){
            if((allmember & clubs[i])==0){
                long long int origin = allmember;
                allmember |= clubs[i];
                choose[idx] = i;
                dfs(K_disjoints,idx+1,N_clubs,i);
                allmember = origin;
            }
        }
    }
}

int main(){
    int N_clubs,K_disjoints;
    int M_members,member_id;
    scanf("%d%d",&N_clubs,&K_disjoints);
    for(int i=0;i<N_clubs;i++){
        scanf("%d",&M_members);
        for(int j=0;j<M_members;j++){
            scanf("%d",&member_id);
            long long int mask = 1; 
            clubs[i] = clubs[i]|(mask << member_id)  ;
        }
    }
#ifdef debug
    for(int i=0;i<N_clubs;i++){
        printf("%lld\n",clubs[i]);
    }
#endif
    //recursive choose disjoint
    dfs(K_disjoints,0,N_clubs,-1);
}