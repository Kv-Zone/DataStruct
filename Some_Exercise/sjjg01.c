#include<stdio.h>
#include<stdlib.h>
#define Llength  100
typedef int ElemTy;
typedef struct//初始化线性表的函数
    {
        ElemTy *Elem;
        int length ;
    }sqlist;
void initialList(sqlist *L);//赋值

void chaji(sqlist *l1,sqlist *l2,sqlist *l3);//求两线性表差集

void showlist(sqlist *l);//展示线性表的元素和长度

void bingji(sqlist *l , sqlist *l1 ,sqlist *l2);//求两线性表的并集

void jiaoji(sqlist *l1 , sqlist *l2 ,sqlist *l3);//求两线性表的交集

void findloc(sqlist *l, int x);//插入一个数然后不影响顺序结构且不插入重复的数字x为被插入的数字

int orderanddel(sqlist *l);//排序并且删除重复元素

void orderedlistjiao(sqlist *l1 , sqlist *l2 , sqlist *l3);//两个有顺序的线性表求
// void charushu(sqlist *l , int x , int n ); 多余代码 可与orderedlistjiao合并
    int createList(sqlist *L){
        L->Elem = (ElemTy*)malloc(Llength*sizeof(ElemTy));//初始化分配内存
        if(!L->Elem)
        {
            return -1;
        }
        else{
            return 1;
        }
    }



    void initialList(sqlist *L)//对线性表进行赋值
    {
           int n = 0;
           printf("输入线性表长度");
           scanf("%d",&n);
           L->length=n;
           printf("输入线性表的元素");
        for(int i=0 ; i<L->length;i++)
        {
            scanf("%d",&n);
            L->Elem[i]=n;
        }
    }



    void chaji(sqlist *l1 , sqlist *l2, sqlist *l3){
        int k = 0;
        int j = 0;
        for(int i =0 ; i<l1->length;i++)
        {
            while(j<l2->length&&l2->Elem[j]!=l1->Elem[i])
            {
                j++;
                if(j==l2->length)
                {
                    l3->Elem[k]=l1->Elem[i];
                    k++;
                }
            }
        //   for(int j = 0 ; j<l2->length;j++)
        //   {
        //       if(l2->Elem[j]!=l1->Elem[i])
        //       {
        //           l3->Elem[k] = l1->Elem[i];
        //           k++;
        //           l3->length = k;
        //       }
        //   }
        }
        l3->length = k;
    }



    void bingji(sqlist *l1 , sqlist *l2 ,sqlist *l3){
        int k = 0 ;
        for (int i =0 ; i<l1->length;i++)//将线性表1的值赋给l3
        {
            l3->Elem[i]=l1->Elem[i];
        }
        k = l1->length;
        for(int j = 0 ; j<l2->length ; j++)
        {
            int m = 0;
            while(m<l1->length&&l2->Elem[j]!=l1->Elem[m])
            {
                m++;//查找是否有不相等的数
            }
            if(m==l1->length)//有数不在l中
            {
                l3->Elem[k] = l2->Elem[j];
                k++;
            }
            l3->length = k;//赋值新长度
        }
    }



    void jiaoji(sqlist *l1 , sqlist *l2 ,sqlist *l3)
    {
        int  k = 0;
        for(int i = 0 ; i<l1->length;i++)//将l1赋值给l3
        {
          for(int j = 0 ; j< l2->length;j++)
        {
            if(l2->Elem[j]==l1->Elem[i])
            {
                l3->Elem[k] = l2->Elem[j];
                k++;
            }
        } 
        }
        l3->length = k ;

    }

void  findloc(sqlist *l , int x )//插入数字仍然为升序 且不插入重复数字
{
    int m = 0;
    for(int i = 0 ; i <l->length;i++)
    {
        m++;
        if(x < l->Elem[i])
        {
            break;
        }
    }
    if(x == l->Elem[m-=2])
    {
        printf("本线性表已有需要插入的数字\n");
    }
    else{
    l->length++;
    for(int i = l->length-1 ; i>m-1 ;i--)
    {
        l->Elem[i] = l->Elem[i-1];
    }
    l->Elem[m-1] = x ;
    }
}

// void charushu(sqlist *l , int x , int m)
// {
//     l->length++;
    
//     for(int i = l->length-1 ; i>m-1 ;i--)
//     {
//         l->Elem[i] = l->Elem[i-1];
//     }
//     l->Elem[m] = x ;
// }

    void showlist(sqlist *l)
    {
        for(int i = 0; i< l->length;i++)
        {
            printf("%d\n",l->Elem[i]);
        }
        printf("长度为%d",l->length);
    }


int orderanddel(sqlist *l1)
{
  int icount = 0;                                     //记录移动元素次数  
    if (l1->length > 1)   
{ 
     //删除后的表中至少存在一个元素，定义index变量记录遍历过程中得到的不同元素的个数
        int index = 1;         
          
        for (int i = 1; i < l1->length; i++)  
        {   
//循环遍历原顺序表，找出不同元素，并移到表的相应位置  
            if (l1->Elem[i] != l1->Elem[index - 1] && i != index)      
            {  
                l1->Elem[index++] = l1->Elem[i];    //原表中第index个不同元素在新表中的数组下标即为（index-1）
                icount++;  
            }  
            else if (l1->Elem[i] != l1->Elem[index - 1] && i == index)  
            {  
                l1->Elem[index++] = l1->Elem[i];  
            }  
        }  
        l1->length = index;                              //新表的长度即为index  
        return  icount;  
    }  
    if (l1->length < 2)  
    {  
        return icount;  
    }  
    }



void orderedlistjiao(sqlist *L1, sqlist *L2, sqlist *L3)
{
int ia = 0, ib = 0, ic = 0;                         //取A、B、C表中首元素的数组下标
	while(ia < L1->length && ib < L2->length)         //同时遍历A、B表，每次只拿任意表中的一个元素直至其中有一表遍历完
	{
		if (L1->Elem[ia] > L2->Elem[ib])                //A表中元素较大则B表元素后移
		{
			ib++;
		}
		else if (L1->Elem[ia] < L2->Elem[ib])           //B表中元素较大则A表元素后移
		{
			ia++;
		}
		else
		{
			L3->Elem[ic] = L1->Elem[ia];                //若两表中此时元素相同则将该元素存入C表中
			ia++;                                       //三表都要元素后移
			ib++;
			ic++;
		}
	}
	L3->length = ic;                                  //C表元素移动次数即为表的长度
}


int main(void){
    sqlist l , l1 , l2;
    int x = 3;
    createList(&l);
    createList(&l1);
    createList(&l2);
    printf("创建线性表\n");
    initialList(&l);
    // initialList(&l1);
    // initialList(&l2);
   printf("初始化线性表\n");



//    chaji(&l,&l1,&l2); 差集
//  bingji(&l,&l1,&l2); 并集
// jiaoji(&l,&l1,&l2);或者有locate方法？
// int m = findloc(&l, x);
// charushu(&l,x, m);

int m =  orderanddel(&l);
printf("%d",m);
   showlist(&l);
    return 0;
}