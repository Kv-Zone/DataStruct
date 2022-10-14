#include "CreateTree.h"
#include <queue>
using namespace std;

void preOrderprint(csNode *T)//先序遍历
{
    if(T)
    {
        cout<<T->data<<" ";
        preOrderprint(T->firstChild);
        preOrderprint(T->nextSibling);
    }
}

void postOrderprint(csNode *T)
{
    if(T)
    {
        preOrderprint(T->firstChild);
        preOrderprint(T->nextSibling);
        cout<<T->data<<" ";
    }
}

void printbylevel(csNode *T)
{
    queue<csNode*> q;//创建模板 也可以使用数组来模拟队列
    csNode *u , *n , *p;
    if(T ==NULL)
    {
        return;
    }
    n = T;
    while(n)
    {
        p = n ;
        q.push(p);//当前节点入队
        while(!q.empty())
        {
            p = q.front();
            cout<<p->data<<" ";
            u = p->firstChild;
            while(u)
            {
                q.push(u);
                u = u->nextSibling;//将当前父节点的所有子节点入队
            }
            q.pop();
        }
        n = n->nextSibling;//可能不止一颗树 有可能是森林
    }

}

int Height(csNode *T)
{
    if(T==NULL){
        return 0 ;
    }
    else 
    {
        int a , b ;
        a = Height(T->firstChild)+1;
        b = Height(T->nextSibling);
         if(a>=b)
    {
        return a ;
    }
    else return b;
    }
   
}

// int Get_Height(csNode *T)//获取当前子树的最大高度
// {
//     int h_1 = 0 , h_2;
//     csNode *s;
//     if(T == NULL)
//     {
//         return 0;
//     }
//     else{
//         s = T->firstChild;//接收节点
//         h_1 = Get_Height(s);
//         if(s)
//         {
//             s = s->nextSibling;//指针改指兄弟节点 求兄弟节点的高度
//         }

//         while(s)
//         {
//             h_2 = Get_Height(s);//兄弟节点的高度
//             if(h_1<h_2)
//             {
//                 h_1 = h_2;
//             }
//             s = s->nextSibling;
//         }
//         return h_1+1;
//     }
// }


// int Get_Height_Forest(csNode *T)//对森林的最大高度
// {
//     int max = 0 , min = 0;
//     csNode *s;
//     s = T;
//     min = Get_Height(s);
//     while(s)
//     {
//         if(min>max)
//         {
//             max = min;
//         }
//         s = s->nextSibling;
//         min = Get_Height(s);
//     }
//     return max;
// }

void Num_of_leaf(csNode *T, int &leafnum)//基于先序遍历的改造
{
    if(T)
    {
        if(T->firstChild == NULL)//因为如果树的节点没有第一个孩子则一定没有孩子节点
        {
            leafnum++;
        }
        Num_of_leaf(T->firstChild,leafnum);
        Num_of_leaf(T->nextSibling,leafnum);
    }
}

int degreeOfForest(csNode *T)
{
    queue<csNode *> q;//该题需要队列模拟过程，需要分析每个节点的孩子节点数量
    csNode * u,*n,*p;
    int min=0,max=0;
    if(T==NULL)
    {
        return 0;
    }
    n=T;
    while(n)
    {
        p=n;
        q.push(p);//当前元素入队
        while(!q.empty())//队列不为空的时候队列元素
        {
            p=q.front();//取队头元素
            u=p->firstChild;
            while(u)//当前元素的所有子节点入队
            {
                p=u;
                q.push(p);
                u=u->nextSibling;
                min++;//度++
            }
            if(min>max)//判断最大值
            {
                max=min;
            }
            min=0;//比较完一个节点后需要置0 防止和下一个节点的度混淆
            q.pop();//当前元素出队
        }
        n=n->nextSibling;
    }
    return max;
}

void PreOrderprint_level(csNode *T,int level)//先序输出并输出层数
{
    if(T){
    cout<<"("<<T->data<<","<<level<<")"<<endl;
    PreOrderprint_level(T->firstChild,level+1);//寻找子节点的时候需要层数+1
    PreOrderprint_level(T->nextSibling,level);//寻找兄弟节点的时侯层数不需要变化
    }
}

void PutWlist(csNode *T)//输出广义表代表的树
{
    if(T)
    {
        cout<<T->data;
        if(T->firstChild)
        {
            cout<<"(";
            PutWlist(T->firstChild);
        }
        if(T->nextSibling)
        {
            cout<<",";
            PutWlist(T->nextSibling);
        }
        else
        {
            cout<<")";
        }
    }
}

void destory_tree(csNode *T)
{
    if(T)
    {
        destory_tree(T->firstChild);
        destory_tree(T->nextSibling);
        delete T;
    }
}