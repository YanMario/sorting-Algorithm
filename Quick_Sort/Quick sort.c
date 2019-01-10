//
// Created by yanpan on 2019/1/9.
//

#if 1
#include <stdio.h>

//写法一： 好理解一点
//找到基数，并进行填坑调整位置，使得调整后的数组在基数右边的数字元素小于基数，左边反之
int AdjustArr(int *arr,int left, int right)
{
    //对参数进行判断，防止对空数组进行操作
    if(arr == NULL || left < 0 || right <= 0 || left > right)
        return -1;
    int i = left;
    int j = right;

    //基数 car_num
    int car_num = arr[left];
    while(i < j)
    {
        //从左边开始找，找到比基数小的元素 并将元素调整到右边的坑中
        while(i < j && arr[j] >= car_num)
            j--;
        if(i < j)
        {
            arr[i] = arr[j];
            //调整之后要将右边 i 的位置进行加一调整
            i++;
        }

        //从左边找完之后，再从右边开始找，找到比基数大的元素 并将元素调整到左边的坑中
        while(i < j && arr[i] <= car_num)
            i++;
        if(i < j)
        {
            arr[j] = arr[i];
            //调整之后将左边 j 的位置进行减一操作
            j--;
        }
    }

    //将基数填到 i 的位置
    arr[i] = car_num;
    return i;
}

//递归函数进行排序 分治算法的思想
void Quick_Sort(int *arr, int left, int right)
{
		if(arr == NULL || left < 0 || right <= 0 || left>right)
				return;
    //递归完成之后一层一层返回
    if(left < right)
    {
        int i = AdjustArr(arr, left, right);
        Quick_Sort(arr, left, i - 1);
        Quick_Sort(arr, i + 1, right);
    }
}

//写法二：代码更简洁

void Quick_Sort1(int *arr, int left, int right)
{
    if(arr == NULL)
        return;
    if(left < right)
    {
        int i = left, j = right, car_num = arr[left];
        while(i < j)
        {
            while(i < j && arr[j] > car_num)
                j--;
            if(i < j)
            {
                arr[i++] = arr[j];
            }

            while(i < j && arr[i] < car_num)
                ++i;
            if(i < j)
            {
                arr[j--] = arr[i];
            }

        }
        arr[i] = car_num;
        Quick_Sort1(arr,left,i-1);
        Quick_Sort1(arr,i+1,right);
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



int main()
{
    int arr[10] = {72,6,57,88,60,42,83,73,48,85};
    int right = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    Quick_Sort1(arr, left, right-1);
    show(arr,right);
    return 0;
}

#endif
