#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef int DATA;
typedef struct nodeList* STACKPOINTER;
typedef struct nodeList {
	int data;
	STACKPOINTER link;
}STACK;

STACKPOINTER Create(int data);
int IsFull(STACKPOINTER stk);
int IsEmpty(STACKPOINTER stk);
STACKPOINTER Push(STACKPOINTER stk, int data);
STACK Pop(STACKPOINTER stk);

STACKPOINTER Conversion(char data[]);
void PrintStack(STACKPOINTER stk);
void InputData(char data[]);

void PrintStack(STACKPOINTER stk) {
	STACK datas = Pop(stk);
	stk = datas.link;
	//printf("%d%s", num,"--->");
	while (datas.data != -1) {
		printf("%d", datas.data);
		datas = Pop(stk);
		stk = datas.link;
	}
	printf("\n");
}

void InputData(char data[]) {
	//printf("%s", "Please input the decimal number: ");
	scanf("%s", data);
}

STACKPOINTER Create(int data) {
	STACKPOINTER temp;
	temp = (STACK *)malloc(sizeof(STACK));
	temp->link = NULL;
	if (data)
		temp->data = data;
	else temp->data = 0;
	return temp;
}

int IsFull(STACKPOINTER stk) {
	int Nfull = 0;
	if (!(stk)) {
		return 0;
	} else {
		int i;
		for (i = 0; i < MAX_NODES; i++) {
			if (stk->link == NULL) {
				Nfull++;
				break;
			}
			stk = stk->link;
		}
		if (Nfull) {
			return 0;
		}
		else return 1;
	}
	return 0;
}

int IsEmpty(STACKPOINTER stk) {
	if ((!stk)) {
		return 1;
	}
	else return 0;
}

STACKPOINTER Push(STACKPOINTER stk, int data) {
	if (!IsEmpty(stk)) {
		STACKPOINTER temp = Create(-1);
		temp->link = stk;
		temp->data = data;
		stk = temp;
	}
	else {
		if (stk->data == -1)
			stk->data = data;
		else stk = Create(data);
	}
	return stk;
}

STACK Pop(STACKPOINTER stk) {
	STACK temp;
	temp.link = NULL;
	temp.data = -1;
	if (!IsEmpty(stk)) {
		temp.data = stk->data;
		temp.link = stk->link;
		STACKPOINTER tmp = stk;
		free(tmp);
	}
	return temp;
}

STACKPOINTER Conversion(char data[]) {
	STACKPOINTER stk = Create(-1);
	char *p = data;
	int temp = 0;
	while (*p != '\0') {
		temp += temp * 10 + *p - '0';
		int num = temp % 2;
		if (!IsFull(stk)) {
			stk = Push(stk, num);
		}
		p++;
	}
	return stk;
}

int main() {
	char num[MAX_NODES];
	InputData(num);
	while ( 1 ) {
		STACKPOINTER result = Conversion(num);
		PrintStack(result);
		InputData(num);
	}
	return 0;
}
