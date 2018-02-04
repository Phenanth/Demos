/*
nodePointer create() {
	nodePointer root, child, tmp, temp1, temp2;
	root = (nodePointer)malloc(sizeof(nodeTree));
	temp1 = (nodePointer)malloc(sizeof(nodeTree));
	temp2 = (nodePointer)malloc(sizeof(nodeTree));
	root->data = 'A', root->left = temp1, root->right = temp2;
	child = temp1, child->data = 'B';
	temp1 = (nodePointer)malloc(sizeof(nodeTree));
	child->left = temp1, child->right = NULL;
	child = temp1, child->data = 'D';
	temp1 = (nodePointer)malloc(sizeof(nodeTree));
	child->right = temp1, child->left = NULL;
	child = temp1, child->left = NULL, child->right = NULL, child->data = 'G';

	child = temp2, child->data = 'C';
	temp2 = (nodePointer)malloc(sizeof(nodeTree));
	tmp = (nodePointer)malloc(sizeof(nodeTree));
	child->left = temp2, child->right = tmp;
	child = child->left, child->data = 'E', child->left = NULL, child->right = NULL;
	child = tmp, child->data = 'F';
	temp2 = (nodePointer)malloc(sizeof(nodeTree));
	child->left = temp2, child->right = NULL, child = child->left, child->data='H';
	child->left = NULL, child->right = NULL;
	return root;
}	
*/

/*#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int data;
	struct node *next;
}NODE;
// int avail = 0;

NODE *Init(int data);
void PrintEach(NODE *p);
NODE *DeleteEach(NODE *p);

int main() {
	NODE *p = NULL;
	p = Init(0);
	PrintEach(p);
	p = DeleteEach(p);
	PrintEach(p);
	return 0;
}

NODE *Init(int data) {
	NODE *temp, *head = NULL;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->data = data, temp->next = NULL;
	head = temp;
	int *avail = &(temp->data);
	for (*avail = 0; *avail < MAX; (*avail)++) {
		NODE *tmp = NULL;
		tmp = (NODE *)malloc(sizeof(NODE));
		tmp->data = *avail, tmp->next = NULL;
		temp->next = tmp, temp = temp->next;

	}
	return head;
}

void PrintEach(NODE *p) {
	NODE *temp;
	int count, *avail = &(p->data);
	if (p) {
		printf("%s\n", "The complete linked list is:");
		for (count = 0, temp = p->next; count < *avail; count++) {
			printf("%4d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	else {
		printf("%s\n", "The linked list is empty!");
	}
}

NODE *DeleteEach(NODE *p) {
	NODE *temp = NULL, *tmp = NULL;
	for (tmp = p->next, temp = p->next; temp!=NULL; ) {
		tmp = tmp->next;
		free(temp);
		temp = tmp;
	}
	p = NULL;
	return p;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer create2() {
	listPointer first, second;
	first = (listPointer)malloc(sizeof(listNode));
	second = (listPointer)malloc(sizeof(listNode));
	second->link = NULL;
	second->data = 20;
	first->data = 10;
	first->link = second;
	return first;
}

listPointer search2(listPointer list, int num) {
	// 在一个两结点链表list中寻找数字num。
	listPointer temp = NULL;
	if (list->data == num) {
		temp = list;
	} else {
		if (list->link->data == num) {
			temp = list->link;
		}
	}
	return temp;
}

int main() {
	listPointer list = NULL, result = NULL;
	int num;
	list = create2();
	printf("%s\n", "Input the number you want to search.");
	scanf("%d", &num);
	result = search2(list, num);
	if (result) {
		printf("%s\n", "Found the number in the list.");
	} else {
		printf("%s\n", "Number is not int the list.");
	}
	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int data;
	struct node *link;
}Node;

void insertFront(Node **last, Node *nodep) {
	if (!(*last)) {
		*last = nodep;
		nodep->link = nodep;
	} else {
		nodep->link = (*last)->link;
		(*last)->link = nodep;
	}
}

int length(Node *last) {
	Node *temp;
	int count = 0;
	if (last) {
		temp = last;
		do {
			count++;
			temp = temp->link;
		} while (temp != last);
	}
	return count;
}

Node *init(int len) {
	Node *rear = NULL;
	rear = (Node *)malloc(sizeof(Node));
	rear->data = len-1, rear->link = rear;
	int i;
	for (i = 0; i < len-1; i++) {
		Node *temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->data = i, temp->link = NULL;
		insertFront(&rear, temp);
	}
	return rear;
}

Node *search(Node *last, int num) {
	Node *temp = NULL, *p = last->link;
	if (last->data == num) {
		temp = last;
	} 
	while (p != last) {
		if (p->data == num) {
			temp = p;
			break;
		}
		p = p->link;
	}
	return temp;
}


int main() {
	Node *last, *result;
	last = init(MAX);
	int num;
	scanf("%d", &num);
	result = search(last, num);
	if (result) {
		printf("%s\n", "Found the number.");
		printf("%s%3d\n", "Number is:", result->data);
	} else {
		printf("%s\n", "Number not in the list.");
	}
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct list{
	int data;
	struct list *link;
}List;
typedef List *ListPointer;

ListPointer CreateList();
void insert(ListPointer x, int num);
int delete(ListPointer tail, ListPointer x);

void print(ListPointer first);

int main() {
	ListPointer list, node, temp;
	int num;

	list = CreateList();
	print(list);

	for (temp = list; temp->link != NULL; temp = temp->link) {};
	insert(temp, 10);
	printf("%s\n", "After the insert:");
	print(list);
	num = delete(list, list->link);
	printf("%s\n", "After the Delete:");
	print(list);
	printf("%s%3d\n", "The number deleted is:", num);
	return 0;
}

ListPointer CreateList() {
	ListPointer first, temp;
	int i;
	temp = (ListPointer)malloc(sizeof(List));
	temp->data = -1, temp->link = NULL;
	first = temp;
	for(i = 0; i < MAX; i++) {
		ListPointer tmp;
		tmp = (ListPointer)malloc(sizeof(List));
		tmp->data = i, tmp->link = NULL;
		temp->link = tmp, temp = temp->link;
	}
	return first;
}

void insert(ListPointer x, int num) {
	ListPointer temp;
	temp = (ListPointer)malloc(sizeof(List));
	temp->data = num;
	temp->link = x->link;
	x->link = temp;
}

int delete(ListPointer tail, ListPointer x) {
	int num = x->data;
	tail->link = x->link;
	free(x);
	return num;
}

void print(ListPointer first) {
	ListPointer temp = first->link;
	printf("%s\n", "The linked list with head node is:");
	do {
		printf("%4d", temp->data);
		temp = temp->link;
	} while (temp != NULL);
	printf("\n");
}