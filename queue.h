#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int dataType;
typedef struct node{
		dataType data;
			struct node *left,*right;
}Deque,node;

Deque* createDeque();
void size(Deque *dq);
int empty(Deque *dq);
dataType front(Deque *dq);
dataType back(Deque *dq);
void push_front(Deque *dq,dataType x);
void push_back(Deque *dq,dataType x);
void pop_front(Deque *dq);
void pop_back(Deque *dq);
void clear(Deque *dq);
void print(Deque *dq);

#endif

