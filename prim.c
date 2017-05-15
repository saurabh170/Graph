#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

struct list
{
	int wt;
	int vertex;

};

struct node
{
	int key;
	struct list list;
	struct node* next; 
};

int parent(int i) { return (i-1)/2; }

void top_down_heapify(struct node* a[], int len, int i){
	int l=2*i +1;
	int r=2*i +2,j;
	struct node *t = (struct node *)malloc(sizeof(struct node));
	if(l==len-1 && a[i]->key>a[l]->key){
		t=a[l];
		a[l]=a[i];
		a[i]=t;
		return;
	}
	while(r<len){
		if(a[l]->key<a[r]->key)
			j=l;
		else
			j=r;
		if(a[i]->key<a[j]->key)
			break;
		else{
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
		i=j;
		l=2*i+1;
		r=2*i+1;
		if(l==len-1&&a[i]->key>a[l]->key){
			t=a[l];
			a[l]=a[i];
			a[i]=t;
			break;	
		}
	}
		
}
void build_heap(struct node* a[],int n){
	int i=n/2;
	while(i>=0){
		top_down_heapify(a,n,i);
		i--;
	}
}

struct node* delete_min(struct node *a[],int *n)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp=a[*n-1];
	a[*n-1]=a[0];
	a[0]=temp;
	temp=a[*n-1];
	(*n)--;
	top_down_heapify(a,*n,0);
	return temp;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void decreaseKey(int harr[],int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}


void addedge(struct node* a[],int u,int v,int wt){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->list.vertex=v;
	temp->list.wt=wt;
	temp->list.key=INT_MAX;
	temp->next=a[u];
	a[u]=temp;
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	temp1->list.vertex=u;
	temp1->list.wt=wt;
	temp1->list.key=INT_MAX;
	temp1->next=a[v];
	a[v]=temp1;
}

void prim(struct node* a[],int r){
	int color[10];
	int pi[10]''
	for (int i = 0; i < 10; ++i)
	{
		color[i]=0;
		a[i].key=INT_MAX;
		pi[i]=-1;
	}
	a[r]->key=0;
	pi[r]=0;
	build_heap(a,n);
	
}

int main()
{
	struct node* a[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i]=NULL;
	}
	addedge(a,0,1,2);
	addedge(a,0,3,6);
	addedge(a,1,2,3);
	addedge(a,1,3,8);
	addedge(a,1,4,5);
	addedge(a,2,4,7);
	addedge(a,3,4,9);
	int key[10];
	int pi[10];
	return 0;
}