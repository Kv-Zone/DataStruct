#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node InitialList ()
{
     node *L ;
    int m ;
    int len ;
Printf("PUT list len");
scanf("%d",&len);
for(int i = 0 ; i< len ; i++)
{
     L = ( node*)malloc(sizeof(node));
    scanf("%d", &m);
    L->data = m;
}
return *L;

}
int main()
{
    
}