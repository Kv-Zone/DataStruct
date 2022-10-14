#include <iostream>
#include <fstream>
#include"HFM.h"

int main()
{
	while (true) {
		cout << "0.输入要压缩的文本(*结束)\n1.压缩\n2.解压:\n";
		int i = 0;
		cin >> i;//选择
		if (i == 0)//输入文本，保存到ToBeTran文件
		{
			ofstream OF("data//ToBeTran.txt", ios::binary);
			char c;
			cin.get();
			while (c = cin.get())
			{
				if (c == '*')
					break;
				else
					OF.put(c);
			}
			OF.close();
		}
		else if (i == 1)//对ToBeTran文件编码
		{
			HufTree *ht = new HufTree(1);//创建编码的对象
			ht->EnCode();//将ToBeTran文本的编码内容保存到CodeFile文件
			ht->TreePrint();//打印树
			delete ht;//删除对象
		}
		else if (i == 2)//对CodeFile文件译码
		{
			HufTree *ht = new HufTree();//创建译码的对象
			ht->Decode1();//对CodeFile文件内容译码
			delete ht;//删除对象
		}
	}
}