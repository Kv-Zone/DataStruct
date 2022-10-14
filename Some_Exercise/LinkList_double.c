#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    struct node *prior ;//指向前方的指针
    struct node *next ;//指向后方的指针
    int data ;//数据域
} dNode;
void intiList(dNode *L)
{    
  
    int m ; 
    L->prior = L ;
    L->next = L ;
    printf("请输入链表长度");
    scanf("%d",&m);
    printf("请输入每个节点的数据");
    for(int i = 0 ; i<m ; i++)
    {
          dNode *m = (struct node*)malloc(sizeof(struct node));//创建新节点分配内存
          
    }
}
int main()
{
    dNode *L ; 
    L = (struct node*)malloc(sizeof(struct node));//创建一个头节点
    intiList(L);
}