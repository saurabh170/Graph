#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

struct node* newNode1(int data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;	
	return newnode;
}	

void enqueue(int x)
{
	struct node *temp;
	temp=newNode1(x);
	if (rear==NULL)
		front=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}	
}

int dequeue()
{
	struct node *temp;
	temp=front;
	if (front==NULL)
	{
		printf("Queue is empty\n");
		front=rear=NULL;
	}
	else
	{
		front=front->next;
		return temp->data;
	}
}

void addedge(struct node* a[],int u,int v){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=a[u];
	a[u]=temp;
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	temp1->data=u;
	temp1->next=a[v];
	a[v]=temp1;
}
struct QNode
{
    int key;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};
 
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp; 
}
 
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
void enQueue(struct Queue *q, int k)
{
    struct QNode *temp = newNode(k);
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode *deQueue(struct Queue *q)
{
    if (q->front == NULL)
       return NULL;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

int isempty(struct Queue *q){
	if (q->front==NULL)
	{
		return 1;
	}
	return 0;
} 

void BFS(struct node* a[],int s){
	int color[10];
	//0 for unvisited;
	//1 for visited;
	//-1 for deleted from queue
	for (int i = 0; i <10; ++i)
	{
		color[i]=0;
	}
	color[s]=1;
	struct Queue *q=createQueue();
	enQueue(q,s);
	while(!(isempty(q))){
		struct QNode* u=deQueue(q);
		printf("%d ",u->key);
		struct node* ttt;
		ttt=a[u->key];
		while(ttt!=NULL){
			if (color[ttt->data]==0)
			{
				enQueue(q,ttt->data);
				color[ttt->data]=1;
			}
			ttt=ttt->next;
		}
		color[u->key]=-1;
	}
}

int main()
{
	struct node* a[10];
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
	BFS(a,2);
	//struct node* temp2=(struct node*)malloc(sizeof(struct node));
	// temp2=a[0];
	// while(temp2!=NULL){
	// 	printf("%d ",temp2->data);
	// 	temp2=temp2->next;
	// }
	// puts("");

	return 0;
}