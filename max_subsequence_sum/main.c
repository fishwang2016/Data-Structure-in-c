#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int isNegative(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        if (a[i]>=0)
            return 0;
    }
    return 1;

 }

int Max3(int a[],int n){
  int thisSum=0,maxSum=0;
  int i=0;
  int start,end,flag;
  int temp[3];
  start =flag = 0;
  end =0;

  if (isNegative(a,n)){
        start =a[0];
        end =a[n-1];

  }else{

        for(i=0;i<n;i++){
        //怎样记录开始的坐标？
            thisSum += a[i];
            if(thisSum>maxSum){
             maxSum = thisSum;
             end = i;
             start = flag;
            }

            if(thisSum<0){
                thisSum=0;
                flag = i+1;
                }
       }
  }



  temp[0]=maxSum;
  temp[1]=start;
  temp[2]= end;
  for(i=0;i<2;i++)
    printf("%d ",temp[i]);
  printf("%d",temp[i]);

  return maxSum;

}

int main()
{
    srand(3);
    int N;
    scanf("%d",&N);
    int a[N],i;
    for(i=0;i<N;i++){
        //scanf("%d",&a[i]);
        a[i]=rand()%100*pow(-1,1);
        if (abs(a[i])<0.1)
        a[i] = a[i] + 10;

    }
        //scanf("%d",&a[i]);



    int s = Max3(a,N);
   // printf("%d\n",s);
     printf("\n");
     for(i=0;i<N;i++)
        //printf("%d ", rand());
        printf("%d ",a[i]);
    return 0;
}
