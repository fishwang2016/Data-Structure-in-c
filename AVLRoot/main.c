#include <stdio.h>
#include <stdlib.h>
// https://pta.patest.cn/pta/test/3512/exam/4/question/73454
typedef struct Node *Position;
typedef struct Node PNode;

struct Node{
  int Data;
  int Height;
  struct Node *Left,*Right;

};

int Max (int a, int b){

  return (a>b)?a:b;
}
int Height(Position T1){
    if (T1==NULL)
        return -1;
    return T1->Height;
}
int UpdateHeight(Position T){

   if (T==NULL)
      return -1;
   return Max(UpdateHeight(T->Left),UpdateHeight(T->Right))+1;
}

Position SingleRotationLL(Position T){
   Position root;
   root = T->Left;
   T->Left = root->Right;
   root->Right = T;
   root->Height = UpdateHeight(root);
   T->Height = UpdateHeight(T);
   //root->Height = Max(Height(root->Left),Height(root->Right))+1;
   return root;
}
Position SingleRotationRR(Position T){
    Position root;
    root = T->Right;
    T->Right = root->Left;
    root->Left = T;
    root->Height = UpdateHeight(root);
    T->Height = UpdateHeight(T);

    return root;

}

Position DoubleRotationLR(Position T){
    T->Left = SingleRotationRR(T->Left);
    Position root = SingleRotationLL(T);
    root->Height = UpdateHeight(root);

    return root;


}

Position DoubleRotationRL(Position T){
    T->Right = SingleRotationLL(T->Right);
    Position root = SingleRotationRR(T);
    root->Height = UpdateHeight(root);

    return root;

}



Position Insert(Position T, int x){
    if(T==NULL){

            T = malloc(sizeof(struct Node));
            T->Data =x;
            T->Left = NULL;
            T->Right = NULL;
            T->Height =0;

    }else if(x<T->Data){
          T->Left = Insert(T->Left,x);
          if(Height(T->Left)-Height(T->Right)==2){
              if(Height(T->Left->Left)> Height(T->Left->Right))//²åÈë×ó×ÓÊ÷µÄ×ó±ß
                    T = SingleRotationLL(T);
              else
               //²åÈë×ó×ÓÊ÷ÓÒ±ß
                    T= DoubleRotationLR(T);
           }
    }


     else if( x > T->Data){
             T->Right = Insert(T->Right,x);
          if(Height(T->Left)-Height(T->Right)==-2){//²åÈëÓÒ×ÓÊ÷µÄ×ó±ß
              if (Height(T->Right->Left)>Height(T->Right->Right))
                   T = DoubleRotationRL(T);
              else //²åÈëÓÒ×ÓÊ÷ÓÒ±ß
              T = SingleRotationRR(T);
          }

     }
     T->Height = Max(Height(T->Left),Height(T->Right))+1;
     return T;

}
void PrintTree(Position T){

   if(T){
       printf("%d ",T->Data);
      PrintTree(T->Left);

      PrintTree(T->Right);

   }
}

int main()
{

    Position T=NULL;
    int N;
    int i;
    int x;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&x);
        T=Insert(T,x);
    }
    PrintTree(T);
    //printf("%d\n",T->Data);
    return 0;
}
