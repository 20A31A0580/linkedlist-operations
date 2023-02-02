#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          // Data 
    struct node *next; // Address 
};
struct node *head,*temp,*p,*r;
int count=0;
int create(int);
void traverseList();
void insert(int);
void delete(int);
int main()
{
    int n,k,q,d;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {  printf("enter:");
        scanf("%d",&k);
        create(k);
    }
    traverseList();
    printf("enter the index at what place to be inserted:");
    scanf("%d",&q);
    insert(q);
    printf("ok");
    traverseList();
    printf("enter the index at what place to be deleted:");
    scanf("%d",&d);
    delete(d);
    traverseList();
}
int create(int k)
{
    temp=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=temp;
        p=temp;
        p->data=k;
        p->next=NULL;
    }
    else
    {  p->next=temp;
       p=temp;
        p->data=k;
        p->next=NULL; 
    }
}
void traverseList()
{ count=0;
  temp = head;
    while(temp != NULL)
    {   count=count+1;
        printf("Data = %d\n", temp->data); 
        temp = temp->next;                 
    }  
}
void insert(int q)
{   int t;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&t);
    if(q==1)
    {
        printf("inserting at 1st place\n");
        temp->data=t;
        temp->next=head;
        head=temp;
    }
    
    else if(q==count){
         printf("inserting at last place\n");
        p=head;
        for(int i=1;i<q;i++)
        {
            p=p->next;
        }
         temp->data=t;
         p->next=temp;
    }
    else 
    {    printf("inserting after %d  place\n",q);
       
        p=head;
        for(int i=1;i<q;i++)
        {
            p=p->next;
        }
         temp->data=t;
         temp->next=p->next;
         p->next=temp;
    }
}
void delete(int d)
{    p=head;
    if(d==1)
    {
        printf("deleting 1st node\n");
    
        head=p->next;
    }
    else if(d==count)
    {   printf("deleting  last node\n");
        for(int i=1;i<d-1;i++)
        {
           p=p->next; 
        }
        p->next=NULL;
    }
    else
    { printf("deleting  %d node\n",d);
        for(int i=1;i<d-1;i++)
        {
           p=p->next; 
        }
        r=p->next;
        p->next=r->next;
        
    }
}