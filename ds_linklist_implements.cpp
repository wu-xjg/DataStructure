#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


LinkList headInsert(LinkList &L){
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	cin>>x;
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin>>x;
	}
	return L;
}

LinkList tailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;
	cin>>x;
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin>>x;
	}
	r->next = NULL;
	return L;
}

int main(){
	LinkList L,p;
	p=tailInsert(L);
	while(p->next!=NULL){
		p=p->next;
		cout<<p->data<<" ";
	}
	
	return 0; 
}
