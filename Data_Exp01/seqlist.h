#pragma once

#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX 100

typedef int elementType;//elementType 为元素类型
typedef int Rank;//Rank 储存的元素序号
class seqList{
private:
    int length=0;
    elementType data[MAX]={0};
public:
    void randInit(int n);//自动填入参数
    int getLength();//获取长度
    Rank search(elementType x);//找到不大于x的最后一位数字（升序）
    bool insert(Rank i,elementType x); //任务<1>,指定位置插入
    void insert1(elementType x);//尾插
    bool getElement(Rank i,elementType& x);//获取位于i的数值x 用于遍历线性表
    bool delete_num(Rank i);         //任务<2>，删除指定位置元素
    void insertA(elementType x); //任务<3>,递增有序的顺序表插入
    void decompose_odd_even();   //任务<4>，分解奇数项和偶数项
    seqList intersect(seqList const &L); //任务<5>， 求两个递增有序顺序表的公共元素，返回公共元素组成的顺序表 / C=A∩B
    int unique();               //任务<6>， 递增有序顺序表删除重复元素,返回移动次数
    // void mergeToSet(seqList const &L);  //拓展任务<1>
    // bool subSetJudge(seqList const &L); //拓展任务<3>
    // elementType finalTask(seqList const& L);//拓展任务<4>

};

int seqList::getLength()
    {
        return length;
    }


Rank seqList::search(elementType x){
    int lo=0,hi=length;
    while(hi>lo){
        Rank mi=(lo+hi)>>1;//右移取中值点
        if(data[mi]>x){
            hi=mi;
        }
        else{
            lo=mi+1;
        }
    }
    return --lo+1; //返回不大于x的最后一个元素序号
}

void seqList::insertA(elementType x )
{
    Rank i=search(x);
    insert(i+1,x);
}


bool seqList::getElement(Rank i,elementType& x){
    if(i>length||i<1){
        return false;
    }
    x=data[i-1];
    return true;
}

bool seqList::insert(Rank i, elementType x){
    if(i<1||i>length+1){
        cout<<"序号错误!\n"<<endl;//输入的序号非法
        return false;
    }
    for(int j=length-1;j>i-2;j--){
        data[j+1]=data[j];//进行插入位置i后的数字的后移
    }
    data[i-1]=x;//i位置赋值为x
    length++;//长度增加
    return true;
}

void seqList::randInit(int n){
    for(int i=0;i<n;i++){
        insert1(rand()%100);
    }
}
void seqList::insert1(elementType x){//尾部插入一个数字
    insert(length+1,x);
}

bool seqList::delete_num(Rank i){
    if(i>length||i<1){
        cout<<"序号错误！\n";
        return false; //序号非法，返回false
    }
    for(int j=i-1;j<length-1;j++){
        data[j]=data[j+1];
    }
    length--;//删除后长度-1
    return true; 
}


void seqList::decompose_odd_even(){
    seqList odd_L,even_L;
    for(int i=0;i<length;i++){
        if(data[i]%2){ //判断奇偶
            odd_L.insert1(data[i]);
        }
        else{
            even_L.insert1(data[i]);
        }
    }
    cout<<"former:";
    for(int i=0;i<length;i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;
    cout<<"odd:";
    for(int i=0;i<odd_L.length;i++){
        cout<<odd_L.data[i]<<' ';
    }
    cout<<endl;
    cout<<"even:";
    for(int i=0;i<even_L.length;i++){
        cout<<even_L.data[i]<<' ';
    }
    cout<<endl;

}

seqList seqList::intersect(seqList const& L){//取交集的最优算法(有顺序的表 双指针排序)
    Rank i=0,j=0;
    seqList Result;
    while(i<length&&j<L.length){
        if(data[i]<L.data[j]){
            i++;
        }
        else if(data[i]>L.data[j]){
            j++;
        }
        else if(data[i]==L.data[j]){
            Result.insert1(data[i++]);
        }
    }
    return Result;
}

int seqList::unique(){
    int count=0;
    if(length<=1) 
    return 0;
    int j=0;
    for(int i=1;i<length;i++){
        if(data[i]!=data[j]){
            data[++j]=data[i];
            if(i!=j) 
            count++;
        }
    }
    length=j+1;
    return count;
}