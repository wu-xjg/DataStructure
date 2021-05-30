#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define InitSize 10
typedef int ElemType;
typedef struct{
	ElemType *data;
	int MaxSize;
	int length;
}SqList;

bool initList(SqList &L){
	L.data = (ElemType *)malloc(InitSize*sizeof(ElemType));
	if(!L.data) 
		return false;
	L.length = 0;
	L.MaxSize = InitSize*2;
	return true;	
}

bool listInsert(SqList &L,int i,ElemType e){
	if(i<1 || i>L.length+1)
		return false;
	if(L.length >= L.MaxSize)
		return false;
	for(int j=L.length; j>=i; j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	return true;	
}

bool listDelete(SqList &L,int i,ElemType &e){
	if(i<1 || i>L.length)
		return false; 
	e = L.data[i-1];
	for(int j=i; j<L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;	 
}

int LocateElem(SqList L,ElemType e){
	int i;
	for(i=0; i<L.length; i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
}

void print(SqList &L){
	for(int i=0; i<L.length; i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}
int main(){
	SqList L;
	initList(L);
	for(int i=0; i<5; i++)
		L.data[i] = 2*i+1;
	L.length = 5;
	print(L);
	int i,e;
	cin >> i >> e;
	listInsert(L,i,e);
	print(L);
//	int loc = LocateElem(L,e);
//	cout<<loc;
//	listDelete(L,i,e);
//	print(L);
return 0; 
}
