#include "stdio.h"
#include <stdlib.h>
#include "string.h"

struct Edge{
	int source;
	int wt;
	int dst;
};

struct Graph
{
	int V;
	int E;
	struct Edge* edge;
};

struct prtrnk{
	int parent;
	int rank;
};

struct Graph* makeGraph(int V,int E){
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;
	graph->E=E;
	graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
	return graph;
}

int find(struct prtrnk prtrnks[], int E){
	if (prtrnks[E].parent!=E)
	{
		prtrnks[E].parent=find(prtrnks,prtrnks[E].parent);
	}
	return prtrnks[E].parent;
}

void Union(struct prtrnk prtrnk[],int x,int y){
	int xRoot=find(prtrnk,x);
	int yRoot=find(prtrnk,y);
	if (prtrnk[xRoot].rank>prtrnk[yRoot].rank)
	{
		prtrnk[yRoot].parent=xRoot;	
	}
	else if (prtrnk[xRoot].rank<prtrnk[yRoot].rank)
	{
		prtrnk[xRoot].parent=yRoot;	
	}
	else{
		prtrnk[xRoot].parent=yRoot;
		prtrnk[yRoot].rank++;
	}
}

void kruskal_MST(struct Graph* graph){
	int V=graph->V;
	struct Edge rst[V];
	for (int i = 0; i < graph->E; i++)
	{
		for(int j=i+1;j<graph->E;j++){
			if (graph->edge[i].wt>graph->edge[j].wt)
			{
				struct Edge temp=graph->edge[i];
				graph->edge[i]=graph->edge[j];
				graph->edge[j]=temp;
			}
		}
	}
	struct prtrnk *prtrnks=(struct prtrnk*)malloc(V*sizeof(struct prtrnk));
	for (int i = 0; i < V; ++i)
	{
		prtrnks[i].parent=i;
		prtrnks[i].rank=0;
	}
	int e=0,i=0;
	while(e<V-1){
		struct Edge new=graph->edge[i];
		int x=find(prtrnks,new.source);
		int y=find(prtrnks,new.dst);
		if (x!=y)
		{
			rst[e]=new;
			Union(prtrnks,x,y);
			e++;
		}
		i++;
	}
	for (int i = 0; i < e; ++i)
	{
		printf("source->%d destination->%d wt->%d\n",rst[i].source,rst[i].dst,rst[i].wt );
	}
}

int main()
{

	int V = 4;  
    int E = 5;  
    struct Graph* graph = makeGraph(V, E);
 
    graph->edge[0].source = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].wt = 10;
 
    graph->edge[1].source = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].wt = 6;
 
    graph->edge[2].source = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].wt = 5;
    
    graph->edge[3].source = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].wt = 15;
 
    graph->edge[4].source = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].wt = 4;
 
    kruskal_MST(graph);

	return 0;
}
