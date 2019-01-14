//
// Created by yanpan on 2019/1/12.
//

//运用分治法的思想，将数组以中心坐标点分成两部分，左右两边的数组继续以它们的中心进行分组
// 直到数组只有一个元素时递归返回，进行排序
//两个有序的数组合并为一个有序的数组


#include <stdio.h>
#include <stdlib.h>

//以mid为中心对两边元素比较后进行排序，brr是额外申请的资源
void MergeArr(int *arr, int start, int mid, int len, int *brr)
{
    if(arr == NULL)
        return;
    int i = start, k = 0;
    int j = mid+1;
    //将相邻的两个有序的序列合并为一个有序的序列
    while(i <= mid && j <= len)
    {
        if(arr[i] >= arr[j])
            brr[k++] = arr[j++];
        else
            brr[k++] = arr[i++];
    }
    //哪个有序序列在另一个序列合并完成后还有元素，直接将该元素按照原序添加到数组中
    while(i <= mid)
        brr[k++] = arr[i++];
    while(j <= len)
        brr[k++] = arr[j++];

    //最后将brr数组中排好序的元素赋给arr
    i = 0;
    while(i < k)
    {
        arr[start + i] = brr[i];
        i++;
    }
}
//归并排序
void MergeSort(int *arr, int start, int len, int *brr)
{
    int mid = (start + len) >> 1;
    if(arr == NULL)
        return;

    //进行递归，直到小数组只有一个元素的时候递归结束
    if(start < len)
    {
        MergeSort(arr, start, mid, brr);
        MergeSort(arr, mid+1, len, brr);
        MergeArr(arr, start, mid, len, brr);
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
    int len = sizeof(arr)/sizeof(arr[0]);
    int first = 0;
    int *brr = (int *)malloc(sizeof(int)*len);
    MergeSort(arr, first, len-1, brr);
    free(brr);
    show(arr,len);
}

void test1()
{
    int arr[] = {2, 1, 1, 2, 2, 3, 5, 6, 7, 3, 2, 1, 8, 9, 7, 4, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int first = 0;
    int *brr = (int *)malloc(sizeof(int)*len);
    MergeSort(arr, first, len-1, brr);
    free(brr);
    show(arr,len);
}

void test2()
{
    int arr[] = {2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int first = 0;
    int *brr = (int *)malloc(sizeof(int)*len);
    MergeSort(arr, first, len-1, brr);
    free(brr);
    show(arr,len);
}

void test3()
{
    int arr[] = {};
    int len = sizeof(arr)/sizeof(arr[0]);
    int first = 0;
    int *brr = (int *)malloc(sizeof(int)*len);
    MergeSort(arr, first, len-1, brr);
    free(brr);
    show(arr,len);
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    return 0;
}
