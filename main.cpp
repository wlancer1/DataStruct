#include<cstdio>

using namespace std;
typedef char ElemType; 
struct LinkQue{
	ElemType data;
	LinkQue *next;
	LinkQue *end;
}; 
struct ShareStack{
	ElemType *base1;
	ElemType *top1;
	ElemType *base2;
	ElemType *top2;
	int Maxsize;
};//共享栈提供两个top两个base分别代表两端。
#include "ShareStack.h"
#include "LinkQue.h" 
int main(){
	struct ShareStack st;
	struct LinkQue *sl;
	int i=0,flag=1;
	char z[]="ABC",e;
//	sl=new LinkQue();//初始化头节点 
	link_init(sl);
	share_init(st,10);
	while(z[i]!='\0'){
		switch(z[i]){
			case 'A':
				share_push(st,z[i],2);
			break;
			case 'B':
				share_push(st,z[i],1);
			break;
			case 'C':
				link_push(sl,z[i]);
			break;
			default:
				break;
		}
		i++;
	}
	while(1){
		if(flag>2)
			break;
		 e=share_pop(st,flag);
		if(e=='#')
			flag++;
		else
			link_push(sl,e);
	}	
	while(1){
		e=link_pop(sl);
		if(e=='#')
				break;
		else
		printf("%c",e);
	}
	
	
	return 0; 
}
