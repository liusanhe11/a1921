#include<stdlib.h>
#include<malloc.h>
#include"lianbiao.h"





//创建链表
LinkList* CreatList(){


	LinkList *head;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	return head;
}


//求链表的元素个数
int size(LinkList *L){
	node *p = L->next;
	int k = 0;
	while(p){
		k++;
		p = p->next;
	}
	return k;
}


//在链表l的第k个位置插入元素x
void insert(LinkList *L,int k,dataType x){
	if(k<1) exit(1);
	node *p = L;
	int i = 0;
	while(p && i<k-1){
		p = p->next;
		i++;
	}
	if(!p) exit(1);
	node *s = (LinkList*)malloc(sizeof(LinkList));
	s->data=x;
	s->next=p->next;
	p->next=s;
}
//删除链表l的第k个元素的值
void Delete(LinkList *L,int k){
	if(k<1) exit(1);
	node *p = L;
	int i = 0;
	while(p->next && i<k-1){
		p = p->next;

		i++;
	}
	if(p->next==NULL) exit(1);
	node *q = p->next;
	p->next = q->next;
	free(q);
}


//判断链表是否为空
int Empty(LinkList *L){
	return L->next == NULL;
}


//求链表l的第k个元素的值
dataType GetData(LinkList *L,int k){
	if (k<1) exit(1);
	node *p = L;
	int i = 0;
	while (p && i<k){
		p = p->next;
		i++;
	}
	if (!p) exit(1);
	return p->data;
}

//在链表l中查找值为x的元素
node* Find(LinkList *L,dataType x){

	node *p = L->next;
	while(p && p->next)
		p = p->next;
	return p;
}

//输出链表
void Print (LinkList *L){
	node *p = L->next;
	node *q;
	while (p){
		printf(" %d  ",p->data);
		p = p->next;

	}
	printf("\n");
}

//清空链表
void ClearList(LinkList *L){
	node *p = L->next;
	node *q;
	while(p){

		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
}
//实现约瑟夫环
void creatlist(){
	node *p, *q, *r;
	p = q = (node*)malloc(sizeof(node));                                             
	p ->data = 1;
	for (int i=2; i<=n; i++){
		r = (node*)malloc(sizeof(node));
		r ->data = i;
		q->next = r;
		q = r;
	}
	q ->next= p;
	q = p;
}

void delete(){
	int k =0;
	node *p, *q, *r;
while (q->next !=q){
		k++;
		if (k == m){
			p->next = q->next;
			free(q);
			q = p->next;
			k = 0;
		}else{
			p = q;
			q = q->next;
		}
	}
printf("最后一个获胜者的编号：%d\n",q->data+1);
}

	 
