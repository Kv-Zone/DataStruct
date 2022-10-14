#pragma once
#define Max 100
#include<iostream>
#include<cstring>
using namespace std;
typedef char elementType ;

typedef struct pnode
{
    elementType data ;
    int parent ; //父节点下标
}PTnode;

typedef struct pTree//森林结构
{
    pnode node[Max] ;//储存节点的数组
    int n ;//储存节点总数
    // void initialTree(pTree &T);
    // bool getAncestor(pTree &T, elementType x);
    // void getChildren(pTree &T, elementType x);
    // int firstChild(pTree &T,int v);
    // int nextSibling(pTree &T,int v,int w);
    // void preOrder(pTree &T,int v);
}PTree;

void initialTree(pTree &T)
{
    T.n = 0;//总数为0
}

bool getAncestor(PTree &T, elementType x)
{
    int w = 0 ;//遍历下标
    elementType y ;
    y = x ;
//所有子节点只会有一个父节点 但是一个父亲节点不止有一个孩子节点
    for(w = 0; w < T.n; w++){
        if(T.node[w].data == y){//找到了值为x的节点
            w = T.node->parent;//获取父节点
            y = T.node[w].data;//获取对应值
            cout<<"parent node"<<y<<endl;
            break;
        }
    }
    if(w>T.n){//元素x不在树上
     return false;   
    }
    while(w!=-1)//寻找所有祖先节点
    {
        if(T.node[w].data == y)
        {
            w = T.node->parent;//获取父节点
            y = T.node[w].data;//获取对应值   
            cout<<"parent node"<<y<<endl;
        }
        else
        {
            w = (w+1) % T.n;//循环操作 
        }
        return true ;
    }
	return true;
}

void getChildren(pTree &T, elementType x)
{
    int w,i;
    for(w=0 ; w<T.n ; w++){
        if(T.node[w].data == x){
            break;
        }
    }
    if(w>T.n){//节点不存在表中
        cout<<"节点不存在"<<endl;
        return ;
    }

    for(i = 0 ; i <T.n ; i++)//不止一个孩子节点奥
    {
        if(T.node[i].parent == w)
        {
            cout<<T.node[i].data<<"\t";
        }
    }
    cout<<endl;
}
//先序遍历的构成
int firstChild(pTree &T,int v)//输出下标为v的节点的第一个孩子节点下标
{
	int w;
	if(v==-1)//不存在树中
		return -1;

	for(w=0;w<T.n;w++)
	{
		if(T.node[w].parent==v)
			return w;
	}
	return -1;
}

int nextSibling(pTree &T,int v,int w)  //搜索v的下标位于w之后的下一个孩子结点下标
{
	int i;
	for(i=w+1;i<T.n;i++)
		if(T.node[i].parent==v)
			return i;
	return -1;
}

void preOrder(pTree &T,int v)
{
	int w;
	cout<<T.node[v].data<<"\t";//当前节点值 

	w=firstChild(T,v);//找到其第一个左孩子
	while(w!=-1)
	{
		preOrder(T,w);//递归遍历
		w=nextSibling(T,v,w);	
	}
}

void preTraverse(pTree &T)//先序遍历整体
{
	int i;
	int visited[Max];
	for(i=0;i<T.n;i++)
	{
		visited[i]=0;	
	}
	    //搜索根结点，可能是森林，有多个根结点
	for(i=0;i<T.n;i++)
	{
		if(T.node[i].parent==-1)
			preOrder(T,i);
	}	
}

void postOrder(pTree &T,int v)//后序遍历
{
	int w;
	w=firstChild(T,v);
	while(w!=-1)
	{
		postOrder(T,w);
		w=nextSibling(T,v,w);	
	}
	cout<<T.node[v].data<<"\t";   //访问根结点
}

void postTraverse(pTree &T)
{
	int i;
	int visited[Max];
	for(i=0;i<T.n;i++)
	{
		visited[i]=0;	
	}
	    //搜索根结点，可能是森林，有多个根结点
	for(i=0;i<T.n;i++)
	{
		if(T.node[i].parent==-1)
			postOrder(T,i);
	}
}

void printTree(pTree &T)//打印树的数据
{
	int i;
	cout<<"下标\t结点\t双亲"<<endl;
	for(i=0;i<T.n;i++)
		cout<<i<<"\t"<<T.node[i].data<<"\t"<<T.node[i].parent<<endl;
}

//链式的结构
	
typedef char elementType;

typedef struct csNode
{
	elementType data;
	struct csNode *firstChild, *nextSibling;
}csNode,*csTree;

//删除字符串、字符数组左边空格
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //找到左起第一个非空格位置
			break;
	}
	    //以第一个非空格字符为手字符移动字符串
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}

int CreateTreeFromFile(char fileName[], pTree &T)
{
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000];  //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行

    int i=0,j=0;


	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("错误：文件%s打开失败。\n",fileName);
		return false;
	}
	
	while(fgets(str,1000,pFile)!=NULL)  //跳过空行和注释行
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //跳过注释行
			continue;
		else  //非注释行、非空行，跳出循环
			break;
	}

    //循环结束，str中应该已经是文件标识，判断文件格式
	if(strstr(str,"Tree or Forest")==NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}


	//读取结点数据，到str。跳过空行
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

	//结点数据存入树的结点数组		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		T.node[nNum].data=*token;
		T.node[nNum].parent=-1;       //父结点指针初始化为-1
		
		token = strtok( NULL, " ");
        
		nNum++;
	}
	
    //循环读取边（父子队）数据
	int nP;  //父结点数组下标
	int nC;  //子结点数组下标

	elementType Nf,Ns; //父子结点对的两个结点
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;
		
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;

		char* token=strtok(str," ");  //以空格为分隔符，分割一行数据，写入邻接矩阵
		
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取树的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf=*token;  //获取父结点
		
		token = strtok( NULL, " ");  //读取下一个子串，即子结点
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取树的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns=*token;  //获取边的第二个结点（子结点）
            //取得父结点下标		
		for(nP=0;nP<nNum;nP++)
		{
			if(T.node[nP].data==Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
           //获取子结点的数组下标		
		for(nC=0;nC<nNum;nC++)
		{
			if(T.node[nC].data==Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		T.node[nC].parent=nP;        //nC的父结点的下标为nP
	}

    T.n=nNum;  //树的结点数，即顶点数组的实际大小

	fclose(pFile); //关闭文件
	return true;
}

//搜索双亲表示中，下标w的下一个兄弟结点，返回兄弟结点的下标
int next(pTree T,int w)  
{
	int i;
	for(i=w+1;i<T.n;i++)
	{
		if(T.node[w].parent==T.node[i].parent)//父亲节点相同则返回下标
			return i;	
	}
	return -1;
}

//递归创建一棵孩子兄弟链表表示的树
void create(csNode *&T,pTree &T1,int v)
{
	int w;
	T=new csNode;
	T->data=T1.node[v].data;
	T->firstChild=NULL;
	T->nextSibling=NULL;
	w=firstChild(T1,v);  //搜索v的第一个孩子结点
	if(w!=-1)
	{
		create(T->firstChild,T1,w);
	}
	
	w=next(T1,v);       //搜索v的下一个兄弟结点
	if(w!=-1)
	{
		create(T->nextSibling,T1,w);
	}	
}

//从双亲表示的树（森林）创建孩子兄弟链表表示的树（森林）
void createCsTree(csNode *&T,pTree T1)
{
	int i;
	//搜索T1的第一个根结点
	for(i=0;i<T1.n;i++)
	{
		if(T1.node[i].parent==-1)   //找到第一个根结点
			break;		
	}
	if(i<T1.n)
		create(T,T1,i);
}


