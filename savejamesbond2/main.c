/*
*��Ҫ˼���Ǹ���һ��״̬��
*ʹ��Dijkstra�㷨��
*�ѿ�ͷ�ͽ�β�������һ���㣻
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MaxV 102
#define True 1
#define False 0
#define Inff 99999
#define ERROR -1;

typedef struct Node *PtrToNode;
typedef PtrToNode PNode;

typedef struct MGraph *PtrToGraph;
typedef PtrToGraph PGraph;

struct Node{
  int x;
  int y;
  int KNOW;
  int Pv;
  int Dv;
};

struct MGraph{
  int Nv;
  int Jump;
  double M[MaxV][MaxV];
  PNode Nodes[MaxV];
};


PGraph BuildGraph(int Nv){
    PNode n;
    int i,j;
    PGraph g = malloc(sizeof(struct MGraph));
    g->Nv = Nv;
    scanf("%d",&g->Jump);
    for(i=2;i<Nv+2;i++){
        n = malloc(sizeof(struct Node));
        scanf("%d %d",&n->x,&n->y);
        n->KNOW = False;  // ��ʼ���ڵ㣻
        n->Pv =-1;// -1  ��ʾ����֪���ĸ��㵽�
        n->Dv = Inff;
        g->Nodes[i] = n;
    }
    // M[0] �ǵ��ϵĵ㣻M[1]�Ǳߣ�

    //�ҳ����������ĵ㣻
    for(i=2;i<Nv+2;i++){

        int  distance = sqrt(g->Nodes[i]->x*g->Nodes[i]->x + g->Nodes[i]->y* g->Nodes[i]->y);

        if( (distance >7.5) && (distance < (7.5+g->Jump)))
        { g->M[0][i]=distance-15;
        g->M[i][0]=distance-15;
        }


        else
        {  g->M[0][i] = Inff;
          g->M[i][0] = Inff;
        }


    }

    //���㵽�ߵľ���

    for(i=2;i<Nv+2;i++){
            int d1 = (abs(g->Nodes[i]->x-50) <  abs(g->Nodes[i]->y-50)) ?  abs(g->Nodes[i]->x-50): abs(g->Nodes[i]->y-50);//�жϵ����Ͻ�
            int d2 = (abs(g->Nodes[i]->x-50) <  abs(g->Nodes[i]->y-50)) ?  abs(g->Nodes[i]->x-50): abs(g->Nodes[i]->y+50);//�жϵ����½�
            int d3 = (abs(g->Nodes[i]->x+50) <  abs(g->Nodes[i]->y-50)) ?  abs(g->Nodes[i]->x+50): abs(g->Nodes[i]->y-50);//�жϵ����Ͻ�
            int d4 = (abs(g->Nodes[i]->x+50) <  abs(g->Nodes[i]->y+50)) ?  abs(g->Nodes[i]->x+50): abs(g->Nodes[i]->y+50);//�жϵ����½�

            if(d1<=g->Jump||d2<=g->Jump||d3<=g->Jump||d4<=g->Jump){
                    g->M[1][i]=1;
                     g->M[i][1]=1;
            }else{
                   g->M[1][i]=Inff;
                   g->M[i][1]=Inff;

            }

    }

    //����ÿ����֮��ľ��룻

    for(i=2;i<Nv+2;i++)
       for(j=2;j<Nv+2;j++){
          double distance = sqrt(pow(g->Nodes[j]->x -g->Nodes[i]->x,2) + pow(g->Nodes[j]->y - g->Nodes[i]->y,2));
          if(distance <= g->Jump&& i!=j){
                  g->M[i][j] = 1;
                  g->M[j][i] = 1;


             }else{

             g->M[i][j]= Inff;
                 }

       }
     // ��ʼ��ͽ�������inff
     if(g->Jump>(50-15)){
        g->M[0][1]=1;
        g->M[1][0]=1;
     }else{
        g->M[0][1]=Inff;
        g->M[1][0] = Inff;
     }



    return g;
}

void PringG(PGraph g){
  int i,j;
  for(i=0;i<g->Nv+2;i++){
       for(j=0;j<g->Nv+2;j++)
         printf("%f ",g->M[i][j]);
       printf("\n");
  }
}

int FindMin(PGraph g, int collected[],int dist[]){
     int i ;
     int MinDist = Inff;
     int MinV ;
     for(i=0;i<g->Nv+2;i++){
        if(collected[i]!=True&&dist[i]<MinDist){
             MinDist = dist[i];
             MinV = i;
        }
     }
     if(MinDist<Inff)
        return MinV;
     else
        return Inff;

}

int Dijkstra(PGraph g, int start,int pv[]){
    int collected[MaxV];
    int dist[MaxV];
    int i,min;
    for(i=0;i<g->Nv+2;i++){
           collected[i] = -1;
           dist[i] = g->M[start][i];
           if(dist[i]<Inff)
              pv[i]=start;
           else
               pv[i]=-1;
    }

    collected[start]= True;
    pv[start]=-1;
    dist[start] =0;

    while (1){


        min = FindMin(g,collected,dist);//�ҳ�Ŀǰλ�õ��Ѿ���¼�Ķ������С����
        if (min == Inff)
            break;
        collected[min] = True;
        for(i=0;i<g->Nv+2;i++){

                if(collected[i]!=True&&g->M[min][i]<Inff&&i!=min){
                    if (g->M[min][i]<0)
                        return False;
                    if(dist[min]+g->M[min][i]<dist[i]){
                         dist[i]=dist[min]+g->M[min][i];
                         pv[i]=min;
                    }
                }//if

        }//for

    }//while


  return True;
}

void PrintPath(int pv[],int i ){

    if (pv[i]!= -1)
        PrintPath(pv, pv[i]);
    printf("%d ",i);


}

int main()
{   int Nv;
    int n=0,i;
    int pv[MaxV];
    int path[MaxV];
    scanf("%d",&Nv);
    PGraph g = BuildGraph(Nv);
    //PringG(g);
    int status = Dijkstra(g,0,pv);
   // PrintPath(pv,1);
    //ת��pv

    if (status == False||pv[1]==-1){
         printf("%d",0);
    }else{
        i = pv[1];
        while (i!=-1){
           path[++n]=i;
           i = pv[path[n]];
        }

        printf("%d\n",n);
        for(i=n-1;i>0;i--){
            printf("%d %d\n",g->Nodes[path[i]]->x,g->Nodes[path[i]]->y);
        }

    }//else





    return 0;
}
