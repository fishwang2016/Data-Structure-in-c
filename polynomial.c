#include<stdio.h>

typedef struct Polynomial *PtrL;
typedef struct Polynomial *List;
struct Polynomial{
	int coef;
	int exp;
	PtrL Next;
	
};

List createNode(){
	List L;
	L = (List)malloc(sizeof(struct Polynomial));
	L->Next=NULL;
	return L;
	
}

int isEmpty(List L){
	
	if(L->Next==NULL) return 1;
	return 0;
}

void AddElement(List L, int coef,int exp){
	List p,tmp;
	p=L;
	tmp=createNode();
	tmp->coef = coef;
	tmp->exp = exp;
	while(p->Next)
	    p=p->Next;
    p->Next = tmp;

	
}

List add(List L1, List L2){//¿ÉÒÔfree(L2)? 
      //printf("Into add...\n");
     if (isEmpty(L1)) return L2;
	 if (isEmpty(L2)) return L1;
	 List L,p1,p2,p;
	 //L=createNode();
	 int i=0;
	 p1 = L1->Next;
	 p2 = L2->Next; 
	 p=L;

	 
	 while(p1&&p2){
	 //	printf("Into while ...\n");
 		if (p1->exp > p2->exp){
 		   p->Next=p1;
 		   p1=p1->Next;
		 }
       
        else if(p1->exp == p2->exp){
            p1->coef = p1->coef + p2->coef;
            p->Next =p1;
            p1=p1->Next;
            p2=p2->Next;
	 }
	    else {
   	      p->Next = p2;
		  p2=p2->Next;  
	
   	   }
   	   p=p->Next;
   	   
   //	printf("No.: %d cycle.\n",i++);   
 	}
 	if(p1){
	 	p->Next=p1;
	 }
	 if(p2){
 		p->Next=p2;
 	}
 
 	return L;
}

printN(List L){
		
      List p=L->Next;
		
      while(p){
	  printf("%d %d ", p->coef,p->exp);
	  p=p->Next;
	}
	 printf("\n");
}

Read(int a[],int n, List L ){
	// read data from array in the main function.
	int i;
		
   for(i=1;i<n;i=i+2){
    AddElement(L,a[i],a[i+1]);
	}
}

List ReadInput(){
	// Read inputs from the screen
	List temp;
	temp=createNode();
	int i,d1,d2,number;
	scanf("%d,",&number);
	for(i=0;i<number;i++){
		scanf("%d %d,",&d1,&d2);
		AddElement( temp,  d1,d2);
	}
    //printN(temp);
    return temp;
}

int main(){
	int a1[9]={4, 3 ,4, -5, 2 , 6, 1,  -2, 0};
	int a2[7] ={3 ,5 ,20,  -7, 4 , 3, 1	};
	List L1,L2,L3;
	L1=ReadInput();
	
    L2=ReadInput();
    printN(L1);
    printN(L2);
/*
	L1 = createNode();
	Read(a1,9,L1);

	L2 = createNode();
	Read(a2,7,L2);

    printN(L1);
    printN(L2);
	*/
	L3 = add(L1,L2);

    printN(L3);
 
	
	
	
}

