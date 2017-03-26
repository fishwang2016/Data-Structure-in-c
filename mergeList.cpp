#include<stdio.h>
#include<malloc.h>
typedef struct Node *PtrToNode;
typedef struct Node *List;
	
struct Node{
		int Data;
		PtrToNode Next;
	};
List makeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}
void insert(int x, List L){
	List s = (List)malloc(sizeof(struct Node));
	List p;
	p =L;
	while(p->Next)
	   p=p->Next;
	s->Data=x;
	s->Next=NULL;
	p->Next = s;

   return ;

}

List Merge(List L1,List L2){
 
	List p1,p2,p,L;
	p1 = L1->Next;
	p2 = L2->Next;
	p=L =L1;
	
	
	while(p1&&p2){
		if(p1->Data < p2->Data){
			p->Next = p1;
			p1 = p1->Next;
			
		}else{
		    p->Next = p2;
			p2 = p2->Next;	
		}
		p = p->Next;
	}
	p->Next=p1?p1:p2;
	free(p2);
	return L;	
}
void Print(List L){
	List p=L;
	while (p){
		printf("%d ",p->Data);
		p =p->Next;
	}
	printf("\n");
}

int main(){
	
	int a1[9]={50,52,55,60,70,80,89,90,100};
	int a2[6]={50,60,70,80,90,100};
	List L1 = makeEmpty(),p;
	List L2 = makeEmpty();
	int i;
	
	for(i=0;i<9;i++){
		insert(a1[i],L1);
	}
	for(i=0;i<6;i++){
		insert(a2[i],L2);
	}
	Print(L1->Next);
	
	Print(L2->Next);

	List L3=Merge(L1,L2);

	Print(L3->Next);
  return 0;
}
