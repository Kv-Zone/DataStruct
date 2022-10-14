#include"LinkList.h"
#include<cstdlib>
#include<cstdio>

LinkList l;

void task1(){
    if(l.get_head()){
        l.show();
    }
    else{
        cout<<"链表为空！请先创建链表。\n";
    }
    cin.get();
    cin.get();
}

void task2(){
    l.initial();
    cout<<"尾插法创建链表\n";
    l.insertR();
    cout<<"创建结果：";
    l.show();
    cin.get();

}

void task3(){
    l.destroy();
    cout<<"销毁成功！\n";
    cin.get();
    cin.get();
}

void task4(){
     l.show();
     cout<<"链表长度："<<l.getlength()<<endl;
     cin.get();
     cin.get();
}

void task5(){
    int i;
    elementType x;
    cout<<"插入前: ";
    l.show();
    cout<<"输入位置序号i和插入值x:";
    cin>>i>>x;
    l.insert(i,x);
    cout<<"插入后：";
    l.show();
    cin.get();
    cin.get();
}

void task6(){
    int i;
    cout<<"删除前：";
    l.show();
    cout<<"输入删除的元素序号：";
    cin>>i;
    if(l.delete_num(i)){
        cout<<"删除后：";
        l.show();
    }
    cin.get();
    cin.get();
}

void task7(){
    elementType x;
    cout<<"插入前：";
    l.show();
    cout<<"输入要插入的元素值x:";
    cin>>x;
    l.insertA(x);
    cout<<"插入后：";
    l.show();
    cin.get();
    cin.get();

}

void task8(){
    l.decompose_odd_even();
    cin.get();
    cin.get();
}

void task9(){
    LinkList L2,L3;
    cout<<"原表L1:";
    l.show();
    cout<<"创建表L2:";
    L2.initial();
    L2.insertR();
    L3=l.intersect(L2);
    cout<<"表L3:";
    L3.show();
    cin.get();
    cin.get();
    L2.destroy();
    L3.destroy();

}

void task10(){
    cout<<"去重前："<<endl;
    l.show();
    l.unique();
    cout<<"去重后: "<<endl;
    l.show();
    cin.get();
    cin.get();
}

void task11(){
    LinkList L2;//先创建表2 初始化
    cout<<"请输入L2数据"<<endl;
    L2.initial();
    L2.insertR();
    cout<<"表L1:"<<endl;
    l.show();
    cout<<"表L2:"<<endl;
    L2.show();
    l.merge(L2);
    cout<<"合并后:"<<endl;
    l.show();
    cin.get();
    cin.get();
}
int main(){
    while(true){
        int choose;
        cout<<"********************************************************测试菜单******************************************************\n";
        cout<<"1.打印链表\n";
        cout<<"2.尾插法创建单链表，打印创建结果。\n";
        cout<<"3.销毁单链表。\n";
        cout<<"4.求链表长度。\n";  
        cout<<"5.任务<1>:在第i个结点插入值为x的结点。\n";
        cout<<"6.任务<2>:删除单链表中第i个元素结点。\n";
        cout<<"7.任务<3>:在一个递增有序的单链表L中插入一个值为x的元素,并保持其递增有序特性。\n";
        cout<<"8.任务<4>:将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的单链表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。\n";
        cout<<"9.任务<5>:求两个递增有序单链表L1和L2中的公共元素,放入新的单链表L3中。\n";
        cout<<"10.任务<6>:删除递增有序单链表中的重复元素，要求时间性能最好。\n";
        cout<<"11.任务<7>:递增有序单链表L1、L2,不申请新结点,利用原表结点对2表进行合并,并使得合并后成为一个集合,合并后用L1的头结点作为头结点,删除L2的头结点,要求时间性能最好。\n";;
        cout<<"输入序号以测试：";
        cin>>choose;
        switch(choose){
            case 1:   task1();break;
            case 2:   task2();break;
            case 3:   task3();break;
            case 4:   task4();break;
            case 5:   task5();break;
            case 6:   task6();break;
            case 7:   task7();break;
            case 8:   task8();break;
            case 9:  task9();break;
            case 10:  task10();break;
            case 11:  task11();break;
            default: break;
        }
        system("CLS");
    }
    return 0;
}