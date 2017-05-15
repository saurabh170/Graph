#include <stdio.h>
#include <stdlib.h>

struct list_node 		//linked list
{
	int data;
	struct list_node* next;
};

struct node       		//element of array
{
	int value;
	char colour;		//red = not visited, blue = visited, yellow = in the data structure
	struct list_node* list;
	struct list_node* current;
	struct list_node* start;
	int parent;
	int d;
	int f;
};

void print_list(struct list_node* start)
{
	struct list_node* temp=malloc(sizeof(struct list_node));
	temp=start;
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
	start=temp;
	printf("\n");
}

void print_graph(int n, struct node* graph[])
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d : ",graph[i]->value);
		print_list(graph[i]->start);
	}
}

void insert(int u, int v, int n, struct node* graph[])  //edge from u to v
{
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		if (graph[i]->value==u)
		{
			graph[i]->list = (struct list_node*)malloc(sizeof(struct list_node));
			graph[i]->list->data=v;
			if (graph[i]->current==NULL)
			{
				graph[i]->current=graph[i]->list;
				graph[i]->current->next=NULL;
				graph[i]->start=graph[i]->current;
			}
			else
			{
				graph[i]->list->next=graph[i]->current;
				graph[i]->current=graph[i]->list;
				graph[i]->start=graph[i]->list;
			}
			flag=1;
		}
	}
	if (flag==0)
	{
		printf("Node doesn't exist.\n");
	}
}

struct stack_node
{
	struct node *node;
	struct stack_node *nxtptr;
}*top=NULL,*present=NULL;

void dfs(int n, struct node *graph[], int u)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		if (graph[i]->value==u && graph[i]->colour=='r')
		{
			flag=1;
			newnode=graph[i];
			printf("%d\n",graph[i]->value);
			graph[i]->colour = 'y';
		}
	}
	if (flag==0)
	{
		printf("No node found\n");
	}
	while(newnode->start !=NULL )
	{
		int temp;
		temp = newnode->start->data;
		for (int i = 0; i < n; ++i)
		{
			if (graph[i]->value==temp && graph[i]->colour=='r')
			{	
				dfs(n,graph,temp);
				break;	
			}	 
		}	
		newnode->start=newnode->start->next;
	}
	newnode->colour = 'b';
}

int main()
{
	int n=6;					//no.of vertices
	struct node* graph[n];
	for (int i = 0; i < n; ++i)
	{
		graph[i]=(struct node*)malloc(sizeof(struct node));
		graph[i]->start=graph[i]->current=NULL;
		graph[i]->colour='r';
	}
	graph[0]->value=41;
	graph[1]->value=30;
	graph[2]->value=10;
	graph[3]->value=2;
	graph[4]->value=5;
	graph[5]->value=61;
	insert(41,30,n,graph);
	insert(2,30,n,graph);
	insert(30,10,n,graph);
	insert(10,41,n,graph);
	insert(5,10,n,graph);
	insert(5,61,n,graph);
	insert(61,2,n,graph);
	insert(30,5,n,graph);
	/*for (int i = 0; i < n; ++i)  Check if all nodes are coloured red
	{
		printf("%d : %c\n",graph[i]->value, graph[i]->colour);
	}*/
	dfs(n,graph,41);
	/*for (int i = 0; i < n; ++i)  Check if all nodes are coloured blue
	{
		printf("%d : %c\n",graph[i]->value, graph[i]->colour);
	}*/
	return 0;
}

