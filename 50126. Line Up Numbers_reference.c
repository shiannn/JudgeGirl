#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int **l = NULL; int i=0,j=0; int flag;
    if (A[i] < B[j]) {
        l = &a[i];
        flag = 0;
    }else{
        l = &b[j];
        flag = 1;
    }
    while (*l != NULL) {
        if (A[i] > B[j]) {
            *l = &B[j];
            l = &b[j];
            j++;
            flag = 1;
        }else{
            *l = &A[i];
            l = &a[i];
            i++;
            flag = 0;
        }
    }
    if (flag == 0) *l = &B[j]; else *l = &A[i];
}