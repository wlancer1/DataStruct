#include<cstdio>
#define MAX_VEX 20
/*1有向图  2无向图  3有向网  4无向网 
*/ 
//邻接矩阵定义
typedef struct AdjPty{
	int value;//权值 
}AdjMatrix[MAX_VEX][MAX_VEX]; 
struct AdjMap{
	char vex[MAX_VEX];//顶点向量 
	int visited[MAX_VEX]; 
	int ptnum,arcnum;//定点数和弧数
	AdjMatrix arcs;	//定义矩阵 
	int kind;	 
}; 

//邻接表定义 
struct Arcnode{
	int index;
	Arcnode *next;
};
typedef struct VNode{
	char data;
	Arcnode *firstarc;
	int visited; 
	
}AdjList[MAX_VEX];
struct ArcMap{
	AdjList vertices;
	int ptnum,arcnum; 
}; 
#include "adjmap.h"
#include "arcmap.h"
int main(){
	AdjMap map;
	ArcMap map2;
	int count=0,l1,l2,l3;
	char rela[]={'A','C','H','M','N','K','F','D','E','I','J','F','B','A'};
	char rela2[]={'E','H','L'},rela3[]={'J','K','F','G'}; 
	char rela4[][2]={{'A','C'},{'A','B'},{'C','H'},{'B','F'},{'D','F'},
	{'D','E'},{'E','I'},{'E','H'},{'F','J'},{'F','K'},{'F','G'},{'I','J'},{'H','L'},
	{'J','K'},{'I','M'},{'K','N'},{'N','M'},{'M','H'}};
	map.ptnum=14;
	map.kind=2;
	map2.ptnum=14;
	InitArc(map2);
	l1=(sizeof(rela)/sizeof(rela[0]));
	l2=(sizeof(rela2)/sizeof(rela2[0]));
	l3=(sizeof(rela3)/sizeof(rela3[0]));	 
		InitMap(map);
		CreateMap(rela,map,count,l1);
		CreateMap(rela2,map,count,l2);
		CreateMap(rela3,map,count,l3);			
		MapPrint(map);		
		printf("有%d\n",count);
		printf("图的dfs遍历的结果:\t");
		DFSTraverse(map,0);
		CreateArc(map2,18,rela4);
		DFS(map2,0);	
	return 0;
} 
