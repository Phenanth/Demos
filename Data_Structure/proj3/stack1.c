#define MAX_NODES 50

void PrintStack(STACKPOINTER stk) {
	STACK data = Pop(stk);
	stk = data.link;
	printf("%s", "The corresponding binary version is: ");
	while (data.data != -1) {
		printf("%d", data);
		data = Pop(stk);
		stk = data.link;
	}
	printf("\n");
}

DATA InputData() {
	int data;
	//printf("%s", "Please input the decimal number: ");
	scanf("%d", &data);
	return data;
}

STACKPOINTER Create(DATA data) {
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

STACKPOINTER Push(STACKPOINTER stk, DATA data) {
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

STACKPOINTER Conversion(DATA data) {
	STACKPOINTER stk = Create(-1);
	while (data != 0) {
		DATA num = data % 2;
		if (!IsFull(stk)) {
			stk = Push(stk, num);
		}
		data /= 2;
	}
	return stk;
}
