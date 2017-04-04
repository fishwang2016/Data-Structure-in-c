#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ) {/* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
    if(BT){
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);

    }
}
void InorderTraversal( BinTree BT ){
    if(BT){

        InorderTraversal(BT->Left);
        printf("%d ",BT->Data);
        InorderTraversal(BT->Right);
    }


}  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert( BinTree BST, ElementType X ){

    if(BST == NULL){
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST ->Right = NULL;

    } else if (X < BST->Data)
        BST->Left= Insert(BST->Left,X);
     else if (X > BST->Data)
        BST->Right = Insert(BST->Right,X);


    return BST;

}

Position Find( BinTree BST, ElementType X ){
    if(BST == NULL)
        return NULL;
    else if(X<BST->Data)
        return  Find(BST->Left,X);
    else if (X > BST->Data)
         return Find(BST->Right,X);
    return BST;

}



Position FindMin( BinTree BST ){
    if (BST==NULL)
        return NULL;
    if(BST->Left==NULL)
        return BST;
    else
        return FindMin(BST->Left);

}
Position FindMax( BinTree BST ){
    if(BST==NULL)
        return NULL;
    if( BST->Right == NULL)
        return BST;
    else
        return FindMax(BST->Right);

}
BinTree Delete( BinTree BST, ElementType X ){

  BinTree tmp;
  if(BST==NULL) {
        printf("Not Found\n");
        return NULL;
  }

  if(X < BST->Data)
     BST->Left = Delete(BST->Left,X);
  else if(X > BST->Data)
     BST->Right = Delete(BST->Right,X);

  else{ //ע��������

      if(BST->Left && BST->Right){
        tmp = FindMin(BST->Right);
        BST->Data = tmp->Data;
        BST->Right = Delete(BST->Right,BST->Data);
        //free(tmp);
     }else{
      tmp = BST;
      if(BST->Left==NULL&&BST->Right==NULL)
        BST=NULL;
      else if(BST->Right)
        BST = BST->Right;
      else if(BST->Left)
        BST = BST->Left;
      free(tmp);

       }
  }

  return BST;
}

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
