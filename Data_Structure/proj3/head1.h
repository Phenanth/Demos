#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
typedef struct nodeList* STACKPOINTER;
typedef struct nodeList {
	DATA data;
	STACKPOINTER link;
}STACK;

STACKPOINTER Create(DATA data);
int IsFull(STACKPOINTER stk);
int IsEmpty(STACKPOINTER stk);
STACKPOINTER Push(STACKPOINTER stk, DATA data);
STACK Pop(STACKPOINTER stk);

STACKPOINTER Conversion(DATA data);
void PrintStack(STACKPOINTER stk);
DATA InputData();

#include "stack1.c"
