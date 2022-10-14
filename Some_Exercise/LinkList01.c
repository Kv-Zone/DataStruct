#include <stdio.h>
#include <stdlib.h> 

typedef struct node
{
    int data;
    struct node *next;
 }Node;

int listDelX(int x , Node *p);
void bingji(Node *a , Node *b);

 int main(){
      struct node *head,*p,*q,*t;
     int i,n,a;
     scanf("%d",&n);
     head->next=NULL;//头指针初始化

     for(i=0;i<n;i++){
         p=(struct node *)malloc(sizeof(struct node));//动态开辟内存
         scanf("%d",&a);//输入各节点的数据
         p->data=a;//data项指向a 
         p->next=NULL; //指针项则是尾指针对null
         if(head==NULL)//若头指针为空 则此点为第一个节点
             head=p;
         else
             q->next=p;
         q=p;
           t=head;
     }

     int m = listDelX(4 ,t );

printf("a");
      while(p!=NULL){
          printf("%d ",p->data);
          p=p->next;
      }
      printf("b");
      return 0;
 }

 int listDelX(int x , Node *p){//删除data为x的节点的操作
     Node *u;
     Node *H = p;//指向头节点
     int result =0 ;//1 为成功删除 0 为不存在该数
     while(H->next)
     {
         if(H->next->data==x)
         {
             u = H->next ;//此点为需要删除的节点
             H->next = u->next;//绕过节点u使前驱指向下一个节点
             free(u);//删除节点
             result = 1;
         }
         else{
             H=H->next;
         }
     }
     if(result==1)
     {
         return 1;//删除成功
     }
     else{
         return 0 ;//不存在此数字
     }
 }

 void bingji(Node *A ,Node  *B)//有序递增链表求并集存入原链表
 {

 }