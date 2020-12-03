#ifndef stack_h
#define stack_h
#include<stdio.h>
#include<stdlib.h>
#define OK 1 
#define ERROR 0
#define STACKINCREMENT 5
#define STACK_INIT_SIZE 10
typedef char SElemType;
typedef int Status;
typedef struct{
	SElemType *base;//栈底指针 
	SElemType *top;//栈顶指针
	int stacksize;//当前已经分配的存储空间 
}SqStack;
char prior[7][7]={{'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'},{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},{'<','<','<','<','<','=','!'},{'>','>','>','>','!','>','>'},
	{'<','<','<','<','<','!','='}};//定义算符之间优先关系的二维数组 

Status InitStack(SqStack *s);
Status Push(SqStack *s,SElemType e);
Status Pop(SqStack *s,SElemType *e);
SElemType GetTop(SqStack *s);
int Index(char c);
char Priority(char a,char b);
int Reckon(int a,char theta,int b);
Status isdigit(char ch);
void GetExpressionValue();



#endif
