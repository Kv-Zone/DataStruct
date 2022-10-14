#pragma once
#include<iostream>
using namespace std; 

typedef int Element ; 

typedef struct Node{
    Element data ;
    struct Node *next;
}node;

class LinkedStack{
    private:
     node *p ;
    public:
    int LinkNum = 0;//储存输出序列的种类
    void initial();
    bool empty();
    void push(Element x);
    bool pop(Element &x);
    bool get_top(Element &x);
    void convert(int n , int base);
    bool paren(const char exp[]);
    void Output(Element input[], Element ioutput[], int len, int i, int j);
};
void LinkedStack::initial(){
    p = NULL;//指针初始化
}
bool LinkedStack::empty(){
    return(p==NULL);
}
void LinkedStack::push(Element x)//新创建节点 将新的数据尾插进入链表的结构中
{
    node *s = new node;
    s->data = x;
    s->next = p;
    p = s;
}

bool LinkedStack::pop(Element &x){
    if(empty())
    {
        return false ;
    }
    else
    {
        node *t;//创建一个新节点来储存需要删除的节点地址
        x = p->data;
        t = p ;
        p = p->next;//指向下一个元素
        delete t;
        return true;
    }
}

bool LinkedStack::get_top(Element &x){
    if(empty())
    {
        return false;//栈空 无栈顶元素
    }
    else
    {
        x = p->data;
        return true;
    }
}

void LinkedStack::convert(int n , int base){
    initial();
    static char digit[] = { '0','1','2','3','4','5','6','7','8','9',
                         'A','B','C','D','E','F','G','H','I','J','K', 
                         'L','M','N','O','P','Q','R','S','T','U','V'};
    while(n>0)
    {
        int reminder = n % base;
        push(digit[reminder]);//将对应的进制数压入栈中
        n=n/base;//靠近循环的终止条件
    }
    cout << "新进制下的数：";
    while(!empty())//遍历输出结果
    {
     int m ;
     pop(m);
     cout<<char(m);  
    }
    cout<<endl;          
}

bool LinkedStack::paren(const char exp[])//判断表达式括号数量是否正确
{
    initial();
    Element x ;
    for(int i = 0 ; exp[i] ; i++)//遍历表达式
    {
        switch(exp[i]){
            case '(':case '[':case '{':
                push(exp[i]);
                break;
            case ')':
                if (!pop(x) || '(' != x)
                    return false;
                break;
            case ']':
                if (!pop(x) || '[' != x)
                    return false;
                break;
            case '}':

                if (!pop(x) || '{' != x)
                    return false;
                break;
            default: break;
        }
    }
    return (empty());//栈空表示匹配
}

//按123..n入栈的顺序求出栈可能序列, 因为是用数组要注意输入的操作
void LinkedStack::Output(Element input[], Element ioutput[], int len, int i, int j)
{
    //i, j-----对应入栈序列和出栈序列的数组下标
    Element x;//储存当前的数字

    //栈空，且得到一个出栈序列
    if (empty() && j >= len)
    {
        //这里同时作为递归的出口
        LinkNum++;

        cout << "#"  <<LinkNum << "   ";
        for(int i = 0 ; i<j ; i++)
        {
            cout<<ioutput[i];
        }
        cout<<endl;
    }
    else if (!empty() && i < len)//栈不空，且入栈序列还有元素
    {
        //此时对每一个在栈内的元素而言，要么出栈要么入栈
        pop(x);
        ioutput[j] = x;
        j++;
        Output(input, ioutput, len, i, j);

        j--;//返回之前的状态
        push(x);

        push(input[i]);//入栈
        i++;
        Output(input, ioutput, len, i, j);

        i--;//恢复到入栈之前的状态
        pop(x);
    }
    else if (!empty() && i >= len)//当栈不为空， 入栈序列已经完了，此时只能出栈
    {
        pop(x);
        ioutput[j] = x;
        j++;
        Output(input, ioutput, len, i, j);

        j--;
        push(x);//恢复到之前的状态
    }
    else if (empty() && i < len)//栈空，但是入栈序列还没有完，此时只能入栈
    {
        push(input[i]);
        i++;
        Output(input, ioutput, len, i, j);

        i--;
        pop(x);
    }
return ;
}


