#include <stdio.h>

#define NumQuiz 18
typedef struct{
    int rawScore;
    double scaledScore;
}Score;
 
typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;
 
typedef struct{
    int numStudent;
    Student student[1000];
}Classes;

void computeGrade(Classes classes[2]){
    double average0=0,average1=0,ratio;
    for(int i=0;i<NumQuiz;i++){
        average0=0,average1=0;
        for(int j=0;j<classes[0].numStudent;j++)average0+=classes[0].student[j].score[i].rawScore;
        average0 /= classes[0].numStudent;
        for(int j=0;j<classes[1].numStudent;j++)average1+=classes[1].student[j].score[i].rawScore;
        average1 /= classes[1].numStudent;
        if(average0>average1){
            ratio = average0 / average1;
            for(int j=0;j<classes[1].numStudent;j++){
                classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore*ratio;
                if(classes[1].student[j].score[i].scaledScore>100)classes[1].student[j].score[i].scaledScore = 100;
            }
            for(int j=0;j<classes[0].numStudent;j++)classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
        }
        else if(average1 > average0){
            ratio = average1 / average0;
            for(int j=0;j<classes[0].numStudent;j++){
                classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore*ratio;
                if(classes[0].student[j].score[i].scaledScore>100)classes[0].student[j].score[i].scaledScore = 100;
            }
            for(int j=0;j<classes[1].numStudent;j++)classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
        }
        else{
            for(int j=0;j<classes[0].numStudent;j++)classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
            for(int j=0;j<classes[1].numStudent;j++)classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
        }
    }
    for(int j=0;j<classes[0].numStudent;j++){
        classes[0].student[j].finalScore=0;
        for(int i=0;i<NumQuiz;i++)classes[0].student[j].finalScore+=classes[0].student[j].score[i].scaledScore;
        classes[0].student[j].finalScore *= 0.06;
        if(classes[0].student[j].finalScore>100)classes[0].student[j].finalScore=100;
        printf("%s %f\n",classes[0].student[j].id,classes[0].student[j].finalScore);
    }
    for(int j=0;j<classes[1].numStudent;j++){
        classes[1].student[j].finalScore=0;
        for(int i=0;i<NumQuiz;i++)classes[1].student[j].finalScore+=classes[1].student[j].score[i].scaledScore;
        classes[1].student[j].finalScore *= 0.06;
        if(classes[1].student[j].finalScore>100)classes[1].student[j].finalScore=100;
        printf("%s %f\n",classes[1].student[j].id,classes[1].student[j].finalScore);
    }
}
int main()
{
    Classes classes[2];
    scanf("%d", &classes[0].numStudent);
    for (int i = 0; i < classes[0].numStudent; i++) {
        scanf("%s", classes[0].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[0].student[i].score[j].rawScore);
        }
    }
    scanf("%d", &classes[1].numStudent);
    for (int i = 0; i < classes[1].numStudent; i++) {
        scanf("%s", classes[1].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[1].student[i].score[j].rawScore);
        }
    }
    computeGrade(classes);
    return 0;
}