 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef int DataType;

/*��������ṹ*/
typedef struct node {
	DataType data;
	struct node* next;
} LNode, * LinkList;

/*

1.�Ӽ�������10����������������ͷ�ĵ�������������ֵ��
2.�Ӽ�������1���������ڵ������в��Ҹý�㡣���ҵ�������ʾ���ҵ��ˡ�����������ʾ���Ҳ�������
3.�Ӽ�������2��������һ����ʾ�������λ��i����һ����ʾ���������ֵx����x�����ڶ�Ӧλ���ϣ�������������н��ֵ���۲���������
4.�Ӽ�������1����������ʾ��ɾ������λ�ã�������������н��ֵ���۲���������
5.�ѵ������ɴ���ͷ����ѭ���������ѭ�����������н��ֵ���۲���������
6.ʵ����ϰ�᣺2.11
7.ʵ����ϰ�᣺2.21
*/
/*β�巨����������*/
LinkList CreateList(int n) {
	LinkList head, s, p;
	head = (LinkList)malloc(sizeof(LNode));

	head->next = NULL;
	p = head;
	cout << "����������" << endl;;
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
//���ص�����ĳ���
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
/*�������ӡ���*/
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
/*���������ָ������ e */
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
/*�Ӽ�������2��������һ����ʾ�������λ��i����һ����ʾ���������ֵe����e�����ڶ�Ӧλ����*/
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
/*�ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��*/
Status  ListDelete(LinkList& L, int i) { // ���ı�L
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

//��ͷ��㵥�������ã�ͷ�巨��
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

//���������Ϊѭ������ 
void ToCircleList(LinkList& L) {
	if (!L) return;
	LinkList p = L->next;
	while (p->next)
	{
		p = p->next;
	}
	p->next = L;


}
//��ѭ��������� 
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
	int x;	//��Ԫ��
	int position;		//����λ�á�ɾ��λ��
	char ch;			//���ڲ˵�
	int i;


	do {
		printf("\n");
		printf(" *******************˳�����Ա��ܲ˵�********************\n");
		printf("  *   a������������             b������Ԫ��              *\n");
		printf("  *   c: ����Ԫ��               d��ɾ��Ԫ��              *\n");
		printf("  *   e: ��Ϊѭ������           f����x�����ʺϵ�λ��     *\n");
		printf("  *   g: �͵�����                                        *\n");
		printf("  *   z���˳�                                            *\n");
		printf("  ********************************************************\n");
		printf("  ���������ѡ��");
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
			printf("  ����Ҫ���ҵ�ֵ��");
			scanf("%d", &x);
			i = LocateElem(L, x);
			if (i)
				printf("�ҵ���\n");
			else
				printf("û�ҵ�\n");
			break;
		case 'c':
			printf("  ������Ҫ���������Ԫ��x��");
			scanf("%d", &x);
			printf("  ������Ҫ�����Ԫ��λ��position��");
			scanf("%d", &position);
			ListInsert(L, position, x);
			PrintList(L);
			break;
		case 'd':
			printf("  ������Ҫɾ��Ԫ�ص�λ��position��");
			scanf("%d", &position);
			ListDelete(L, position);
			PrintList(L);
			break;
		case 'e':
			printf("  ��Ϊѭ�������");

			ToCircleList(L);
			PrintCircleList(L);
			break;
		case 'f':
			printf("  ������Ҫ�����Ԫ��x��");
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
