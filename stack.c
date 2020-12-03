#include"stack.h"

//构造一个存放char型数据的空栈 
Status InitStack(SqStack *s){
	s->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!s->base) return ERROR;
	s->top = s->base;//栈中元素个数为0
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//入栈
Status Push(SqStack *s,SElemType e){
	if(s->top-s->base>=s->stacksize){
		s->base = (SElemType *)realloc(s->base,(STACKINCREMENT+s->stacksize)*sizeof(SElemType));
		if(!s->base) exit(0);
		s->top = s->base+s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return OK;
}
//出栈
Status Pop(SqStack *s,SElemType *e){
	if(s->base==s->top){
		printf("空栈！\n");
		return ERROR;
	}
	*e = *--s->top;
	return OK;
}
//得到栈顶元素
SElemType GetTop(SqStack *s){
	return *(s->top-1);
} 
//确定输入的字符如果是操作符的话判断在二维数组中的下标 若是数字的话就另外与操作符区分开 便于在输入表达式时是入哪个栈 
int Index(char c){
	switch(c){
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		case ')': return 5;
		case '#': return 6;
		default:  return 7;
	}
}
//判断优先级,返回大小 < > = !
char Priority(char a,char b){
	int x,y;
	x = Index(a); y = Index(b);
	if(x!=7&&y!=7)
		return prior[x][y];
	else
		return '!';
}
//简单表达式求值
int Reckon(int a,char theta,int b){
	switch(theta){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}
//判断是字符是否是数字
int isdigit(int ch){
	if(ch>='0'&&ch<='9') return OK;
	else return ERROR;
} 
//算术表达式求值
void GetExpressionValue(){
	SqStack OPTR,OPND; 
	SElemType result;//返回最后结果 
	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR,'#');//将结束符置于操作符的底端  
	printf("请输入算术表达式:\n");
	char c = getchar();

	while(c!='#'||GetTop(&OPTR)!='#'){//当*c=='#'&&栈顶字符=='#'的时候
		if(isdigit(c)){//如果是数字的话将其转化为数字 然后入操作数栈 
			int data[10];
			int i,num;
			i = num =0;//num是一个中间数 用于将字符串中的数字转化为整数然后入栈 i是用于将字符串中的字符存入data数组 
			while(isdigit(c)){
				data[i] = c-'0';
				i++;
				c = getchar();
			}
			for(int j=0;j<i;j++){
				num = num*10+data[j];
			}
			Push(&OPND,num);
		}else{//如果是字符的话将其入操作符栈
			SElemType a,b,theta;//a b theta是用来返回操作数栈和操作符栈里的元素的
			switch(Priority(GetTop(&OPTR),c)){//比较即将入栈的字符与栈顶 操作符的优先级关系 
				case '<':Push(&OPTR,c); 
					 c = getchar();
					 break;
				case '>':Pop(&OPND,&b);
					 Pop(&OPND,&a);
					 Pop(&OPTR,&theta);
					 Push(&OPND,Reckon(a,theta,b));
					 break;//将结果入栈 
				case '=':Pop(&OPTR,&theta);
					 c = getchar();
					 break;//说明括号相遇 删除栈内括号即可 
				default:break;
			}
		}
	}
	Pop(&OPND,&result);
	printf("结果是：%d",result);
}

