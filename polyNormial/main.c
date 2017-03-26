#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef struct PtrToNode PolyNor;

struct Node {
  int Coeff;
  int Exp;
  PtrToNode * Next;
};


int main()
{
    printf("Hello world!\n");
    L1 = Read();
    L2 = Read();
    LM = Mutiply(L1,L2);
    LA = Add(L1,L2);

    Print(LM);
    Print(LA);

    return 0;
}
