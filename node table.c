#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct node
{
	Elemtype data;
	struct node* next;
}Node;

Node* initList();

int main()
{
	Node *head = initList();
	addList (head, 1);
	addList (head, 3);
	addList (head, 4);
	addList (head, 2);
	addList (head, 7);
	printf("删去%d",deleList(head,3));
	checkList(head, 4);
	checkList(head, 3);
	printf("%d",putList(head));
	return 0;
}

Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}//初始化链表

int putList(Node* head)
{
	int i = 0;
	for(; ; i ++)
	{
		if(head->next == NULL)
		{
			break;
		}
		else
		{
			Node *currentnode = head->next;
			printf("%d ",head->next->data);
			head->next = head->next->next;
			free(currentnode);
		}
	}
	return i;
 } 

void addList(Node* head, Elemtype a)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = a;
	newnode->next = head->next;
	head->next = newnode;
 }//头加法添加元素 
 
Elemtype deleList(Node* head, int pos)
{
	int i = 0;
	Node *currentnode = head;
	for(; i < pos; i ++)
	{
		if(currentnode->next == NULL)
		{
			printf("不存在要删除元素");
			break;
		}
		currentnode = currentnode->next;
	}
	if(currentnode->next == NULL)
	{
		printf("不存在要删除元素");
	}
	else
	{
		Node *nextnode = currentnode->next;
		currentnode->next = currentnode->next->next;
		return nextnode->data;
		free(nextnode);
    }
}//删除元素 

void checkList(Node* head, Elemtype a)
{
	int i = 1;
	Node *currentnode = head->next;
	int check_if_a_exist = 0;
	for(;currentnode != NULL;i ++)
	{
		if(currentnode->data == a)
		{
			printf("第%d个 ",i);
			check_if_a_exist = 1;
		}
		currentnode = currentnode->next;
	}
	if (!check_if_a_exist)
	{
		printf("不存在所查找元素");
	}
 } //查找元素 
