#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define Maxlen 10000
using namespace std;

typedef char elementType;

typedef struct Node {
	elementType data;
	struct Node *lc, *rc,*parent;
}node;
 
class Queue{
public:
	node* data[100];
	int front = 0 ;//类内初始化
	int rear = 0 ;
	bool empty(Queue q);
	void pop();
	void push(node *T);
};

bool Queue::empty(Queue q)
{
	if(front == rear) return true;
	else return false;
}

void Queue::push(node *T)
{
	data[rear] = T;
	rear++;
}

void Queue::pop()
{
	front++;
}
class BiTree {
private:
	node *root=NULL;
public:
	bool createTree(node *& root, node * par,char strLine[100][3], int nLen, int &nRow);
	void PrintPreOrder(node *T);//先序
	void PrintInOrder(node *T);//中序
	void PrintPostOrder(node *T);//后序
	void PrintInOrder_level(node *T, int i); //中序遍历输出结点值及对应层次数
	int height(node *T);//求树的高度
	int num_of_node(node *T);//节点数
	int num_of_lef(node *T);//叶子数
	int num_of_oneDegree(node *T);//度为1的节点数
	node* find(node *T,elementType e);//寻找值为e的节点并返回地址
	void nbrinfo(elementType e);//输入一个节点寻找其父节点，子节点，兄弟节点的值，若没有需要提示
	bool level(node *T,elementType e,int i);//寻找节点值为e的点，找到则输出层数，未找到则进行提void示
	bool empty() { return !root; };//判断是否为空树
	node*& TreeRoot() { return root; }//输出该树的根
	void convertFromArray(node *&T, elementType A[], int i);//从顺序储存转化为链式储存
	void printPath(node*T);//输出所有叶子节点到根节点的路径
	void printInLevel(node *T);//层序遍历
	void delete_tree(node *T);//delete the created tree
};

// void Myqueue::push(node *T)
// {
// 	qnode *newnode = 
// }
// void Myqueue::pop()
// {
// 	myqueue.front++;
// }

// bool Myqueue::if_empty(queuex *q)
// {
//     return (q->front == q->rear);
// }

bool ReadFileToArray(char filename[], char strLine[100][3], int &nArrlen) {
	//filename为打开的文件名
	//strLine存储二叉树结点信息
	//nArrlen为结点个数
	FILE * pf;
	char str[100];
	pf = fopen(filename, "r");//接收返回值
	if (!pf) {
		cout << "二叉树数据文件打开失败！\n";
		return false;
	}
	if (fgets(str, 1000, pf) != NULL) {
		if (strcmp(str, "BinaryTree\n") != 0) {
			cout << "打开的文件格式错误!\n";
			fclose(pf);
			return false;
		}
	}
	nArrlen = 0;
	while (fscanf(pf, "%c %c %c\n", &strLine[nArrlen][0], &strLine[nArrlen][1], &strLine[nArrlen][2]) != EOF) {
		cout << strLine[nArrlen][0] << ' ' << strLine[nArrlen][1] << ' ' << strLine[nArrlen][2]<<endl;
		nArrlen++;
	}
	fclose(pf);
	return true;
}

bool BiTree::createTree(node *& root,node * par,char strLine[100][3],int nLen,int &nRow) { //递归创建
	//nLen为结点数(总行数)
	//nRow当前行号
	if (nRow >= nLen || nLen == 0) {
		return false; //处理完毕或无数据
	}
	root = new node;
	root->data = strLine[nRow][0];
	root->lc = NULL;
	root->rc = NULL;
	root->parent = par;
	//cout << root->data << endl;
	int nRowNext = nRow;
	if (strLine[nRowNext][1] == '1') {
		nRow++;
		createTree(root->lc, root, strLine, nLen, nRow);
	}
	if (strLine[nRowNext][2] == '1') {
		nRow++;
		createTree(root->rc, root, strLine, nLen, nRow);
	}
	return true;
}

void BiTree::delete_tree(node *T){

	if(T)
	{
		delete_tree(T->lc);
		delete_tree(T->rc);
	}
	delete T;
	
}

void BiTree::PrintPreOrder(node *T){//递归先序输出二叉树
    if(T){
    cout<<T->data<<endl;//输出根节点数值
    BiTree::PrintPreOrder(T->lc);//左孩子
    BiTree::PrintPreOrder(T->rc);//右孩子
    }
}   

void BiTree::PrintInOrder(node *T){
    if(T){
        BiTree::PrintInOrder(T->lc);
        cout<<T->data<<endl;//输出根节点的值
        BiTree::PrintInOrder(T->rc);
    }
}

void BiTree::PrintPostOrder(node *T){
    if(T){
        BiTree::PrintPostOrder(T->lc);
        BiTree::PrintPostOrder(T->rc);
		cout<<T->data<<endl;//访问根节点
    }
}

void BiTree::PrintInOrder_level(node *T, int i){//即改造中序遍历的函数即可 函数中的i变化不会影响原函数的i
	if(T){
		BiTree::PrintInOrder_level(T->lc,i+1);
		cout<<"data:"<<T->data<<"  level:"<<i<<endl;
		BiTree::PrintInOrder_level(T->rc,i+1);
	}
}

int BiTree::height(node *T){//基于先序遍历的求高度
	int h1,h2,h;
	if(T==NULL){
		return 0;
	}
	h1 = height(T->lc);
	h2 = height(T->rc);
	h = ((h1>h2)?h1:h2)+1;
	return h;
	// return max(height(T->lc),height(T->rc))+1;
}

int BiTree::num_of_lef(node *T){
	if(T){
		if(T->lc==NULL && T->rc==NULL){//左右节点都不存在即为叶子节点
			return 1;
		}
		return (num_of_lef(T->lc) + num_of_lef(T->rc));//递归点
	}	
	return 0 ;//该节点T不存在则为0 不为叶子节点
}

int BiTree::num_of_oneDegree(node *T){
	if(T == NULL){//树空or无节点
		return 0;
	}
	if(T->lc == NULL && T->rc !=NULL)	
	{
		return 1+num_of_oneDegree(T->rc);
	}
	if(T->lc != NULL && T->rc ==NULL)
	{
		return 1+num_of_oneDegree(T->lc);
	}
	return num_of_oneDegree(T->lc) + num_of_oneDegree(T->rc);//当前节点的度不为1
}


node *BiTree::find(node *T , elementType e){
	if(T &&T->data == e)
	{
		return T;
	}
	if(T){//若未找到则继续向下寻找 
		node *t;
		if(t = find(T->lc , e)) return t;
		if(t = find(T->rc , e)) return t;
	}
	return NULL;

}


void BiTree::nbrinfo(elementType e) {
	node * addr = NULL;
	if (! (addr = find(root, e))) {
		cout << "the node doesn't exist" << endl;
		cin.get();
		return ;
	}

	if (addr->parent) {
		cout << "parent node:" << addr->parent->data <<  endl;
	}
	else cout << "the parent node doesn't exist" << endl;

	if (addr->parent) {//it doesn't have parent node so it doesn't have the brother node
		if (addr->parent->lc == addr) {
			if (addr->parent->rc) {
				cout << "itself is parent node's left child and it right brother is" << addr->parent->rc->data  << endl;
			}
			else {
				cout << "it doesn't have brother node" << endl;
			}
		}
		else {
			if (addr->parent->lc) {
				cout << "itself is parent node's right child and it left brother is " << addr->parent->lc->data  << endl;
			}else{
				cout << "it doesn't have brother node" << endl;
			}
		}
	}
	else {
		cout << "it doesn't have brother node" << endl;
	}

	if (addr->lc) {
		cout << "the left child node" << addr->lc->data <<endl;
	}
	else {
		cout << "it doesn't have left child node" << endl;
	}
	
	if (addr->rc) {
		cout << "the right child node" << addr->rc->data <<  endl;
	}
	else {
		cout << "it doesn't have right child node" << endl;
	}
	cin.get();
	return ;	
}

bool BiTree::level(node *T, elementType e , int i){//基于先序遍历的改造
    if (T&&T->data == e) {
		cout << "the level of the element is " << i << endl;
		cin.get();
		return true;
	}
	if (T) {
		if(level(T->lc, e, i+1)) return true;
		if(level(T->rc, e, i+1)) return true;
	}
	return false; //not found the element e 
}

void BiTree::convertFromArray(node *&T,elementType A[],int i) {
	T= new node;
	T->data = A[i];
	T->lc = NULL;
	T->rc = NULL;
	if (A[2 * i] != '^'&&A[2 * i] != 0 && A[2*i]!='#' ) { //约定数组有效数据不为0和'^'
		convertFromArray(T->lc, A, 2 * i );//左孩子
	}
	if (A[2 * i + 1] != '^'&&A[2*i+1]!=0 && A[2*i+1]!='#') {
		convertFromArray(T->rc, A, 2 * i + 1);//有孩子
	}
}

void BiTree::printPath(node *T){
	if(T){
		if(!T->lc && !T->rc){//没有左孩子且没有右孩子则为叶子节点
		node *leaf = T;
		while(leaf != root){
			cout<<"path "<<leaf->data<<"  ";
			leaf = leaf->parent;//向根节点递归的层进条件
			if(leaf == root) cout<<"path "<<leaf->data<<"  this leaf node over\n"<<endl;
		}
		}
		printPath(T->lc);//遍历左子树
		printPath(T->rc);//遍历右子树
	}
}

void BiTree::printInLevel(node *T){
	if(T){
		node *x;
		Queue q;
		q.push(T);//根节点入队
		while(!q.empty(q)){
			x = q.data[q.front];
			cout<<x->data<<"  ";
			q.pop();//弹出当前元素
			if(x->lc) q.push(x->lc);//如果含有左孩子则进行入栈
			if(x->rc) q.push(x->rc);//同上
		}
	}
}
