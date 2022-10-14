#include"CreateTree.h"
#include"Cfunction.h"
#include<cstdlib>
int main()
{
    int choose ;
    char fileName[100];
    csNode *T;
    pTree T1;
    int high , degree , leafNum;
    while(true)
    {
    cout<<"*************************************************"<<endl;
    cout<<"0退出并销毁森林"<<endl;
    cout<<"1数据文件创建森林"<<endl;
    cout<<"2按先序、后序、层次遍历森林"<<endl;
    cout<<"3求森林的高度"<<endl;
    cout<<"4求森林叶子结点数"<<endl;
    cout<<"5求森林的度"<<endl;
    cout<<"6先序输出结点值及其层次号"<<endl;
    cout<<"7输出广义表表示的树"<<endl;
    cout<<"*************************************************"<<endl;
    cin>>choose;
    cin.get();
    switch(choose)
    {
        case 0 :
        destory_tree(T);
        cout<<"删除完毕,程序退出"<<endl;
        return 0;
        break;
        
        case 1 :
        cout<<"请输入文件名称"<<endl;
        cin>>fileName;
        if(CreateTreeFromFile(fileName, T1))
        {
             cout<<"数据处理完毕！"<<endl;
        }
        createCsTree(T,T1);
        cin.get();
        break;
        
        case 2 :
        preOrderprint(T);
        cout<<"先序遍历"<<endl;
        postOrderprint(T);
        cout<<"后序遍历"<<endl;
        printbylevel(T);
        cout<<"层序遍历"<<endl;
        cin.get();
        break;

        case 3 :
        // high = Get_Height_Forest(T);
        high = Height(T);
        cout<<"该森林的高度为："<<high<<endl;
        cin.get();
        break;

        case 4 :
        Num_of_leaf(T,leafNum);
        cout<<"该树的叶子总数为"<<leafNum<<endl;
        cin.get();
        break;

        case 5 :
        degree = degreeOfForest(T);
        cout<<"该树的度为"<<degree<<endl;
        cin.get();
        break;

        case 6 :
        cout<<"先序输出并输出层次号"<<endl;
        PreOrderprint_level(T,1);
        cin.get();
        break;;

        case 7 :
        cout<<"广义表表示的树为"<<endl;
        PutWlist(T);
        cin.get();
        break;
    
    }
    }
    system("CLS");
    return 0;
}