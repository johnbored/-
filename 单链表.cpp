 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef int DataType;

/*单链表结点结构*/
typedef struct node {
	DataType data;
	struct node* next;
} LNode, * LinkList;

/*

1.从键盘输入10个整数，产生带表头的单链表，并输入结点值。
2.从键盘输入1个整数，在单链表中查找该结点。若找到，则显示“找到了”；否则，则显示“找不到”。
3.从键盘输入2个整数，一个表示欲插入的位置i，另一个表示欲插入的数值x，将x插入在对应位置上，输出单链表所有结点值，观察输出结果。
4.从键盘输入1个整数，表示欲删除结点的位置，输出单链表所有结点值，观察输出结果。
5.把单链表变成带表头结点的循环链表，输出循环单链表所有结点值，观察输出结果。
6.实现练习册：2.11
7.实现练习册：2.21
*/
/*尾插法建立单链表*/
LinkList CreateList(int n) {
	LinkList head, s, p;
	head = (LinkList)malloc(sizeof(LNode));

	head->next = NULL;
	p = head;
	cout << "请输入数据" << endl;;
	for (int i = 0; i < n; i++)
	{

		s = (LinkList)malloc(sizeof(LNode));
		s->next = NULL;
		//scanf("%d", &s->data);
		cin >> s->data;
		p->next=s;
		p = s;
	}
	return head;

}
//返回单链表的长度
int length(LinkList L)
{
	if(!L)
	return ERROR;
	int l=0;
	LinkList p=L->next;
	while(p&&p!=L)
	{
		p=p->next;
		l++;
	}
	return l;
 } 
/*单链表打印输出*/
Status PrintList(LinkList L) {
	if (!L) return ERROR;
	LinkList p = L->next;
	while (p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	return OK;
}
/*单链表查找指定数据 e */
int LocateElem(LinkList L, DataType e) {
	if (!L) return 0;
	LinkList p = L->next;
	int  f = 0;
	while (p)
	{
		if (p->data == e)
		{
			f = 1;
			break;
		}
		p=p->next;
	}

	return f;

}
/*从键盘输入2个整数，一个表示欲插入的位置i，另一个表示欲插入的数值e，将e插入在对应位置上*/
Status ListInsert(LinkList& L, int i, int e) {
	if (!L || i < 1) return 0;
	int l = 1;
	LinkList p = L;
	while (p->next)
	{
		if (l == i)
			break;
		p = p->next;
		l++;
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->next=NULL;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/*在带头结点的单链线性表L中，删除第i个元素*/
Status  ListDelete(LinkList& L, int i) { // 不改变L
	if (!L || i < 1) return 0;
	LinkList p = L, s;
	int l = 1;
	while (p->next)
	{
		if (l == i)
			break;
		p = p->next;
		l++;
	}
	if (l < i)
		return 0;
	else{
	LinkList s = p->next;
	p->next = p->next->next;
	free(s);
	return OK;
}
}

//带头结点单链表逆置（头插法）
Status Reverse(LinkList& L) {
	LinkList head, p, s;
	head = L;
	int l=length(head);
	p=head->next;
	s=p;
	if (!head) return ERROR;
	DataType *arr=(DataType*)malloc(length(L)*sizeof(DataType));
	for(int i=0;i<l;i++)
	{
		arr[i]=p->data;
		p=p->next;
	}
	for(int i=l-1;i>=0;i--)
	{
		s->data=arr[i];
		s=s->next;
	}
	
	return OK;
}

//将单链表改为循环链表 
void ToCircleList(LinkList& L) {
	if (!L) return;
	LinkList p = L->next;
	while (p->next)
	{
		p = p->next;
	}
	p->next = L;


}
//将循环链表输出 
Status PrintCircleList(LinkList L) {
	if (!L)return 0;
	LinkList p=L->next;
	while (p!= L){
		cout << p->data << " ";
		p=p->next;
}

	return OK;
}
void OrderedListInsert(LinkList L,int x)
{
	LinkList p=L->next;
	while(p->next)
	{
		if(p->data<=x&&p->next->data>x)
		break;
		p=p->next;
	}
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=x;
	s->next=NULL;
	s->next=p->next;
	p->next=s;
}
int main() {
	LinkList L, L1, L2, L3;
	int x;	//新元素
	int position;		//插入位置、删除位置
	char ch;			//用于菜单
	int i;


	do {
		printf("\n");
		printf(" *******************顺序线性表功能菜单********************\n");
		printf("  *   a：创建单链表             b：查找元素              *\n");
		printf("  *   c: 插入元素               d：删除元素              *\n");
		printf("  *   e: 改为循环链表           f：将x插入适合的位置     *\n");
		printf("  *   g: 就地逆置                                        *\n");
		printf("  *   z：退出                                            *\n");
		printf("  ********************************************************\n");
		printf("  请输入你的选择：");
		//scanf("%c", &ch);
		//getchar();
		cin>>ch;
		//ch = getch();
		switch (ch) {
		case 'a':
			L = CreateList(10);
			PrintList(L);
			break;
		case 'b':
			printf("  输入要查找的值：");
			scanf("%d", &x);
			i = LocateElem(L, x);
			if (i)
				printf("找到了\n");
			else
				printf("没找到\n");
			break;
		case 'c':
			printf("  请输入要插入的数据元素x：");
			scanf("%d", &x);
			printf("  请输入要插入的元素位置position：");
			scanf("%d", &position);
			ListInsert(L, position, x);
			PrintList(L);
			break;
		case 'd':
			printf("  请输入要删除元素的位置position：");
			scanf("%d", &position);
			ListDelete(L, position);
			PrintList(L);
			break;
		case 'e':
			printf("  改为循环链表后：");

			ToCircleList(L);
			PrintCircleList(L);
			break;
		case 'f':
			printf("  请输入要插入的元素x：");
			scanf("%d", &x);
			OrderedListInsert(L, x);
			PrintList(L);
			break;
		case 'g':
			Reverse(L);
			PrintList(L);
			break;
		default:
			break;
		}
	} while (ch != 'z');
	return 0;
}
