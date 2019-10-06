#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variableValue{
    char Name[10];
    int Value;
}variableValue;
variableValue variableValueArray[105]; 

char Lines[1010][100000];
int Num=0;

int getVariableIndex(char Name[]){
    for(int i=0;i<Num;i++){
        if(strcmp(Name,variableValueArray[i].Name)==0)return i;
    }
    return -1;
}
int main(){
    char Variable[10];
    char equality[5];
    char value[25];
    while(scanf("%s",Variable)!=EOF){
        if(strcmp(Variable,"END")==0)break;
        scanf("%s%s",equality,value);
        strcpy(variableValueArray[Num].Name,Variable);
        variableValueArray[Num].Value = atoi(value);
        Num++;
    }
#ifdef debug
    for(int i=0;i<Num;i++){
        printf("%s == %d\n",variableValueArray[i].Name,variableValueArray[i].Value);
    }
#endif
    //fgets讀到一個換行
    //char trash;
    //scanf("%c",&trash);
    //用scanf %c 讀走它
    int curLine = 0;
    while(fgets(Lines[curLine],100000,stdin)!=NULL){
        if(strcmp(Lines[curLine],"STOP")==0){
            curLine++;
            break;
        }
        curLine++;
    }
#ifdef debug
    for(int i=0;i<curLine;i++){
        printf("%d:%s",i,Lines[i]);
    }
#endif
    //去除換行?
    int runningLine = 1;
    while(strncmp(Lines[runningLine],"STOP",4)!=0){
        char segment[20];
        sscanf(Lines[runningLine],"%s",segment);
        if(strcmp(segment,"GOTO")==0){
            char Goto[20];
            char GotoLineStr[20];
            sscanf(Lines[runningLine],"%s%s",Goto,GotoLineStr);  
            int GotoLine = atoi(GotoLineStr);
            runningLine = GotoLine;
        }
        else if(strcmp(segment,"IF")==0){
            char IF[5];
            char Var1[20];
            char op[5];
            char Var2[20];
            char Goto[20];
            char GotoLineStr[20];
            sscanf(Lines[runningLine],"%s%s%s%s%s%s",IF,Var1,op,Var2,Goto,GotoLineStr);
            int idx1 = getVariableIndex(Var1);
            int Value1 = variableValueArray[idx1].Value;
            int idx2 = getVariableIndex(Var2);
            int Value2 = variableValueArray[idx2].Value;
            int GotoLine = atoi(GotoLineStr);
            if(strcmp(op,"==")==0){
                if(Value1==Value2){
                    runningLine = GotoLine;
                }
                else{
                    runningLine++;
                }
            }
            if(strcmp(op,"!=")==0){
                if(Value1!=Value2)runningLine = GotoLine;
                else runningLine++;
            }
            if(strcmp(op,">")==0){
                if(Value1>Value2){
                    runningLine = GotoLine;
                }
                else{
                    runningLine++;
                } 
            }
            if(strcmp(op,"<")==0){
                if(Value1<Value2)runningLine = GotoLine;
                else runningLine++;
            }
            if(strcmp(op,">=")==0){
                if(Value1>=Value2)runningLine = GotoLine;
                else runningLine++;
            }
            if(strcmp(op,"<=")==0){
                if(Value1<=Value2)runningLine = GotoLine;
                else runningLine++;
            }
        }
        else if(strcmp(segment,"PRINT")==0){
            char Print[8];
            char Var1[20];
            sscanf(Lines[runningLine],"%s%s",Print,Var1);
            int idx = getVariableIndex(Var1);
            printf("%d\n",variableValueArray[idx].Value);
            runningLine++;
        }
        else{
            //assign
            char Var0[20];
            char equality[5];
            char Var1[20];
            char Var2[20];
            char op[5];
            sscanf(Lines[runningLine],"%s%s%s%s%s",Var0,equality,Var1,op,Var2);
            int idx0 = getVariableIndex(Var0);
            int idx1 = getVariableIndex(Var1);
            int idx2 = getVariableIndex(Var2);
            int value0 = variableValueArray[idx0].Value;
            int value1 = variableValueArray[idx1].Value;
            int value2 = variableValueArray[idx2].Value;

            if(strcmp(op,"+")==0)value0 = value1 + value2;
            if(strcmp(op,"-")==0)value0 = value1 - value2;
            if(strcmp(op,"*")==0)value0 = value1 * value2;
            if(strcmp(op,"/")==0)value0 = value1 / value2;
            if(strcmp(op,"%")==0)value0 = value1 % value2;
            variableValueArray[idx0].Value = value0;
            runningLine++;
        }
    }
}