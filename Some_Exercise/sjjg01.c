#include<stdio.h>
#include<stdlib.h>
#define Llength  100
typedef int ElemTy;
typedef struct//��ʼ�����Ա�ĺ���
    {
        ElemTy *Elem;
        int length ;
    }sqlist;
void initialList(sqlist *L);//��ֵ

void chaji(sqlist *l1,sqlist *l2,sqlist *l3);//�������Ա�

void showlist(sqlist *l);//չʾ���Ա��Ԫ�غͳ���

void bingji(sqlist *l , sqlist *l1 ,sqlist *l2);//�������Ա�Ĳ���

void jiaoji(sqlist *l1 , sqlist *l2 ,sqlist *l3);//�������Ա�Ľ���

void findloc(sqlist *l, int x);//����һ����Ȼ��Ӱ��˳��ṹ�Ҳ������ظ�������xΪ�����������

int orderanddel(sqlist *l);//������ɾ���ظ�Ԫ��

void orderedlistjiao(sqlist *l1 , sqlist *l2 , sqlist *l3);//������˳������Ա���
// void charushu(sqlist *l , int x , int n ); ������� ����orderedlistjiao�ϲ�
    int createList(sqlist *L){
        L->Elem = (ElemTy*)malloc(Llength*sizeof(ElemTy));//��ʼ�������ڴ�
        if(!L->Elem)
        {
            return -1;
        }
        else{
            return 1;
        }
    }



    void initialList(sqlist *L)//�����Ա���и�ֵ
    {
           int n = 0;
           printf("�������Ա���");
           scanf("%d",&n);
           L->length=n;
           printf("�������Ա��Ԫ��");
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
        for (int i =0 ; i<l1->length;i++)//�����Ա�1��ֵ����l3
        {
            l3->Elem[i]=l1->Elem[i];
        }
        k = l1->length;
        for(int j = 0 ; j<l2->length ; j++)
        {
            int m = 0;
            while(m<l1->length&&l2->Elem[j]!=l1->Elem[m])
            {
                m++;//�����Ƿ��в���ȵ���
            }
            if(m==l1->length)//��������l��
            {
                l3->Elem[k] = l2->Elem[j];
                k++;
            }
            l3->length = k;//��ֵ�³���
        }
    }



    void jiaoji(sqlist *l1 , sqlist *l2 ,sqlist *l3)
    {
        int  k = 0;
        for(int i = 0 ; i<l1->length;i++)//��l1��ֵ��l3
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

void  findloc(sqlist *l , int x )//����������ȻΪ���� �Ҳ������ظ�����
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
        printf("�����Ա�������Ҫ���������\n");
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
        printf("����Ϊ%d",l->length);
    }


int orderanddel(sqlist *l1)
{
  int icount = 0;                                     //��¼�ƶ�Ԫ�ش���  
    if (l1->length > 1)   
{ 
     //ɾ����ı������ٴ���һ��Ԫ�أ�����index������¼���������еõ��Ĳ�ͬԪ�صĸ���
        int index = 1;         
          
        for (int i = 1; i < l1->length; i++)  
        {   
//ѭ������ԭ˳����ҳ���ͬԪ�أ����Ƶ������Ӧλ��  
            if (l1->Elem[i] != l1->Elem[index - 1] && i != index)      
            {  
                l1->Elem[index++] = l1->Elem[i];    //ԭ���е�index����ͬԪ�����±��е������±꼴Ϊ��index-1��
                icount++;  
            }  
            else if (l1->Elem[i] != l1->Elem[index - 1] && i == index)  
            {  
                l1->Elem[index++] = l1->Elem[i];  
            }  
        }  
        l1->length = index;                              //�±�ĳ��ȼ�Ϊindex  
        return  icount;  
    }  
    if (l1->length < 2)  
    {  
        return icount;  
    }  
    }



void orderedlistjiao(sqlist *L1, sqlist *L2, sqlist *L3)
{
int ia = 0, ib = 0, ic = 0;                         //ȡA��B��C������Ԫ�ص������±�
	while(ia < L1->length && ib < L2->length)         //ͬʱ����A��B��ÿ��ֻ��������е�һ��Ԫ��ֱ��������һ�������
	{
		if (L1->Elem[ia] > L2->Elem[ib])                //A����Ԫ�ؽϴ���B��Ԫ�غ���
		{
			ib++;
		}
		else if (L1->Elem[ia] < L2->Elem[ib])           //B����Ԫ�ؽϴ���A��Ԫ�غ���
		{
			ia++;
		}
		else
		{
			L3->Elem[ic] = L1->Elem[ia];                //�������д�ʱԪ����ͬ�򽫸�Ԫ�ش���C����
			ia++;                                       //����ҪԪ�غ���
			ib++;
			ic++;
		}
	}
	L3->length = ic;                                  //C��Ԫ���ƶ�������Ϊ��ĳ���
}


int main(void){
    sqlist l , l1 , l2;
    int x = 3;
    createList(&l);
    createList(&l1);
    createList(&l2);
    printf("�������Ա�\n");
    initialList(&l);
    // initialList(&l1);
    // initialList(&l2);
   printf("��ʼ�����Ա�\n");



//    chaji(&l,&l1,&l2); �
//  bingji(&l,&l1,&l2); ����
// jiaoji(&l,&l1,&l2);������locate������
// int m = findloc(&l, x);
// charushu(&l,x, m);

int m =  orderanddel(&l);
printf("%d",m);
   showlist(&l);
    return 0;
}