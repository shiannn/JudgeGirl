#include <stdio.h>


char CLeadingChar;
int KMaxDistance,Llength,NnumPrint;
int Count = 0;
char toPrint[1050];
void dfs(int idx, char prev){
    if(Count == NnumPrint)return;
    if(idx == Llength){
        printf("%s\n",toPrint);
        Count += 1;
    }
    else{
        if(prev+KMaxDistance > 'z'){
            for(int i='a';i<='a'-1 + KMaxDistance-('z'-prev);i++){
                char temp=i;
                //if(temp >'z')temp ='a' + temp -'z';
                toPrint[idx] = temp;
                dfs(idx+1,temp);
                toPrint[idx] = '\0';
            }
            for(int i=1;prev+i<='z';i++){
                char temp=(prev+i);
                //if(temp >'z')temp ='a' + temp -'z';
                toPrint[idx] = temp;
                dfs(idx+1,temp);
                toPrint[idx] = '\0';
            }
        }
        else{
            for(int i=1;i<=KMaxDistance;i++){
                char temp=(prev+i);
                //if(temp >'z')temp ='a' + temp -'z';
                toPrint[idx] = temp;
                dfs(idx+1,temp);
                toPrint[idx] = '\0';
            }
        }
    }
}
int main(){
    scanf("%c%d%d%d",&CLeadingChar,&KMaxDistance,&Llength,&NnumPrint);
    toPrint[0] = CLeadingChar;
    dfs(1,CLeadingChar);
}