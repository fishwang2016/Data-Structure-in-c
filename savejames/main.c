#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//https://pta.patest.cn/pta/test/3512/exam/4/question/80569

typedef struct Crocodile *PtrToCro;
typedef  PtrToCro CNode;

typedef struct GNode *PtrToGnode;
typedef PtrToGnode MGraph;

#define TRUE 1
#define FALSE 0
#define MaxV 100

struct GNode{

   int Nv;
   int startPoints[MaxV];
   int startNum; //可以选择开跳位置个数；
   int M[MaxV][MaxV];
   CNode NArray[MaxV];
   int visit[MaxV];
};

struct Crocodile{
    int x,y;
    int Bank ;//靠岸？
 };

CNode createCro(int x, int y,int D){

   CNode N = malloc(sizeof(struct Crocodile));
   N->x = x;
   N->y = y;

   if (abs(x-50)<=D ||abs(y-50)<=D|| abs(x+50)<=0 || abs(y+50)<=0)
      N->Bank = TRUE;
   else
      N->Bank = FALSE;
   return N;
}


int isAnEdge(CNode a, CNode b,int D){

    if (sqrt((a->x-b->x)*(a->x-b->x) +(a->y-b->y)*(a->y-b->y))<= D)
        return TRUE;
    return FALSE;

}

void insertEdge(MGraph G, int i, int j){
    G->M[i][j]=1;
    G->M[j][i]=1;

}
int isStartPoints(CNode a,int D){
   int tmp = (D+15)*(D+15) - (a->x*a->x +a->y*a->y );
   if(tmp >=0)
    return TRUE;
   return FALSE;
}

MGraph buildGraph(){
    int D;
    int i,j,x,y;
    int starts=0;


    MGraph G = malloc(sizeof(struct GNode));
    scanf("%d %d",&G->Nv,&D);
    for(i=0;i<G->Nv;i++){
         G->startPoints[i]=-1;// 初始化可以开跳的位置
         G->visit[i] = -1;
         for(j=0;j<G->Nv;j++)
           G->M[i][j]=0;// initialize Graph

    }
     G->startNum =0;
    for(i=0;i<G->Nv;i++){
        scanf("%d %d",&x,&y);
        G->NArray[i] = createCro(x,y,D);
        if(isStartPoints(G->NArray[i],D)==TRUE){
            G->startPoints[starts++]=i;
            G->startNum++;
        }

        for(j=0;j<i;j++){
                if(isAnEdge(G->NArray[j],G->NArray[i],D)==TRUE&&G->M[i][j]!=1)
                     insertEdge(G,i,j);
                  }
    }
    return G;
}

void PrintG(MGraph G){

   int i,j;
   for(i=0;i<G->Nv;i++){
      for(j=0;j<G->Nv;j++)
        printf("%d ",G->M[i][j]);
      printf("\n");
   }


}

int BFS(MGraph G,int N){
  int i;
  G->visit[N]= N;
  printf("%d ",N);
  if(G->NArray[N]->Bank ==TRUE)
     return 1;
  else
     for(i =0;i<G->Nv;i++)
        if(G->M[N][i]==1&&G->visit[i]==-1)
            BFS(G,i);

  return 0;

}

int main()
{   int i,flag;
    int j;
    MGraph G = buildGraph();
    if(G->startNum ==0)
        printf("No\n");
    else{
        for(i=0;i<G->startNum;i++){
                flag = BFS(G,i);

                if(flag==1){
                    printf("Yes\n");
                    break;
                  }
                for(j=0;j<G->Nv;j++)
                    G->visit[j]=-1;
        }
        if(flag ==0)
            printf("No\n");

    }
    return 0;
}
