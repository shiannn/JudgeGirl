#include <stdio.h>

char word[40];
int main(){
    char pre = 127;
    int count=0;
    while(scanf("%s",word)!=EOF){
        for(int i=0;word[i]!='\0';i++){
            if(word[i]!='a'&&word[i]!='e'&&word[i]!='i'&&word[i]!='o'&&word[i]!='u'){
                if(word[i]>pre)count++;
                pre = word[i];
            }
        }
    }
    printf("%d\n",count);
}