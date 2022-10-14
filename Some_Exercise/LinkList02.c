#include<stdio.h>
#include<stdlib.h>
 typedef struct Linklist
    {
        int data;
        struct Linklist *next;//指针域

    }Linklist;
void Deletex(int x , Linklist *p);
void orderlist(Linklist *A , Linklist *B);

void RevLinkList(Linklist *L){//链表逆序 新创一个头节点和遍历节点使用头插法
    Linklist *p = L->next,*q;
    L->next = NULL;
    while(p != NULL){//头插法构建新的链表
        q = p->next;//q指向下一个节点，即剩余链表的头一个元素
        p->next = L->next;
        L->next = p;
        p = q;
    }
}


Linklist *LinklistBing(Linklist* m, Linklist* n){
Linklist * p = (struct Linklist *)malloc (sizeof(struct Linklist));       //建立一个新链表
p->next = NULL;
Linklist * M, * N;
M = m->next, N = n->next;              //指向首元素节点
while (M != NULL && N != NULL){
if (M->data < N->data){            //m节点的元素值较小，将m节点存入新表，m后移
Linklist* u = (struct Linklist *)malloc (sizeof(struct Linklist));
u->data = M->data;
u->next = p->next;
p -> next = u;
M = M->next;
}
else if(M->data > N->data) {         //n节点的元素值较小，将n节点存入新表，m后移
Linklist* u = (struct Linklist *)malloc (sizeof(struct Linklist));
u->data = N->data;
u->next = p->next;
p->next = u;
N = N->next;
}
else{                               //相等只需存入其中一个表，m，n均后移
Linklist * u = (struct Linklist *)malloc (sizeof(struct Linklist));
u->data = N->data;
u->next = p->next;
p->next = u;
N = N->next;
M = M->next;
}
}
while (M != NULL) {                      //A表未遍历结束，A表后续节点全部接入新表
Linklist *u = (struct Linklist *)malloc (sizeof(struct Linklist));
u->data = M->data;
u->next = p->next;
p->next = u;
M = M->next;
}
while (N != NULL) {                     //B表未遍历结束，B表后续节点全部接入新表
Linklist *u = (struct Linklist *)malloc (sizeof(struct Linklist));
u->data = N->data;
u->next = p->next;
p->next = u;
N = N->next;
}
return p;                            //返回新表
}


int main(void)
{
struct Linklist *head = (struct Linklist *) malloc(sizeof(struct Linklist));//头节点动态分配内存
struct Linklist *head1 = (struct Linklist *) malloc(sizeof(struct Linklist));//头节点动态分配内存
head->next = NULL;//头节点初始化
struct Linklist *p ; //遍历使用的节点
struct Linklist *p1;



int n ;
printf("put listlen");
scanf("%d",&n);//节点总数
printf("put data");
for(int i =0 ;i<n;i++)
{
    struct Linklist *s = (struct Linklist *)malloc(sizeof(struct Linklist));//为头插法的节点分配内存
    //头插法有点类似栈的形式 先进后出 第一个输入的数字是最后一个输出的数字
    int m ;
    scanf("%d",&s->data);//存入节点的数据域
    s->next = head->next;//先动后侧的节点 否则不能找到链表的顺序
    head->next = s;
}
p = head ;//p赋值为头节点

// RevLinkList(p);

int m ;
printf("put listlen");
scanf("%d",&m);//节点总数
printf("put data");
for(int i =0 ;i<m;i++)
{
    struct Linklist *s1 = (struct Linklist *)malloc(sizeof(struct Linklist));//为头插法的节点分配内存
    //头插法有点类似栈的形式 先进后出 第一个输入的数字是最后一个输出的数字
    int m ;
    scanf("%d",&s1->data);//存入节点的数据域
    s1->next = head1->next;//先动后侧的节点 否则不能找到链表的顺序
    head1->next = s1;
}
p1 = head1;



// int x ; 
// printf("put delete num");
// scanf("%d",&x);
// Deletex(x , p);

orderlist( p , p1 );

while(p->next)//因为是头节点 所以输出的数值域是位于下一个节点内的
{
    printf("%d\n",p->next->data);
    p=p->next;
}
return 0;
}



void Deletex(int x , Linklist *p){
    Linklist *u ;

    while(p->next)
    {
        if(p->next->data==x)//若符合条件 则p->next（u）是需要删除的节点
        {
            u = p->next;//需要删除的节点
            p->next  = u->next;//绕过p->next节点
            free(u);
        }
        else{
            p = p->next;
        }
    }
    printf("over\n");
}

void orderlist(Linklist *A , Linklist *B)
{
    Linklist *p1 ,*p2 , *new0 , *new1;
    p1 = A;
    p2 = B->next;
    while(p1->next!=A && p2->next!=B)
    {

        if(p1->next->data < p2->data)
        {
           p1= p1->next;//A链表后指一位 后续再比较 B链表数字若小于A表则插入A
        }

        else if (p1->next->data > p2->data)
        {
            new0 = (struct Linklist *)malloc(sizeof(struct Linklist));//对行节点分配内存 准备存入A链表
            new0->data = p2->data;//将B表的值赋给新节点
            new0->next = p1->next;//将新节点插入A链表
            p1->next = new0;
            p2 = p2->next;
        }
         else //(p1->next->data == p2->data)
        {
                       
            p1=p1->next;//链表A B同时后指一位 因为数值相等 求并集就不需要调整 直接使用A的原数据即可
            p2 = p2->next;
        } 
       
    }
    while(p2!=B)//A表遍历完的情况下B表未遍历完
    {
        
        new1 = (struct Linklist *)malloc (sizeof(struct Linklist));//对需要加入的新节点分配内存
        new1->data = p2->data ; 
        new1->next = p1->next;
        p1->next = new1;//应当加到A链表的结尾 因为A表已经遍历完毕
        p1 = new1;
        p2 = p2->next;
    }
}