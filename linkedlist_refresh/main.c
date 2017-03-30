#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Ptr_Node;
typedef Ptr_Node Position;

struct Node {
  int Data;
  struct Node *Next;
};

void Print(struct Node  *L){
   L=L->Next;
   if (L==NULL)
       printf("NULL");
   else{

      while(L){
        printf("%d ",L->Data);
        L=L->Next;
      }
   }

}

Position Create_Node(int x){
      Position tmp = malloc(sizeof(struct Node));
        tmp->Data = x;
        tmp->Next = NULL;

        return tmp;
}

void Change(Position L){
//**  this function can change the content of L but could't revise the L to NULL ...
    Position tmp;
    tmp = L;
    if (tmp)
        tmp=tmp->Next;

    tmp->Data =1000;
   // L->Next= NULL;// adding this line can change the L to NULL .
   /*
    while(L){
        L->Data = 3;
        L=L->Next;// after this, L is not set to NULL;
    }
   */
   while(tmp){

      tmp->Data =3;
      tmp = tmp->Next;
   }
   L->Next = NULL;
}

int main()
{
    Ptr_Node L,tmp,p;
    p = malloc(sizeof(struct Node));
    L = p;

    int a[]={1,4,6,8,9};
    int N= 5,i;
    for(i=0;i<N;i++){
            tmp = Create_Node(a[i]);
            p->Next = tmp;
            p = tmp;
    }

    Print(L);
    printf("\nafter change!!\n");
    Change(L);
    Print(L);

    return 0;
}
