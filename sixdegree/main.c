#include <stdio.h>
#include <stdlib.h>

//typedef struct VNode *PtrToVnode;
//typedef PtrToVnode AdjList;
typedef struct GNode *PtrToGNode;
typedef PtrToGNode LGraph;
typedef struct AdjVNode *PtrToAdjVnode;
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;

#define MaxVerV 10000
//
//struct VNode{
//    PtrToAdjVnode FirstEdge;
//} ;
struct AdjVNode{
    int AdjV;
    PtrToAdjVnode Next;
};

struct ENode{
   int a;
   int b;
};

struct GNode{
   int Nv;
   int Ne;
    PtrToAdjVnode *A;
};

Edge CreateEdge(){
   Edge E = malloc(sizeof(struct ENode));
   E->a = -1;
   E->b = -1;
   return E;

}

LGraph CreateGraph(int VertexNum){
    int v;

    LGraph Graph =malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    Graph->A = malloc(sizeof(struct PtrToAdjVnode*)*VertexNum);
    for(v=1;v<=Graph->Nv;v++)
        Graph->A[v] = NULL;
    return Graph;

}
void InsertEdge(LGraph G, Edge E){
   PtrToAdjVnode NewNode ;
   NewNode = malloc(sizeof(struct AdjVNode));
   NewNode->AdjV = E->b;
   NewNode->Next=G->A[E->a];
   G->A[E->a] = NewNode;


   NewNode = malloc(sizeof(struct AdjVNode));
   NewNode->AdjV = E->a;
   NewNode->Next = G->A[E->b];
   G->A[E->b] = NewNode;

}

LGraph BuildGraph(){
   int Vnum;
   Edge E;
   int i;
   scanf("%d",&Vnum);
   LGraph G = CreateGraph(Vnum);
   scanf("%d",&G->Ne);
   for(i=0;i<G->Ne;i++){
        E = CreateEdge();
        scanf("%d %d",&E->a,&E->b);
        InsertEdge(G,E);
   }

   return G;

}

struct Queue{
   int Size;
   int Cap;
   int Front;
   int Rear;
   PtrToAdjVnode *Member;

};

typedef struct Queue *PtrToQueue;
typedef PtrToQueue Queue;

Queue CreateQueue(int VNum){

    Queue Q = malloc(sizeof(struct Queue));
    Q->Size =0;
    Q->Cap = VNum;
    Q->Front =0;
    Q->Rear = -1;
    Q->Member = malloc(sizeof(PtrToAdjVnode )*VNum);
    return Q;
}

int isFull(Queue Q){
  return Q->Size ==Q->Cap;
}

int isEmpty(Queue Q){

  return Q->Size ==0;
}

void Enque(Queue Q ,PtrToAdjVnode Adj){

    if(isFull(Q)){
        printf("Queue full\n");

    }else{

     Q->Member[++Q->Rear] = Adj;
     Q->Size++;
    }

}

PtrToAdjVnode DeQue(Queue Q){
  if(isEmpty(Q)){
    printf("Queue is empty!!\n");
    return NULL;
  }else{

      Q->Size--;

      return Q->Member[Q->Front++];

 }

}


int BFS(LGraph G, int i){

    int count=0 ,level =0;
    PtrToAdjVnode pc,tmp,last=NULL;
    Queue Q =CreateQueue(G->Nv);
    Enque(Q,G->A[i]);

    while(!isEmpty(Q)&&level<6){
           count++;
           pc = DeQue(Q);
           printf("%d ",pc->AdjV);

           while(pc){
            pc = pc->Next;
            if(pc)
                Enque(Q,pc);
           }





    }

    return count;

}

void PrintG(LGraph G){

  int i;
  PtrToAdjVnode pc;
  for(i=1;i<=G->Nv;i++){
     pc = G->A[i];
     printf("%d: ",i);
     while(pc!=NULL){ // while 循环中最好不要改变自身，使用pc进行遍历比较好
                      // 如果不用pc指针，直接采用G->[i]进行内容操作，会引起副作用
                      //在这个例子中，打印到最后一个出错

        printf("%d ",pc->AdjV);
        pc=pc->Next;

     }//while
     printf("\n");
     free(pc);
  }

}

int main()
{
   LGraph G = BuildGraph();
   //PrintG(G);
   int i, count=0;
   for (i=1;i<=1;i++){

       count = BFS(G,i);
      printf("%d: %.2f\n",i,count/G->Nv*100.00);

   }

    return 0;
}
