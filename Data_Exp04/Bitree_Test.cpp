#include<iostream>
#include<cstdlib>
#include"Bitree.h"
using namespace std;

int main() {
	BiTree T,T1;
    elementType A[100];
    char filename[50];
    char strLine[100][3];
    int nArrlen=0, nRow = 0;
    char x ;
    int i = 0;
	while (true) {
			cout << "0.创建二叉树\n";
			cout << "1.设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。\n";
			cout << "2.求二叉树的叶子结点数。\n";
			cout << "3.求二叉树的度为1的结点数。\n";
			cout << "4.键盘输入一个元素x,求其父节点、兄弟结点、子结点的值,存在时给出相应提示信息。\n";
			cout << "对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。\n";
			cout << "5.键盘输入一个元素x,求其在树中的层次。不存在时给出相应提示信息。\n";
			cout << "6.输出所有叶子节点到根节点的路径\n";
            cout << "7.将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。\n";
            cout << "8.对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次遍历序打印。（提示：需要使用队列）\n";
            cout << "9.删除当前的二叉树数据并退出程序\n";
			int choose;
			cin >> choose;
			cin.get();
			switch (choose){
                 case 0 :
                cout << "输入文件名" << endl;
                cin >> filename;
                cin.get();
                if (!ReadFileToArray(filename, strLine, nArrlen)) {
                    cout << "读取文件失败" << endl;
                    cin.get();
                    break;
                    }
                    if (!T.createTree(T.TreeRoot(), NULL, strLine, nArrlen, nRow)) {
                        cout << "创建失败！" << endl;
                        cin.get();
                        }
                     else 
                     cout << "创建成功！" << endl;

                     cout <<"根结点地址："<<T.TreeRoot() << endl;
                     cin.get();
                 break;

                 case 1 :
                 T.PrintInOrder_level(T.TreeRoot(),1);
                 cin.get();
                 break;

                 case 2 :
                 cout<<"该树的节点叶子节点为"<<T.num_of_lef(T.TreeRoot())<<endl;
                 cin.get();
                 break;

                 case 3 :
                 i = T.num_of_oneDegree(T.TreeRoot());
                 cout<<"该树的度为1的节点数为:"<<i<<endl;
                 cin.get();
                 break;

                 case 4 :
                 cout<<"请输入需要查询的元素x"<<endl;
                 cin>> x ;
                 T.nbrinfo(x);
                 cin.get();
                 break;

                 case 5 :
                 cout<<"请输入需要查询的元素x"<<endl;
                 cin>> x;
                 if (!T.level(T.TreeRoot(), x, 1)) {
                     cout << "不存在该元素" << endl;
                     }
                cin.get();
                 break;

                 case 6 :
                 cout<<"输出每个叶子节点到根节点的路径"<<endl;
                 T.printPath(T.TreeRoot());
                 cin.get();
                 break;

                 case 7 :
	             memset(A, 0, sizeof(A));
                 cout << "按下标顺序输入该数组(以'#'结束):";
                 while ( i==0 || A[i] != '#') {
		         cin >> A[++i];
	            }
	             cin.get();
	             T.convertFromArray(T.TreeRoot(), A,1);
	             cout << "转换完成，二叉树的层次遍历序列为：";
	             T.printInLevel(T.TreeRoot());
	             cin.get();
                 break;

                 case 8 :
                 cout<<"层序输出所创建的树"<<endl;
                 T.printInLevel(T.TreeRoot());
                 cin.get();
                 break;
                 
                 case 9 :
                 cout<<"删除创造的二叉树"<<endl;
                 T.delete_tree(T.TreeRoot());
                     cout<<"删除成功"<<endl;
                 cin.get();
                 return 0;
                 break;
            }
        }
        system("CLS");
        return 0;
}