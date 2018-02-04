#define MAX_TERMS 50
int avail = 0;

char* Create() {
	char* stkp;
	stkp = (char *)malloc(MAX_TERMS * sizeof(char));
	*(stkp + MAX_TERMS) = '\0';
	return stkp;
}

int IsEmpty(char* stkp) {
	if (*stkp == '\0')
		return 1;
	else return 0;
}

int IsFull(char* stkp) {
	char* temp = stkp + MAX_TERMS;
	if (stkp == temp)
		return 1;
	else return 0;
}

void Push(char* stkp, char data) {
	if (IsFull(stkp)) {
		printf("%s\n", "Stack is full!");
		exit(EXIT_FAILURE);
	}
	avail += 1;
	*stkp = data;
}

char Pop(char* stkp) {
	char num = *stkp;
	*stkp = '\0';
	avail -= 1;
	return num;
}

int Matching(char* str) {
	int isMaching = 1;
	char stk[MAX_TERMS];
	char* stkp = stk;
	while (*str != '\0') {
		if (*str == '(') {
			Push(stkp, '(');
		}
		else if (*str == ')') {
			char temp;
			temp = Pop(stkp);
			if (temp != '(') {
				isMaching = 0;
				break;
			}
		}
		str++;
	}
	if (avail != 0) {
		isMaching = 0;
	}
	avail = 0;
	return isMaching;
}
