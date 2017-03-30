#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode PolyNor;

struct Node {
  int Coeff;
  int Exp;
  PtrToNode  Next;
};

PolyNor Read(){
   int N,i;
   //struct Node *L,*pc,*tmp;
   PolyNor L,pc,tmp;
   L = malloc(sizeof(struct Node));
   pc = L;
   scanf("%d",&N);
   for(i=0;i<N;i++){
      tmp = malloc(sizeof(struct Node));
      scanf("%d",&tmp->Coeff);
      scanf("%d",&tmp->Exp);
      pc->Next = tmp;
      pc = tmp;
   }
   pc->Next= NULL;

 return L;

}

void Print(PolyNor L){
   if(L)
      L = L->Next;
   if(!L){
    printf("0 0\n");
    return ;
   }
   while(L->Next){
    printf("%d ",L->Coeff);
    printf("%d ",L->Exp);
    L = L->Next;
   }
    printf("%d ",L->Coeff);
    printf("%d\n",L->Exp);

    return ;
}
int CheckZero(PolyNor L){// check whether List has a Zero

    PolyNor pc,tmp;
    pc = L;
    while(pc->Next){
        if(pc->Next->Coeff==0){
            if(pc->Next->Next){
                    tmp = pc->Next;
                    pc->Next=pc->Next->Next;
                    continue;
            }else{
                tmp =pc->Next;
                pc->Next=NULL;
                break;
            }
            free(tmp);
        }
        pc=pc->Next;
    }
    //return L ;
return 0;
}

PolyNor CreatNode(){
     PolyNor cnode= malloc(sizeof(struct Node));
   return cnode;
 }
PolyNor Add(PolyNor L1,PolyNor L2){//一元多项式相加
   PolyNor p1,p2;
   PolyNor L,pc,tmp;
   L = malloc(sizeof(struct Node));
   pc=L;
   p1 = L1;
   p2 = L2;
   p1 = p1->Next;
   p2 = p2->Next;
   while(p1&&p2){
      if(p1->Exp == p2->Exp){
            tmp = CreatNode();
            tmp->Coeff = p1->Coeff + p2->Coeff;
            tmp->Exp = p1->Exp;
            pc->Next = tmp;
            pc = tmp;
            p1= p1->Next;
            p2 = p2->Next;

      }else if(p1->Exp > p2->Exp){
          tmp = CreatNode();
          tmp->Coeff = p1->Coeff;
          tmp->Exp = p1->Exp;
          pc->Next= tmp;
          pc = tmp;
          p1=p1->Next;

      }else{

          tmp = CreatNode();
          tmp->Coeff = p2->Coeff;
          tmp->Exp = p2->Exp;
          pc->Next= tmp;
          pc = tmp;
          p2=p2->Next;

      }

   }

   while(p1){
          tmp = CreatNode();
          tmp->Coeff = p1->Coeff;
          tmp->Exp = p1->Exp;
          pc->Next= tmp;
          pc = tmp;
          p1=p1->Next;
   }
   while(p2){
          tmp = CreatNode();
          tmp->Coeff = p2->Coeff;
          tmp->Exp = p2->Exp;
          pc->Next= tmp;
          pc = tmp;
          p2=p2->Next;
   }
    pc->Next= NULL;
    CheckZero(L);
    return L;
}


PolyNor Mutiply(PolyNor L1,PolyNor L2){//一元多项式相乘
    PolyNor L,tmp,poly_temp,pc_temp;
    PolyNor p1,p2;
    p1 = L1;
    p2 = L2;
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    //pc = L;
    p1 = p1->Next;
    p2 = p2->Next;
    poly_temp = malloc(sizeof(struct Node));
    pc_temp = poly_temp;//临时表达式指针
    if (!p1 || !p2){

        return L;
    }
    while(p1){

            while(p2){
                tmp = malloc(sizeof(struct Node));
                tmp->Coeff = p1->Coeff * p2->Coeff;
                tmp->Exp  = p1->Exp + p2->Exp;
                pc_temp->Next =tmp;
                pc_temp = tmp;
                p2=p2->Next;
            }
            pc_temp->Next = NULL;
            //printf("checking loop of poly_temp..\n");
            //Print(poly_temp);
            L = Add(L,poly_temp);
           // printf("checking adding in Multiply loop of L.\n");
           // Print(L);
             //这里加起来所有的。
            //L = p;
            pc_temp = poly_temp;
            //printf("after adding , poly_temp\n");
           // Print(poly_temp);
            p1 = p1->Next;
            p2 = L2->Next;// next round
    }


    return L;
}

int main(){
    PolyNor L1,L2;
    PolyNor LA,LM;

   // printf("Hello world!\n");
    L1 = Read();
    // checkzero
    //CheckZero(L1);
    //Print(L1);

    L2 = Read();
    //printf("L1 L2 before adding...\n");
    //Print(L1);
   // Print(L2);
   LA = Add(L1,L2);
   // printf("L1 L2 after adding...\n");
    //Print(L1);
   // Print(L2);
    LM = Mutiply(L1,L2);
   //printf("printing LM\n");
    Print(LM);
   // printf("printing LA\n");
    Print(LA);
    return 0;
}
