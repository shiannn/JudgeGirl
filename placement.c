void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    if(method==0){
        //first
        for(int i=0;i<M;i++){
            int flag = -1;
            for(int j=0;j<N;j++){
                if(bucket[j]>=ball[i]){
                   bucket[j]-=ball[i];
                   flag=j;
                   break;
                }
            }
            result[i] = flag;
        }
    }
    if(method==1){
        //best
        for(int i=0;i<M;i++){
            int flag = -1, max = 2147483647;
            for(int j=0;j<N;j++){
                if(bucket[j]>=ball[i]){
                   if(bucket[j]<max){
                       max = bucket[j];
                       flag=j;
                   }
                }
            }
            bucket[flag] -= ball[i];
            result[i] = flag;
        }
    }
    if(method==2){
        //worst
        for(int i=0;i<M;i++){
            int flag = -1, min = -2147483648;
            for(int j=0;j<N;j++){
                if(bucket[j]>=ball[i]){
                   if(bucket[j]>=min){
                       min = bucket[j];
                       flag=j;
                   }
                }
            }
            bucket[flag] -= ball[i];
            result[i] = flag;
        }
    }
}