#include <stdio.h>
#include <stdlib.h>

typedef struct Edge *PtrToEdge;
typedef PtrToEdge PEdge;

typedef struct MGraph *PtrToGraph;
typedef PtrToGraph PGraph;

#define MaxCity 500
#define False -1
#define True 1
#define Inff 99999

struct Edge{
  int length;
  int cost;
};

struct MGraph{
   int Nv;
   int Ne;
   int Start;
   int Destination;
   PEdge M[MaxCity][MaxCity];
 };


 PGraph Build_Graph(int Nv){
   int i,j;
   int a,b;

   PEdge edge;
   PGraph g = malloc(sizeof(struct MGraph));
   g->Nv =Nv;
   scanf("%d %d %d",&g->Ne,&g->Start,&g->Destination);
   for(i=0;i<500;i++)
      for(j=0;j<500;j++){
           g->M[i][j]= NULL;
      }


    for(i=0;i<g->Ne;i++){
        edge = malloc(sizeof(struct Edge));

        scanf("%d %d %d %d",&a,&b,&edge->length,&edge->cost);
        g->M[a][b]= edge;
        g->M[b][a]= edge;
    }

    return g;
 }
int FindMin(PGraph g, int dist[],int cost[],int collected[]){
    // 主要思想是寻找距离已经收藏的集合最短的边，并返回这个边连着的点v；
    int min = Inff;
    int v;
    int i,j;
    for(i=0;i<g->Nv;i++)
        if(collected[i])
           for(j=0;j<g->Nv;j++)
                if(j!=i&&collected[j]!=True&&g->M[i][j]){
                    if(g->M[i][j]->length + dist[i]< min){
                        min = g->M[i][j]->length+dist[i];
                        v = j;

                    }else if(g->M[i][j]->length + dist[i] == min){
                        if(g->M[i][j]->cost + cost[i]> cost[j])
                           v = j;


                    }//else if;
                 }// if;

    return v;


}
void Dijkstra(PGraph g){

    int start = g->Start;
    int collected[g->Nv];

    for(i=0;i<g->Nv;i++){
        collected[i]= False;
        if(g->M[start][i]!=NULL){
            dist[i]=g->M[start][i]->length;
            cost[i]=g->M[start][i]->cost;
        }else{
            dist[i]=Inff;
            cost[i]=Inff;
        }
    }

    collected[start] = True;

    while(True){

            min = FindMin(g,dist,cost,collected);
            if(min = False)
                break;
            collected[min] = True;
            for(i=0;i<g->Nv;i++){
                if(collected[i]!=True && g->M[min][i]!= NULL){
                        if(dist[min]+g->M[min][i]<dist[i]){
                                dist[i] = dist[min]+g->M[min][i]->length;
                                cost[i] = cost[min]+g->M[min][i]->cost;

                        }else if(dist[min]+g->M[min][i]->length==dist[i]){
                            if( cost[min]+g->M[min][i]->cost<cost[i])
                                cost[i] = cost[min]+g->M[min][i]->cost;
                        }
                }
            }// for

    }//while

    printf("%d %d\n",dist[1],cost[1]);


}

int main(){
    int Nv;
    scanf("%d",&Nv);
    PGraph g = Build_Graph(Nv);
    Dijkstra(g);
    return 0;
}
