#include<iostream>
using namespace std;
typedef struct Node{
    int data ;
    struct Node* next ;
}node;
int main()
{
    //头插法
    node *L = new node ;
    L->next = NULL;
    int length  = 0 ;
    cout<<"输入数据以-1为截止条件"<<endl;
    int x ;
    node *k = L->next;
    while(cin>>x && x!=-1)
    {
        node *p = new node ;
        p->data = x ;
        p->next = k ;
        L->next = p;
        length++;
    }
    k = L->next;
    while(k->next!=NULL)
    {
        cout<<k->data;
        k= k->next;
    }
    return 0 ;
}