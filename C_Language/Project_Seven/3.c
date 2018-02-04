/*
3. 编写程序，输入若干个正整数，输入-1时输入结束，用单向链表组织输入的正整数。
定义和调用函数：structnode *createSortList(); 
建立单向链表，要求链表按照结点中整数值的大小从大到小排序，返回指向链表头结点的指针。 
定义和调用函数：voidprintList(struct node *head); 输出单向链表。

建立工作指针p（上一结点）,q（下一结点）
头尾指针tail,head。
t新建结点的指针。
每次从头将小的往右传，将合适位置的p（下一结点）q（上一结点）链接到t。
####另考虑头和尾的情况
头：改将head指向t，t->next指向p
尾：该将q->next指向t，t->next指向NULL
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	unsigned int num;
	struct node *next;
}NODE,*NODEP;

NODEP createSortList();
void printList(NODEP head);

int main(){
	NODEP head;
	head = createSortList();
	printList(head);
	return 0;
}
NODEP createSortList(){
	NODEP t,head = NULL,p,q;
	unsigned int num;
	scanf("%d",&num);
	while((int)num != -1){
		t = (struct node *)malloc(sizeof(struct node));
		t -> num = num;
		p = head;
		while(p != NULL && num < p->num){
			q = p;
			p = p -> next;
		}
		if(p == head)
			head = t;
		else q -> next = t;
		t -> next = p;
		scanf("%d",&num);
	}
	return head;
}
void printList(NODEP head){
	NODEP p = head,q = head;
	while(p != NULL){
		printf("%-5d",p -> num);
		p = p -> next;
		free(q);
		q = p;
	}
}
/*
 有待修改：
{NODEP p = NULL,q = NULL;
			if(p == NULL)//尾的处理方法
				q -> next = t,t -> next = NULL;
			else if(num >= p -> num)
					if(t->num > head->num)//头
						head = t,t -> next = p;
					else q -> next = t, t -> next = p;
*/
