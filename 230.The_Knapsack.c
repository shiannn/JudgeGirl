#include <stdio.h>
#include <stdlib.h>
#define max_things 20

struct things{
    int value,weight;
};
typedef struct things things;
things thing_array[max_things];

int max(int a,int b){
    if(a>b)return a;
    return b;
}
int knapsack(int N,int W,things thing_array[]){
    if(N==-1)return 0;

    int choose=0;
    if(W>=thing_array[N].weight){
        choose=thing_array[N].value+knapsack(N-1,W-thing_array[N].weight,thing_array);
    }
    int not_choose=knapsack(N-1,W,thing_array);
    return max(choose,not_choose);
}
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&thing_array[i].weight,&thing_array[i].value);
    }
    int ans=knapsack(n,W,thing_array);
    printf("%d\n",ans);
    return 0;
}
