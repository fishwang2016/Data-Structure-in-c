#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct Node PtrToNode;

 struct Node{
   int Data;
   struct Node *Left,*Right;
};

void Swap(int *a, int *b){
   int tmp =*a;
   *a = *b;
   *b = tmp;
}

void Sort(int a[],int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(a[i]>a[j]){
                Swap(&a[i],&a[j]);
            }
        }
    }

}

void PrintA(int a[],int N){
    int i;
    printf("Sorted Array:\n");
    for(i=0;i<N-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}
PtrToNode BuildTree(int *a,int N){
    PtrToNode root;

    int depth = floor(log2(N))+1;
    int k = pow(2,depth)/2 - (N - pow(2,depth-1)+1);





   return root;
}

void Test(){

  double n;
  printf("log %d = %f \n",2,pow(2,3));
}

int main()
{
  Test();
//    int N,i;
//    scanf("%d",&N);
//    int a[N];
//    for(i=0;i<N;i++)
//        scanf("%d",&a[i]);
//    Sort(a,N);
//    PrintA(a,N);

    return 0;
}
