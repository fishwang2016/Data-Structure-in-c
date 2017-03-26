#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    printf("printing L\n");
    Print(L);
    printf("printing L1 and L2\n");
    Print(L1);
    Print(L2);
    return 0;
}
List Merge( List L1, List L2 ){
   List L,pc,p1,p2;
   L = malloc(sizeof(struct Node));//ʹ��L1 ��ͷ�ڵ���Ϊ�µ�ͷ�ڵ㣻
   pc = L;
   p1 = L1;
   p2 = L2;
   p1=p1->Next;
   p2 =p2->Next;
   while(p1 && p2){

     if(p1->Data < p2->Data){
            pc->Next =p1;
            pc = p1;
            p1=p1->Next;
     }else{
           pc->Next =p2;
           pc = p2;
           p2=p2->Next;
     }
   }
   while(p1){
    pc->Next =p1;
    pc = p1;
    p1=p1->Next;
   }
  // L1->Next =NULL;
   while(p2){
    pc->Next =p2;
    pc = p2;
    p2=p2->Next;
   }
   //L2->Next= NULL;
  //pc->Next = L1?L1:L2;
 // free(L1);
  //free(L2);
  L1->Next = NULL;//���ϵ���ĿҪ���L1��L2����ΪNULL
  L2->Next = NULL;
   return L;
}


List Read(){//���ش�ͷ��������
    List L,tmp,p;
    p=malloc(sizeof(struct Node));
    L=p;
    int n ,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
       tmp = malloc(sizeof(struct Node));
       if (tmp==NULL){
        printf("No space available!");
        return NULL;
        }else{
           scanf("%d",&tmp->Data);
           tmp->Next=NULL;
        }
        p->Next=tmp;
        p= p->Next;
    }
    return L;



}

void Print( List L ){
    List P;
    P = L->Next;
    if (P==NULL)
        printf("NULL");
    else{

        while(P!=NULL){
            printf("%d ",P->Data);
            P=P->Next;
        }

    }
    printf("\n");

}
