#ifndef list_h
#define list_h
typedef int dataType;
typedef struct node{
	dataType data;
	struct node *next;
}LinkList,node;

LinkList *CreateList();
int size(LinkList *L);
void insert(LinkList *L,int k,dataType x);
void Delete(LinkList *L,int k);
int Empty(LinkList *L);
dataType GetData(LinkList *L,int x);
node *Find(LinkList *L,dataType x);
void Print(LinkList *L);
//实现约瑟夫环
void createlist();
void delete();

#define m 11
#define n 3
#endif 
