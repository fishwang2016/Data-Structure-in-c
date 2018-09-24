#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Node *PtrToNode;
//https://pta.patest.cn/pta/test/3512/exam/4/question/80568
struct Node{
  int Data;
  PtrToNode Next;

};

PtrToNode createNode(){
     PtrToNode N ;
     N = malloc(sizeof(struct Node));
     if(!N){

        printf("out of memory!\n");
        return NULL;
     }
     N->Next = NULL;

     return N;

}

void createLine(PtrToNode Nodep[],int node1, int node2){
          PtrToNode newNode = createNode();
          newNode->Data = node2;
          if(Nodep[node1]){

              PtrToNode tmp;
              tmp = Nodep[node1];
              Nodep[node1]=newNode;
              newNode->Next = tmp;

          }else{
              Nodep[node1] =newNode;
          }
}


void PrintAdjList(PtrToNode *a,int TotalNum){
    int i;
    PtrToNode pc;

    for(i=0;i<TotalNum;i++){
        pc= a[i];
        printf("%d:",i);
        while(pc!=NULL){
            printf("%d ",pc->Data);
            pc=pc->Next;
        }
        printf("\n");
    }
}

void BSF(){

}

void DFS(PtrToNode nodep[],int visit[],int v){
     if(visit[v]==-1)
          visit[v]=v;
    for(;nodep[v]!=NULL;){


        if(nodep[v])
          DFS(nodep,visit,nodep[v]->Data);
        nodep[v]=nodep[v]->Next;
    }



}

int main()
{   int i,node1,node2;
    int NumOfV;
    int NumOfL;
    scanf("%d %d",&NumOfV,&NumOfL);
    PtrToNode Nodep[NumOfV];
    int visit[NumOfV];
    for(i=0;i<NumOfV;i++){
         Nodep[i]=NULL;
         visit[i]=-1;
    }

    for(i=0;i<NumOfL;i++){
        scanf("%d %d",&node1 ,&node2);
        if((node1<NumOfV)&&(node2<NumOfV))
           createLine(Nodep,node1,node2);
    }

    PrintAdjList(Nodep,NumOfV);
    DFS(Nodep,visit,0);

    for(i=0;i<NumOfV;i++)
        printf("%d %d\n",i,visit[i]);


    return 0;
}
