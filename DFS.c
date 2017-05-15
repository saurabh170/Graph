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

void addedge(struct node* a[],int u,int v){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=a[u];
	a[u]=temp;
	// struct node* temp1=(struct node*)malloc(sizeof(struct node));
	// temp1->data=u;
	// temp1->next=a[v];
	// a[v]=temp1;
}

void DFS_visit(struct node* a[],struct Time tm[],int u,int t,int color[]){
	t=t+1;
	tm[u].disc=t;
	color[u]=1;
	printf("%d \n",u );
	struct node* v=a[u];
	while(v!=NULL){
		if (color[v->data]==0)
		{
			DFS_visit(a,tm,v->data,t,color);
		}
		v=v->next;
	}
	color[u]=-1;
	t++;
	tm[u].fsh=t;
}

void DFS(struct node* a[],struct Time tm[]){
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
			DFS_visit(a,tm,i,t,color);	
		}
	}
}

int main()
{
	struct node* a[10];
	struct Time t[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i]=NULL;
	}
	addedge(a,0,1);
	addedge(a,0,2);
	addedge(a,1,2);
	addedge(a,2,0);
	addedge(a,2,3);
	addedge(a,3,3);
	DFS(a,t);
	return 0;
}