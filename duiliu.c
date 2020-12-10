#include"queue.h"

Deque* createDeque(){
	Deque *head;
	head=(Deque*)malloc(sizeof(Deque));
	head->left=head->right=head;
	return head;
}

void size(Deque *dq){
	node *p=dq->right;
	int k=0;
	while (p!=dq){
		k++;
		p=p->right;
	}
	printf("该队列的元素个数为:%d \n",k);
}

int empty(Deque *dq){
	return dq->right==dq;
}

dataType front(Deque *dq){
	if(empty(dq)) exit(1);
	return dq->right->data;
}

dataType back(Deque *dq){
	if (empty(dq)) exit(1);
	return dq->left->data;
}

void push_front(Deque *dq,dataType x){
	node *s=(node*)malloc(sizeof(node));
	s->data=x;
	s->left=dq;
	s->right=dq->right;
	dq->right->left=s;
	dq->right=s;
}

void push_back(Deque *dq,dataType x){
	node *s=(node*)malloc(sizeof(node));
	s->data=x;
	s->left=dq->left;
	s->right=dq;
	dq->left->right=s;
	dq->left=s;
}

void pop_front(Deque *dq){
	if(empty(dq)) exit(1);
	node *p=dq->right;
	p->right->left=dq;
	dq->right=p->right;
	free(p);
}

void pop_back(Deque *dq){
	if(empty(dq)) exit(1);
	node *p=dq->left;
	p->left->right=dq;
	dq->left=p->left;
	free(p);
}

void clear(Deque *dq){
	node *q,*p;
	p=dq->right;
	while(p!=dq){
		q=p;
		p=p->right;
		free(p);
	}
	dq->left=dq->right=dq;
}

void print(Deque *dq){
	node *p=dq->right;
	printf("该队列的元素为;");
	while(p!=dq){
		printf("%d ",p->data);
		p=p->right;
	}
	printf("\n");
}

