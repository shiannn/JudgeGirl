//ready time of each jobs
//number of tasks finished of each jobs(next job idx)
//ready time of each machines(completion time of tasks)
//find earliest completion job to do (small job idx)
#include <stdio.h>

typedef struct task{
    int idxMachine,timeTake;
}task;

typedef struct job{
    int ParrivalTime,QnumTasks;
    task taskArray[520];
}job;

job jobArray[520];
int readyEachJob[520];
int numberTasksFinishedEachJob[520];//To do 0
int readyEachMachine[520];
int main(){
    int Nmachines, Mjobs;
    int TotalTaskNumber = 0;
    scanf("%d%d",&Nmachines,&Mjobs);
    for(int i=0;i<Mjobs;i++){
        scanf("%d%d",&jobArray[i].ParrivalTime,&jobArray[i].QnumTasks);
        TotalTaskNumber += jobArray[i].QnumTasks;
        readyEachJob[i] = jobArray[i].ParrivalTime;
        for(int j=0;j<jobArray[i].QnumTasks;j++){
            scanf("%d%d",&jobArray[i].taskArray[j].idxMachine,&jobArray[i].taskArray[j].timeTake);
        }
    }
    #ifdef debug
    printf("Nmachines==%d Mjobs==%d\n",Nmachines,Mjobs);
    for(int i=0;i<Mjobs;i++){
        printf("job%d Arrival==%d NumTasks==%d\n",i,jobArray[i].ParrivalTime,jobArray[i].QnumTasks);
        for(int j=0;j<jobArray[i].QnumTasks;j++){
            printf("[idxMachine==%d timeTake==%d]",jobArray[i].taskArray[j].idxMachine,jobArray[i].taskArray[j].timeTake);
        }
        printf("\n");
    }
    #endif
    //jobArray[i].taskArray[numberTasksFinishedEachJob[i]] 第i個job準備要做的tasks
    
    /*all tasks number*/
    #ifdef debug
    printf("TotalTasks == %d\n",TotalTaskNumber);
    #endif
    
    while(TotalTaskNumber>=1){
        int EarliestTime = 5000010, ToDoJob, ToUseMachine;
        for(int i=0;i<Mjobs;i++){
            if(numberTasksFinishedEachJob[i]==jobArray[i].QnumTasks)continue;
            //get the complete time of the tasks
            task tempTask = jobArray[i].taskArray[numberTasksFinishedEachJob[i]];
            //task complete 會受 機器ready和Jobready影響
            int jobReady = readyEachJob[i];
            int MachineReady = readyEachMachine[tempTask.idxMachine];
            int tempCompletion;
            if(jobReady >= MachineReady){
                tempCompletion = jobReady + tempTask.timeTake;
            }
            else{
                tempCompletion = MachineReady + tempTask.timeTake;
            }
            if(tempCompletion < EarliestTime){
                ToDoJob = i;
                EarliestTime = tempCompletion;
                ToUseMachine = tempTask.idxMachine;
            }
        }
        //update
        readyEachJob[ToDoJob] = EarliestTime;
        numberTasksFinishedEachJob[ToDoJob] += 1;
        readyEachMachine[ToUseMachine] = EarliestTime;  
        TotalTaskNumber -= 1;
    }
    for(int i=0;i<Mjobs;i++){
        printf("%d\n",readyEachJob[i]);
    }
}