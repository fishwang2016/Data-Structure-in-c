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
      Position tmp =(Position) malloc(sizeof(struct Node));
        tmp->Data = x;
        tmp->Next = NULL;

        return tmp;
}

void Change(Position L){
// it doesn't change the original content of the L at all in Main function.
    Position tmp = L;
    if (tmp)
        tmp=tmp->Next;

    tmp->Data =1000;

}

int main()
{
    Ptr_Node L,tmp,p;
    p = (Position)malloc(sizeof(struct Node));
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
