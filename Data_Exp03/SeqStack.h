#pragma once
#include<iostream>
using namespace std;
 
#define MAXLEN 100000
typedef int elementType;

class seqStack {

public: 
    elementType data[MAXLEN];//定义最长的数组长度 储存元素
    int t;
    int SeqNum = 0;
    void inital();//初始化
    bool Empty();//判断是否栈空
    bool get_top(elementType &x);//取栈顶元素
    bool full();//判断栈满
    bool push(elementType x);//压栈
    bool pop(elementType &x);//弹栈
    void convert(int n, int base);//转换进制
    bool paren(const char exp[]);//判断括号是否匹配
    bool stackPermutation(const int B[], int n);
    void OutSequence(int In[], int Out[], int n ,int i , int j);//判断有多少种出栈序列
};

void seqStack::inital() {
    t = -1;
}
bool seqStack::Empty() {
    return (t == -1);
}

bool seqStack::get_top(elementType &x) {
    if (Empty())
        return false;
    else {
        x = data[t];
        return true;
    }
}

bool seqStack::full() {
    return (t == MAXLEN - 1);
}

bool seqStack::push(elementType x) {
    if (full()) {
        return false;
    }
    else {
        data[++t] = x;
        return true;
    }
}

bool seqStack::pop(elementType &x) {
    if (Empty()) {
        return false;
    }
    else {
        x = data[t--];
        return true;
    }
}

void seqStack::convert(int n,int base) {// n为转化前的数字 base为转化后的进制
    inital();
    static char digit[] = { '0','1','2','3','4','5','6','7','8','9',
                         'A','B','C','D','E','F','G','H','I','J','K', 
                         'L','M','N','O','P','Q','R','S','T','U','V'};
    while (n>0) {
        int remainder = n%base;//取余数 用于计算
        push(digit[remainder]); 
        n /= base;
    }
    //
    cout << "转换后的进制数为:";
    while (!Empty()) {
        int x;
        pop(x);
        cout <<char(x);
    }
    cout << endl;
}

bool seqStack::paren(const char exp[]) {
    inital();
    elementType x;
    for (int i = 0; exp[i]; i++) {
        switch (exp[i]) {
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
    return Empty();
}

void seqStack::OutSequence(elementType In[], elementType Out[], int n,int i, int j)
{
    //In[]入栈序列,Out[]出栈序列
    //n 序列长度
    //i指示当前处理的入栈序列元素;    j指示当前获取的出栈序列元素                          
    //每次操作有可能有 2 种操作，要么出栈，要么入栈，且 2 种操作是或的关系。但，出栈、入栈递归返回后要恢复递归前状态
    elementType x;                                      //存放出栈的数
    if (Empty() && j >= n)                         //递归出口，获得了一个出栈序列
    {
        SeqNum++;
        //cout<<"第"<<SeqNum<<"种序列";
        cout << "#" << SeqNum <<"  ";
        // printf("第%d种", SeqNum);
        //打印序列
        for (int m = 0; m < n; m++)
        {
            cout << Out[m] << "   ";
        }
        cout << endl;
    }
    else if (!Empty() && i < n)                //栈不空且入栈序列中还有数据
    {
        //选择出栈
        pop(x);
        Out[j] = x;
        j++;
        OutSequence(In, Out, n, i,j);
        j--;                                        //递归返回，恢复到出栈前的状态
        push(x);
        //选择入栈
        push(In[i]);
        i++;
        OutSequence(In, Out, n, i, j);
        i--;                                        //恢复到入栈前的状态
        pop(x);
    }

    else if (!Empty() && i >= n) {              //栈不空，入栈序列数据已经处理结束
           //此时只能选择出栈操作
        pop(x);
        Out[j] = x;
        j++;
        OutSequence(In, Out, n,i, j);
        j--;                                        //恢复到出栈前状态
        push(x);
    }
    else if (Empty() && i < n)                 //栈空，入栈序列未处理结束
    {
        //此时，只能选择入栈操作
        push(In[i]);
        i++;
        OutSequence(In, Out, n,i, j);
        i--;                                        //恢复到入栈前的状态
        pop(x);
    }
}

bool seqStack::stackPermutation(const int B[],int n) {//B为序列的顺序 n为序列个数
    int i = 1 ; 
    elementType x ;
    for(int k = 0 ; k<n ; k++)
    {
        do
        {
            if(i<=n) push(i++);
            else return false;
        } while (!get_top(x) ||B[k]!=x);
        pop(x);
    }
    return true;
}
