#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct node
{
	int data;
	struct node* next;
};

struct Time
{
	int disc;
	int fsh;
};

void addedge(struct node* a[],struct node* gt[],int u,int v){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=a[u];
	a[u]=temp;
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	temp1->data=u;
	temp1->next=gt[v];
	gt[v]=temp1;
}

void DFS_visit(struct node* a[],struct Time tm[],int u,int t,int color[],struct node** topo){
	t=t+1;
	tm[u].disc=t;
	color[u]=1;
	struct node* v=a[u];
	while(v!=NULL){
		if (color[v->data]==0)
		{
			DFS_visit(a,tm,v->data,t,color,topo);
		}
		v=v->next;
	}
	color[u]=-1;
	t++;
	tm[u].fsh=t;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=u;
	temp->next=*topo;
	*topo=temp;
}

void DFS(struct node* a[],struct Time tm[],struct node** topo){
	int color[10];
	for (int i = 0; i <10; ++i)
	{
		color[i]=0;
	}
	int t=0;
	for (int i = 0; i < 10; ++i)
	{
		if (color[i]==0 && a[i]!=NULL)
		{
			DFS_visit(a,tm,i,t,color,topo);	
		}
	}
}
void DFS_visitB(struct node* a[],int u,int color[]){
	color[u]=1;
	printf("%d ",u );
	struct node* v=a[u];
	while(v!=NULL){
		if (color[v->data]==0)
		{
			DFS_visitB(a,v->data,color);
		}
		v=v->next;
	}
	color[u]=-1;
}

void DFSB(struct node* a[],struct node* finish){
	int color[10];
	struct node* curr=finish;
	for (int i = 0; i <10; ++i)
	{
		color[i]=0;
	}
	int s=1;
	while(curr!=NULL){
		if (color[curr->data]==0)
		{
		printf("%d-->",s );
		s++;
		DFS_visitB(a,curr->data,color);
		printf("\n");
		}
		curr=curr->next;	
	}
}

void SSC(struct node* g[],struct node* gt[],struct Time t[]){
	struct node* finish=NULL;
	DFS(g,t,&finish);
	struct node* temp=finish;
	// while(temp!=NULL){
	// 	printf("%d ",temp->data);
	// 	temp=temp->next;}
	DFSB(gt,finish);
}

int main()
{
	struct node* g[10];
	struct node* gt[10];
	struct Time t[10];
	for (int i = 0; i < 10; ++i)
	{
		g[i]=NULL;
		gt[i]=NULL;
	}
	addedge(g,gt,1,0);
	addedge(g,gt,0,2);
	addedge(g,gt,2,1);
	addedge(g,gt,0,3);
	addedge(g,gt,3,4);
	SSC(g,gt,t);
	return 0;
}