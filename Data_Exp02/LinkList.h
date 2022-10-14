#pragma once

#include<iostream>
#include<cstdlib>
#define Max 100
using namespace std;

typedef int elementType;
typedef struct Node{
    elementType data;//数值域
    struct Node* next;//创建其链表的指针域
}node;

class LinkList{
    private:
    int length = 0;//链表长度
    node *L;//头节点
    public:
    void initial();//链表的初始化
    node* get_head()//获取头节点
    {
        return L ;
    }
    int getlength()//获取链表长度
    {
        return length;
    }  
    void show();//展示链表的内容
    void destroy();//销毁链表
    void insert(elementType x);//尾插一个数字
    void insertR();//尾插法
    bool insert(int i , elementType x);//任务<1> 在位置i插入一个数x 失败则报错
    bool delete_num(int i);//任务<2> 删除指定位置i处的数字，失败则报错
    void insertA(elementType x);//任务<3> 在有序链表中加入一个数字x保证原链表顺序不变
    void decompose_odd_even();//任务<4> 分开链表中的奇数元素和偶数元素
    LinkList intersect(LinkList const &L);//任务<5>取两个递增有序链表的交集
    void unique();//任务<6>删除单链表中重复元素并且时时间效能最好
    void merge(LinkList L2);//任务<7>合并两递增有序表（不申请新节点） 并且使得L1为表头 L2头节点删除
};

void LinkList::initial(){
    L = new node ;//创建一个头节点
    L->next = NULL;
    int length = 0;//头节点不计入长度单位
}
void LinkList::show(){
    node *p = L->next;
    while(p!=NULL){
            cout<<p->data<<" ";
            p = p->next;//遍历条件
    }
}

void LinkList::destroy()
{
    node *p = L ;
    node *q ;//临时储存下一个删除的变量
    while(p!=NULL)
    {
        q = p->next;
        delete p ;
        p = q ;
    }
    L = NULL;
}

void LinkList::insertR(){//尾插法的实现
       node *p=L;
    elementType x;
    cout<<"输入元素(以-1结束):";
    while(cin>>x&&x!=-1){
        while(p->next!=NULL){
            p=p->next;
        }
        node *u=new node;
        u->data=x;
        u->next=NULL;
        p->next=u;
        length++;
    }
    cin.get();
}

bool LinkList::insert(int i , elementType x){
    node *p = L;
    int k = 0 ;
    while(k!=i-1 && p!=NULL)
    {
        p = p->next ; //使指针跳至需要插入的位置 即k=i-1
        k++;
        if(p==NULL)
        {
            cout<<"序号错误！"<<endl;
            return false;
        }
    }
    node *u = new node ;
    u->data = x ;
    u->next = p->next;
    p->next = u ;
    length++;
    return true ;
}
void LinkList::insert(elementType x){
    insert(getlength()+1,x);
}

bool LinkList::delete_num(int i){
    node *p = L;
    int k = 0 ;
    if(i==length+1||i==0||i>length)
    {
        cout<<"输入序号错误"<<endl;
        return false;
    }
    while(k!=i-1 && p!=NULL){
        p = p->next;
        k++;
        if(p==NULL)
        {
            
            return false ;
        }
    }
    node *u = p->next;
    p->next = u->next;
    delete u ;
    return true ;
}

void LinkList::insertA(elementType x){
    node *p= L;
    while(p->next!=NULL&&p->next->data<=x){
        p=p->next;
    }
    node *u=new node;
    u->data=x;
    u->next=p->next;
    p->next=u;
}

void LinkList::decompose_odd_even(){
    node *p=L->next;
    LinkList odd,even;
    odd.initial();
    even.initial();
    while(p){
        if(p->data%2){
            odd.insert(p->data);
        }
        else{
            even.insert(p->data);
        }
        p=p->next;
    }
    cout<<"原表：";
    show();
    cout<<"奇数项表：";
    odd.show();
    cout<<"偶数项表：";
    even.show();
    odd.destroy();
    even.destroy();
}

LinkList LinkList::intersect(LinkList const &L2){
        node *p1=L->next,*p2=L2.L->next;
    LinkList  L3;
    L3.initial();
    while(p1&&p2){//类似有序线性表取并集的操作 双指针遍历数组
        if(p1->data<p2->data){
            p1=p1->next;
        }
        else if(p1->data==p2->data){
            L3.insert(p1->data);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
    }
    return L3;
}

void LinkList::unique()
{
        node *p=L->next;
    int i=2;//第一个重复数字不会出现在1位置 所以定义i为2
    int num = 0 ;
    while(p){
        while(p->next&&p->next->data==p->data){
            delete_num(i);
            num++;
        }
        i++;
        p=p->next;
    }
    // cout<<num;
}

void LinkList::merge(LinkList L2)
{
    node *p1=L,*p2=L2.L->next;
    while(p1->next&&p2){
        if(p1->next->data == p2->data){
            p1=p1->next;//相等则删除一个节点
            node *t=p2->next;
            delete p2;
            p2=t;
        }
        else if(p1->next->data < p2->data){
            p1=p1->next;//p1的值小于p2先放p1数值
        }
        else if(p1->next->data > p2->data){
            node *u=p1->next;//p2的值小于p1则先放p2的值
            node *v=p2->next;
            p1->next=p2;
            p1->next->next=u;
            p2=v;
        }
    }
    if(p2) p1->next=p2;//若表未遍历完成 则进行p2的整体尾插法
    delete L2.L;//删除无用的节点
    L2.L=NULL;
}