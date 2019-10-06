#include <stdio.h>
#include <string.h>
#define maxString 200010

char InputString[maxString];
char OutputString[maxString];
char Command[20];
char parameter1[5];
char parameter2[5];
char invalidCommand[20];
int main(){
    int valid = 1;
    scanf("%s",InputString);
    while(valid == 1 && scanf("%s",Command)!=EOF){
        //printf("command == %s\n",Command);
        if(strcmp(Command,"end")==0){
            break;
        }
        else if(strcmp(Command,"replace")==0){
            scanf("%s",parameter1);
            scanf("%s",parameter2);
            char throw = parameter1[0];
            char addin = parameter2[0];
            //printf("%c %c",throw,addin);
            for(int i=0;InputString[i]!='\0';i++){
                if(InputString[i] == throw){
                    InputString[i] = addin;
                }
            }
        }
        else if(strcmp(Command,"remove")==0){
            scanf("%s",parameter1);
            char ToRemove = parameter1[0];
            for(int i=0,j=0;;i++){
                if(InputString[i] != ToRemove){
                    OutputString[j] = InputString[i];
                    j++;
                }
                if(InputString[i] == '\0'){
                    break;
                }
            }
            strcpy(InputString,OutputString);
        }
        else if(strcmp(Command,"addhead")==0){
            scanf("%s",parameter1);
            char head = parameter1[0];
            OutputString[0] = head;
            for(int i=0,j=1;;i++,j++){
                OutputString[j] = InputString[i];
                if(InputString[i] == '\0'){
                    break;
                }
            }
            strcpy(InputString,OutputString);
        }
        else if(strcmp(Command,"addtail")==0){
            scanf("%s",parameter1);
            char tail = parameter1[0];
            for(int i=0,j=0;;i++,j++){
                if(InputString[i] == '\0'){
                    OutputString[j] = tail;
                    OutputString[j+1] = '\0'; 
                    break;
                }
                OutputString[j] = InputString[i];
            }
            strcpy(InputString,OutputString);
        }
        else{
            valid = 0;
            strcpy(invalidCommand,Command);
        }
    }
    if(valid == 0){
        printf("invalid command %s\n",invalidCommand);
    }   
    else{
        printf("%s\n",InputString);
    } 
    return 0;
}