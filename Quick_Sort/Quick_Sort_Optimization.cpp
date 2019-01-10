//
// Created by yanpan on 2019/1/10.
//

#if 1
#include <iostream>
#include <stack>
using namespace std;


//返回三数中第二小的数的下标
int Mid_Num(int *arr, int i, int j)
{
    int mid = i + ((j-i)>>1);
    if(arr[i] >= arr[mid] && arr[i] >= arr[j])
    {
        if(arr[mid] >= arr[j])
            return mid;
        else
            return j;
    }
    if(arr[mid] >= arr[i] && arr[mid] >= arr[j])
    {
        if(arr[i] >= arr[j])
            return i;
        else
            return j;
    }
    if(arr[j] >= arr[mid] && arr[j] >= arr[i])
    {
        if(arr[mid] >= arr[i])
            return mid;
        else
            return i;
    }

}

//写法一： 好理解一点
//找到基数，并进行填坑调整位置，使得调整后的数组在基数右边的数字元素小于基数，左边反之
int AdjustArr(int *arr,int left, int right)
{
    //对参数进行判断，防止对空数组进行操作
    if(arr == NULL || left < 0 || right <= 0 || left > right)
        return -1;
    int i = left;
    int j = right;

    //防止复杂度达到最坏的情况，所以去了中数
    int mid = Mid_Num(arr,i,j);

    int car_num = arr[mid];
    arr[mid] = arr[i];
    arr[i] = car_num;
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

//非递归的快排,运用栈的特性  时间复杂度为O(N*log N)
void QuickSort(int *arr, int left, int right)
{
    //对参数进行判断，防止对空数组进行操作
    if(arr == NULL || left < 0 || right <= 0 || left > right)
        return;
    int i,j;
    stack<int> vec1;
    vec1.push(right);  //先右后左
    vec1.push(left);
    //栈空则跳出while循环，则整个数组排好顺序
    while(!vec1.empty())
    {
        i = vec1.top(); //left
        vec1.pop();
        j = vec1.top(); //right
        vec1.pop();
        if(i < j)
        {
            //找到中间的k值
            int k = AdjustArr(arr, i, j);
            if(k > i)
            {
                //将k下标左边的数组入栈然后进行排序
                vec1.push(k - 1);
                vec1.push(i);
            }
            if(k < j)
            {
                //将k下标左边的数组入栈然后进行排序
                vec1.push(j);
                vec1.push(k + 1);
            }

        }

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
    QuickSort(arr, left, right-1);
    show(arr,right);
    return 0;
}



#endif