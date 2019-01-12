//
// Created by yanpan on 2019/1/11.
//

#if 0
#include <stdio.h>

//进行堆调整
void MaxHeap_Adjust(int *arr, int start, int len)
{
    int temp;
    int left;
    while((left = start * 2 + 1) <= len)  //判断当前节点有无孩子节点
    {
        int right = left + 1;
        int j = left;
        if (right <= len && arr[right] >= arr[left])  //如果有右孩子找到最大的孩子节点
        {
            ++j;        //如果右孩子最大则对j加一，下标挪到最大的孩子节点
        }
        //判断父节点是否大于子节点中最大的节点，如果小于将与最大的孩子节点进行值交换
        if (arr[j] > arr[start])
        {
            temp = arr[start];
            arr[start] = arr[j];
            arr[j] = temp;
        }
        //如果父节点大于孩子节点则退出循环
        else
            break;
        //调整完成后将 孩子节点的下标赋值给 start，继续判断调整过后的子节点是否是大于它的孩子节点
        start = j;
    }
}

void MaxHeap_Sort(int *arr, int len)
{
    //建立大根堆
    for(int start = (len - 1) / 2; start >= 0; start--)
        MaxHeap_Adjust(arr,start,len);

    //取出最大的数字，并进行堆调整
    int temp;
    while(len >= 0)
    {
        //将堆顶元素与尾元素进行交换后 尾元素是堆中最大的元素
        temp = arr[0];
        arr[0] = arr[len];
        arr[len] = temp;
        //交换元素后，将长度减一
        len--;
        //再次对堆进行调整
        MaxHeap_Adjust(arr, 0, len);
    }
}

void Show(int *arr, int len)
{
    int i = 0;
    while(i < len)
    {
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 40, 22, 2, 66, 3, 45, 56, 390, 453, 223, 99};
    int len = sizeof(arr)/sizeof(arr[0]);
    MaxHeap_Sort(arr, len-1);
    Show(arr,len);
    return 0;
}
#endif