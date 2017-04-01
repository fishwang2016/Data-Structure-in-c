//
//  main.c
//  isSameBST
//
//  Created by Fish on 2017/3/31.
//  Copyright © 2017年 Fish. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
typedef struct Node Node;

#define True 1;
#define False 0;

struct Node{

    int Data;
    struct Node *Left,*Right;
};

PtrToNode MakeNode(int x){
    PtrToNode ANode =malloc(sizeof(Node));
    ANode->Left = NULL;
    ANode->Right = NULL;
    ANode->Data = x;
    return ANode;

}

PtrToNode Insert(int x,PtrToNode T){

    if(T==NULL){
            T = malloc(sizeof(struct Node));
            T->Data = x;
            T->Left = NULL;
            T->Right = NULL;

    }else if(x<T->Data)
        T->Left=Insert(x,T->Left);
    else if (x>T->Data)
        T->Right=Insert(x, T->Right);

    return T;


}

void Print(PtrToNode T,PtrToNode head){

    if (T){//后序打印

           Print(T->Left,head);

            Print(T->Right,head);
            if(T==head){
                 printf("%d\n",T->Data);
            }else{
                 printf("%d ",T->Data);
            }

    }

}

int Compare(PtrToNode T1,PtrToNode T2){
     if (T1==NULL && T2==NULL)
        return True;
     if (T1==NULL && T2)
        return False;
     if(T2==NULL && T1)
        return False;
     if (T1->Data==T2->Data)
        return Compare(T1->Left,T2->Left)&& Compare(T1->Right,T2->Right);
     else
        return False;

}

int main(int argc, const char * argv[]) {

    // N:每个序列插入元素的个数
    // L:需要检查的序列个数

    int N,L;
    int i,j;
    int x;

    scanf("%d",&N);
    //printf("ok!\n");


    PtrToNode T[N*N];
    int flag=0;
    int Check[N*N];
//    T[0]=NULL;
//    for(i=0;i<N;i++){
//        scanf("%d",&x);
//        T[0]=Insert(x,T[0]);
//    }
//    Print(T[0]);

    while(N!=0){

        scanf("%d",&L);
        for(i=0;i<L+1;i++){
            T[i] = NULL;

            for(j=0;j<N;j++){
                scanf("%d",&x);
                T[i]=Insert(x,T[i]);//建立每一棵树

            }
        }
        if(L>=1){
                for(i=1;i<=L;i++){
                    Check[flag++]=Compare(T[0],T[i]);//记录不同的比较结果
                }
                    //Print(T[i],T[i]);
                //Compare(T[0],T[i])
        }else{
          printf("No list to compare.\n");
        }
        scanf("%d",&N);
    }
    for(i=0;i<flag;i++){//一次性打印结果

        if(Check[i]==0)
            printf("No\n");
        else if(Check[i]==1)
            printf("Yes\n");
    }

    return 0;
}
