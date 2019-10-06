#include <stdio.h>
#include <string.h>

char word[100000];
int valpos[100000];
const char tmp = '+';

int main(){
    int sy1,sy2,count;
    while(scanf("%s%d%d",word,&sy1,&sy2)!=EOF){
        count = 0;
        memset(valpos,0,100000);
        for(int i=0;word[i]!='\0';i++){
            if(word[i] == 'a'||word[i] == 'e'||word[i] == 'i'||word[i] == 'o'||word[i] == 'u'){
                valpos[count] = i;
                count++;
            }
        }
        //sy1 syllable means valpos[sy1-1]+1 ~ valpos[sy1]
        int N = strlen(word);
        int st1,ed1,st2,ed2;
        st1 = (sy1==0)? 0:valpos[sy1-1]+1;
        ed1 = (sy1==0)? valpos[0]:valpos[sy1];
        st2 = (sy2==0)? 0:valpos[sy2-1]+1;
        ed2 = (sy2==0)? valpos[0]:valpos[sy2];
        for(int i=0;i<N;i++){
            printf("%c",(i>=st1 && i<=ed1)? word[i]:tmp);
        }
        printf("\n");
        for(int i=0;i<N;i++){
            printf("%c",(i>=st2 && i<=ed2)? word[i]:tmp);
        }
        printf("\n");
        for(int i=0;i<N;i++){
            printf("%c",(!(i>=st1 && i<=ed1) && !(i>=st2 && i<=ed2))?word[i]:tmp);
        }
        printf("\n");
    }
}