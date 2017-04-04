#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// N, number of inserting elements
// M , numbers of paths to be printed.
typedef struct HeapStruct *PtrToHeap;
typedef struct HeapStruct HeapStruct;

struct HeapStruct{
   int Size;
   int Cap;
   int *Members;

};

PtrToHeap InitHeap(int cap){

   PtrToHeap H;
   H = malloc(sizeof(struct HeapStruct));
   H->Size = 0;
   H->Cap = cap;
   H->Members = malloc(sizeof(int)*(cap+1));
   return H;
}

int HeapPercolateUp(PtrToHeap H,int x,int i){
   int tmp;

   if(i>0){
        if (i==1)
             return H->Members[1];
        else {
           if(x>H->Members[i/2]){
              tmp = H->Members[i];
              H->Members[i] = x;
             }
            else if(x < H->Members[i/2]){
                tmp =   H->Members[i];
                H->Members[i]=HeapPercolateUp(H,x,i/2);
                if(i==2)
               H->Members[i/2]= x;
         }
        return tmp;
   }}
    return -1;
}

void HeapInsert(PtrToHeap H, int x){
    if(H){
            if(H->Size < H->Cap){
                if(H->Size==0)
                    H->Members[++H->Size]=x;
                else
                    HeapPercolateUp(H,x,++H->Size);
               }

            else
                printf("Heap full...\n");

    }else{

      printf("Heap is NULL and needs initialization.");

    }

}
void PrintHeap(PtrToHeap H){
   int i;
  if(H){

    for(i=1;i<=H->Size;i++)
        printf("%d ",H->Members[i]);
    printf("\n");
  }
}
void PrintPath(PtrToHeap H,int i){
    if(i>=1 && i<H->Size){

        while (i!=1){

        printf("%d ",H->Members[i]);
        i = i/2;
        }
        printf("%d\n",H->Members[i]);

    }



}

void Test(){

    int N,M;
    int i,x,node;
    PtrToHeap H;
    printf("Print input the max number and path numbers.\n");
    scanf("%d %d",&N, &M);
    H = InitHeap(N);
    for(i=0;i<N;i++){
          x = rand()%100*pow(-1,rand()%10);
          HeapInsert(H,x);
    }
    PrintHeap(H);

    for(i=0;i<M;i++){
            scanf("%d",&node);
            PrintPath(H,node);
    }


}

int main()
{
    int N,M;
    int i,x,node;
    PtrToHeap H;
    scanf("%d %d",&N, &M);
    H = InitHeap(N);
    for(i=0;i<N;i++){
          scanf("%d",&x);
          HeapInsert(H,x);
    }
    //PrintHeap(H);

    for(i=0;i<M;i++){
            scanf("%d",&node);
            PrintPath(H,node);
    }
   //Test();


    return 0;
}
