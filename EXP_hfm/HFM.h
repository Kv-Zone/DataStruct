#pragma once
#include <string>
#include<fstream>
using namespace std;

int x = 0;

class HufNode
{
public:
	int weight = 0;//节点权重
	char key;//节点数据
	string code="";//节点编码
	HufNode*left = 0;//左子树
	HufNode*right = 0;//右子树
	HufNode*parent = 0;//父亲
	HufNode(char key, int weight)//构造函数
	{
		this->key = key;
		this->weight = weight;
	}
};

class HufTree
{
public:
	HufNode *head = 0;//哈夫曼树的根节点
	HufNode *code[256] = { 0 };//结点指针数组
	HufTree(int i)//编码过程的构造函数
	{
		HufNode *d[256] = { 0 };//临时指针数组保存字符信息
		Statistic_char(d);//统计字符信息
		head = HufCreat(d);//构建Huffman树
		ofstream *OF=new ofstream("data//CodePrint1.txt");
		HufCode(head, OF);//对树进行编码
		OF->close();
		SaveCode();//将编码信息保存到文件
	}
	HufTree()//译码过程的构造函数
	{
		GetCode();//从文件中获取编码信息
		this->head = HufCreat(code);//调用函数构建Huffm树
	}
	HufNode* HufCreat(HufNode *d[]);//哈夫曼树构造函数
	void EnCode();//编码函数
	//void Decode();
	void Decode1();//解压函数
	void TreePrint();//打印树
private:
	bool Decode_each_byte(HufNode*&temp, char byte, int &num, ifstream&IF, ofstream&OF);//对从CodeFile文件读出的每个字节进行解压
	void TreePrint(HufNode*temp, int i, ofstream&of);//打印树的结构
	void HufCode(HufNode*p, ofstream *&OF);//哈夫曼编码函数
	void Statistic_char(HufNode *d[]);//字符统计函数
	void Save_Text(string str);//保存字符到ToBeTran.txt文件
	void SaveCode();//保存出现的字符及编码到CodePrint1.txt，出现的字符及字符的个数放到CodePrint.dat文件
	void GetCode();//从CodePrint.dat文件获取字符及字符的出现数量，保存在内存里。
};

int myhash(char key);//定义哈希函数，根据字符返回数组下标


int myhash(char key)//定义哈希函数，根据字符返回数组下标
{
	/*if (key<'A' || (key > 'Z'&&key < 'a') || key>'z')//若key不是字母，根据ascii值分别返回53-62
		return key > 0 ? key % 10 + 53 : 53 - key % 10;
	return key > 'Z' ? key - 96 : key - 38;//'A'-'Z'分别返回1-26，'a'-'z'返回27-55*/
	return key + 128;
}

//从文件ToBeTran.txt中读入字符，并统计字符数，用d数组保存
void HufTree::Statistic_char(HufNode *d[])//字符统计函数
{
	ifstream IF("data//ToBeTran.txt", ios::binary);
	char temp;
	while (IF.get(temp))//遍历文件
	{
		int hash = myhash(temp);//计算当前字符的hash值,用整形hash保存
		if (!d[hash])//判断d[hash]节点是否存在
		{
			d[hash] = new HufNode(temp, 0);//不存在，则创建一个节点，key为当前字符，权重为0
			code[hash] = d[hash];
		}
		else 
		while (d[hash]&&d[hash]->key != temp)//若d[hash]已存在即已被占用，并且key值不同，则发生哈希冲突
		{
			hash++;//令hash值+1，浮动到一个未被占用或key值相同的位置
		}
		if (!d[hash])//再判断该位置是否被占用
		{
			d[hash] = new HufNode(temp, 0);//未被，则创建一个节点，key为当前字符，权重为0
			code[hash] = d[hash];
		}
		d[hash]->weight++;//权重+1
	}
	IF.close();
}


//查找两个权重最小，如果权重相同，则选键值小的节点。
//确保一组数据只能生成唯一的Huffman树
void search_tow_min(HufNode *d[], int &a, int &b)
{
	for (int i = 0; i < 256; i++)//i从1到255，遍历d[1]到d[255]
	{
		if (!d[i] || i == a || i == b)//d[i]不存在，跳出当前循环
			continue;
		if (!d[a] || d[i]->weight < d[a]->weight || (d[i]->weight == d[a]->weight&&d[i]->key < d[a]->key))//d[i]比d[a]更符合条件时
		{
			b = a; a = i;
		}
		else if (a == b || !d[b] || d[i]->weight < d[b]->weight || (d[i]->weight == d[b]->weight&&d[i]->key < d[b]->key))//d[i]比d[b]更符合条件
		{
			b = i;
		}
	}
}

//保存文本到ToBeTran.txt文件
void HufTree::Save_Text(string str)//保存文本信息
{
	ofstream of("data//ToBeTran.txt");
	int index = 0;
	char data;
	while (data = str[index++])
	{
		of.put(data);
	}
	of.close();
}

//构建Huffman树
HufNode* HufTree::HufCreat(HufNode *d[])//构造哈夫曼树
{
	int a = 0, b = 0;//定义a，b用于记录d数组中权重最小，且键值小的两个节点的下标，a为最小，b为次小。
	for (int i = 0; i < 256; i++)//最多循环256次，故i<256
	{	
		search_tow_min(d, a, b);//查找权重最小的两个节点
		//当权重相同，则选键值小的节点，即当 a和b的权重都为6时，选a不选b。
		if ((!d[b] || a == b) && i == 0 && d[a])
		{
			HufNode *temp = new HufNode(NULL, d[a]->weight);
			temp->left = d[a];
			return temp;
		}
		if ((!d[b] || a == b))//假如d[b]不存在,说明已经构造完毕,故直接返回d[a]
		{
			return d[a];
		}
		//创建d[a]、d[b]的根节点temp，初始化权重为d[a]、d[b]两个节点的权重之和
		HufNode *temp = new HufNode(NULL, d[a]->weight + d[b]->weight);
		temp->left = d[a]; temp->right = d[b];//令temp的左孩子=d[a]，右孩子=d[b]
		d[a]->parent = temp; d[b]->parent = temp;//d[a]、d[b]的父亲为temp
		d[a] = temp;//temp赋值给d[a]
		d[b] = 0;//令d[b]=0
	}
	return d[a];//循环结束，返回d[a]
}

//对Huffman树的节点编码
void HufTree::HufCode(HufNode*p, ofstream *&OF)//哈夫曼树生成哈夫曼编码
{
	//以根节点为中心，向左+0，向右+1
	if (!p)//p为空，返回
		return;
	if (p->left)//判断左孩子是否存在
	{
		p->left->code = p->code + '0';//左孩子的编码=父亲节点的编码+0
		HufCode(p->left, OF);//递归左孩子
	}
	if (p->right)//判断右孩子是否存在
	{
		p->right->code = p->code + '1';//右孩子的编码=父亲节点的编码+1
		HufCode(p->right, OF);//递归右孩子
	}
	if (!p->left&&!p->right)//若该节点无左右孩子，则为叶子节点，即记录信息的节点
	{
		OF->put(p->key);//写入文本编码信息
		OF->write(&p->code.at(0), p->code.length());
		OF->put('\n');
		x+=p->weight;
		cout << p->key << "字符的编码:\t" << p->code << "\t字符数为:" << p->weight <<"当前WPI为"<<x<<endl;//输出节点信息
	}
}

//通过字符查找Huffman树节点

//保存编码信息到Codeprint.dat文件
void HufTree::SaveCode()
{
	ofstream OF("data//Codeprint.dat", ios::binary);
	for (int i = 0; i < 256; i++)//将字符和对应字符的数量写入文件
	{
		if (!code[i])
			continue;
		OF.put(code[i]->key);//将字符写入文件
		OF.write((char*)&code[i]->weight, sizeof(int));//将整形的二进制代码写入文件
	}
	OF.close();
}

//将文本编码保存到CodeFile.dat文件
void HufTree::EnCode()//编码文本文件
{
	ofstream OF("data//CodeFile.dat",ios::binary);
	ifstream IF("data//ToBeTran.txt",ios::binary);
	char temp = 0;
	int size = 7;
	char data;
	while (IF.get(data))//从ToBeTran文件获取一个字符
	{
		HufNode* fn = this->code[myhash(data)];//获取该字符对应的Huffman结点指针
		if (!fn)//判断是否为空
			continue;
		string c = fn->code;//保存Huffman编码
		int n = 0, len = c.length();//获取长度
		while (n < len)//循环进行位运算，将Huffm编码写入位
		{
			if (c.at(n++) == '1')
				temp = temp | (1 << size);//对应二进制位置1
			size--;
			if (size < 0)//判断字节是否写满
			{
				OF.put(temp);//将字节写入文件
				temp = 0;
				size = 7;
			}
		}
	}
	if (size < 7)//写入最后一个字节
		OF.put(temp);
	OF.close();	IF.close();
}

//从Codeprint.dat文件获取编码信息
void HufTree::GetCode()
{
	for (int i = 0; i < 256; i++)
		delete code[i];
	ifstream IF("data//Codeprint.dat", ios::binary);
	char d;
	int index = 0;
	while (IF.get(d))//获取字符
	{
		char key = d;//记录字符
		int weight = 0;
		for (int i = 0; i < 4; i++)//循环获取整形的第i个字节
		{
			char d;
			IF.get(d);//获取整形的第i个字节
			for (int j = 0; j < 8; j++)//
				if (d & 1 << j)
					weight |= 1 << (i * 8 + j);//记录第i个字节
		}
		code[index++] = new HufNode(key, weight);//创建Huffman树的结点对象
	}
	IF.close();
}

//解压方式
void HufTree::Decode1()
{
	ofstream *OF = new ofstream("data//CodePrint1.txt");
	HufCode(this->head, OF);//对创建的Huffman树进行编码
	OF->close();
	ifstream IF("data//CodeFile.dat", ios::binary);//打开压缩文件
	OF->open("data//TextFile.txt", ios::binary);//打开要保存解压结果的文件
	char byte;
	HufNode*temp = this->head;
	int num = 0;
	while (true)//循环获取压缩文件的字节
	{
		IF.get(byte);//获取一个字节
		//判断Decode_each_byte函数的返回值和是否文件已经读完
		//Decode_each_byte函数对字节内容进行译码
		if (!Decode_each_byte(temp, byte, num, IF, *OF) || IF.cur == IF.end)
			break;
	}
	cout << endl;
	IF.close(); OF->close();
}

bool HufTree::Decode_each_byte(HufNode*&temp, char byte, int &num, ifstream&IF, ofstream&OF)
{
	for (int i = 7; i >= 0; i--)//对字节的每一位进行位运算
	{
		if (byte & (1 << i))//根据运算结果对temp指针进行游动
			temp = temp->right;
		else
			temp = temp->left;
		if (temp && !temp->left && !temp->right)//如果temp游动到叶子结点，将叶子结点信息输出
		{
			OF.put(temp->key);//将键值写入副本文件
			//cout << temp->code << '\t';//终端输出编码
			temp = this->head;//temp返回到Huffman树根节点
			if (++num == this->head->weight)//根据字符数判断是否已经译码完成
				return false;//完成则返回false
		}
	}
	return true;//否则返回true
}

void HufTree::TreePrint()
{
	ofstream of("data//TreePrint.txt");//打开文件
	TreePrint(this->head, 0, of);//调用有参数的TreePrint函数
	of.close();//关闭文件
}

void HufTree::TreePrint(HufNode*temp, int i, ofstream&of)
{
	if (!temp || !of)//判断参数是否有效
		return;
	TreePrint(temp->left, i + 1, of);//中序递归打印树的结构
	for (int j = 0; j < i; j++)
	{
		cout << '\t';
		of << '\t';
	}
	if (temp->key)
	{
		cout << temp->key << '\n';
		of << temp->key << '\n';
	}
	else
	{
		cout << "*\n"; 
		of << "*\n";
	}
	TreePrint(temp->right, i + 1, of);
}
