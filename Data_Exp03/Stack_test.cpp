#include"LinkedStack.h"
#include"SeqStack.h"
#include<cstdlib>
using namespace std;

int main()
{

    while(true){
        cout<<"********************************************\n";
        cout<<"顺序栈\n";
        cout<<"1.顺序栈实现十进制数字转化为n进制的(2=<n<=32)\n";
        cout<<"2.顺序表实现判断表达式括号是否匹配的问题\n";
        cout<<"3,顺序栈实现输出所有合法的输出序列和其个数\n";
        cout<<"链栈\n";
        cout<<"4.链栈实现十进制数字转化为n进制的(2=<n<=32)\n";
        cout<<"5.链表实现判断表达式括号是否匹配的问题\n";
        cout<<"6.链表实现输出所有合法的输出序列和其个数\n";
        cout<<"7.判断序列是否为合法输出序列"<<endl;
        cout<<"8.结束程序"<<endl;
        cout<<"********************************************\n";
        cout<<"输入序号进行测试"<<endl;
        int x ,n , icount=0; 
        string ans;
        char exp[100];//储存判断的表达式
        int exp1[100], exp2[100];
        int raw , base;
        cin>>x;
        int m=0 , k=0 ;    
        seqStack Ss;
        LinkedStack Ls ;
        switch(x)
        {
            case 1:
            cout<<"请输入原始数字"<<endl;
            cin>>raw;
            cout<<"请输入最后转化成的进制"<<endl;
            cin>>base;
            Ss.convert(raw, base);
            break;

            case 2:
            cout<<"请输入需要判断的表达式"<<endl;
            cin>>exp;
            cin.get();
            if(Ss.paren(exp))
            {
                cout<<"括号匹配"<<endl;
            }
            else
            {
                cout<<"括号不匹配"<<endl;
            }
            cin.get();
            break;

            case 3:
            Ss.inital();
                cout << "输入n即输入序列长度:" <<endl;
                cin >> n;
                cout<<"输入序列的入栈顺序"<<endl;
                for(int i=0 ; i<n ; i++)
                {
                    cin>>exp1[i];
                }
                cout << "所有合法输出序列为：" << endl;
                Ss.OutSequence( exp1 , exp2 , n , m , k);
                cout << "共" << Ss.SeqNum << "个" << endl;
                break;

            case 4:
              cout<<"请输入原始数字"<<endl;
            cin>>raw;
            cout<<"请输入最后转化成的进制"<<endl;
            cin>>base;
            Ls.convert(raw, base);
            break;

            case 5:
            cout<<"请输入需要判断的表达式"<<endl;
            cin>>exp;
            cin.get();
            if(Ls.paren(exp))
            {
                cout<<"括号匹配"<<endl;
            }
            else
            {
                cout<<"括号不匹配"<<endl;
            }
            cin.get();
            break;

            case 6:
            Ls.initial();
            cout<<"请输入序列长度"<<endl;
            cin>>n;
            cout<<"请输入入栈顺序序列"<<endl;
            for(int i = 0 ; i<n ; i++)
            {
                cin>>exp1[i];
            }
            cout<<"所有合法的输出序列为:"<<endl;
            Ls.Output(exp1, exp2, n, m, k);
            cout<<"共有"<<Ls.LinkNum<<"种输出序列"<<endl;
            break;
            
            case 7:
            Ss.inital();
            cout<<"请输入序列长度n"<<endl;
            cin>>n;
            cout<<"请输入需要判断的输出顺序"<<endl;
            for(int i = 0 ; i < n ; i++)
            {
                cin>>exp1[i];
            }
            if(Ss.stackPermutation(exp1, n))
            cout<<"输出序列合法"<<endl;
            else
            cout<<"输出序列不合法"<<endl;
            break;

            case 8:
            return 0 ;
        }

    } 
    system("CLS");
    return 0 ;
}
