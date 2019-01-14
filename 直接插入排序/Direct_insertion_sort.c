//
// Created by yanpan on 2019/1/14.
//

//时间复杂度为O(N2)  从小到大排序
//思想：将数组的元素一个一个的进行插入，i=0时只有一个元素，有序，i=1，将arr[1]插入到arr[0]前后
//依次到n-1，则数组有序，最好的情况时间复杂度为O(N)

#if 0
#include <stdio.h>
//#include <iostream>
//using namespace std;

void Direct_Insert_Sort(int *arr, int len)
{
    if(arr == NULL || len < 0)
        return;
    int i = 1;
    int j,k;
    //从头开始插入元素
    while(i <= len)
    {
        //找到第一个比要插入元素小的元素
        for(j = i - 1; j >= 0; j--)
        {
            //找到该元素后跳出
            if(arr[j] <= arr[i])
                break;
        }

        int temp = arr[i];
        if(k != i-1)
        {
            //挪动元素插入到合适位置
            for(k = i-1; k > j; k--)
                arr[k+1] = arr[k];
            arr[k+1] = temp;
        }
        //当插入元素大于最后一个元素则直接i++，不用进行其他的插入操作
        i++;
    }
}

void show(int *arr,int len)
{
    if(arr == NULL || len<= 0)
        return;
    int i = 0;
    while(i < len)
    {
        printf("%d ",arr[i]);
        ++i;
    }
    printf("\n");
    return;
}




void test0()
{
    int arr[] = {2, 3, 5, 6, 8, 4, 9, 0, 7, 1, 19, 22, 3, 44, 55, 61, 23, 43, 345, 443, 667};
    int  len = sizeof(arr) / sizeof(arr[0]);
    Direct_Insert_Sort(arr, len-1);
    show(arr,len);
}

void test1()
{
    int arr[] = {2,3,1,12};
    int  len = sizeof(arr) / sizeof(arr[0]);
    Direct_Insert_Sort(arr, len-1);
    show(arr,len);
}

void test2()
{
    int arr[] = {};
    int  len = sizeof(arr) / sizeof(arr[0]);
    Direct_Insert_Sort(arr, len-1);
    show(arr,len);
}
int main()
{
    test0();
    test1();
    test2();
    return 0;
}
#endif


//直接插入排序的其他写法
#if 0
void Direct_Insert_Sort1(int *arr, int len)
{
    if(arr == NULL || len < 0)
        return;
    int i = 1;
    int j;
    while(i <= len)
    {
        if(arr[i-1] > arr[i])
        {
            int temp = arr[i];
            for(j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
        i++;
    }
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Direct_Insert_Sort2(int *arr, int len)
{
    if(arr == NULL || len < 0)
        return;
    int i = 1;
    int j;
    while(i <= len)
    {
        if(arr[i-1] > arr[i])
        {
            for(j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
        i++;
    }
}
#endif