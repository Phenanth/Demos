#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Create();
int IsEmpty(char* stkp);
int IsFull(char* stkp);
void Push(char* stkp, char data);
char Pop(char* stkp);

int Matching(char* str);

#include "stack2.c"