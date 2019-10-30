#include <stdio.h>
#include <string.h>

int table[30][30];
char trainingWord[200];
char resultWord[200];
int main(){
    int threshold;
    scanf("%d",&threshold);
    while(scanf("%s",trainingWord)!=EOF){
        int len = strlen(trainingWord);
        for(int i=0;i<=len-2;i++){
            table[trainingWord[i]-'a'][trainingWord[i+1]-'a'] += 1;
        }
    }
    //找出start pair
    int max=-1,maxi,maxj;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(j!=0)printf(" ");
            printf("%d",table[i][j]);
            if(table[i][j]>max){
                maxi = i;
                maxj = j;
                max = table[i][j];
            }
        }
        printf("\n");
    }
    int vis[26]={0};
    char start1 = 'a' + maxi;
    char start2 = 'a' + maxj;
    vis[maxi] = 1;
    vis[maxj] = 1;
    printf("%c%c",start1,start2);
    
    //逐步連上
    int prev = maxj;
    int flag = 0;
    while(flag == 0){
        int maxCount = -1, maxNext;
        //掃這一個row
        for(int i=0;i<26;i++){
            //printf("%d ",table[prev][i]);
            if(vis[i]==0){
                if(table[prev][i]>threshold && table[prev][i] > maxCount){
                    maxCount = table[prev][i];
                    maxNext = i;
                }
            }
        }
        if(maxCount == -1){
            flag = 1;
        }
        else{
            vis[maxNext] = 1;
            printf("%c",'a'+maxNext);
            prev = maxNext;
        }
    }
}