//
// Created by yanpan on 2019/1/7.
//

#include <stdio.h>
#include <stdbool.h>

bool Bubble_Sort(int *arr,int len)
{
    if(len <= 0)
        return false;
    int i = 0;
    int j = 0;
    int temp = 0;
    for(; i<len-1; ++i)
    {
        for(j=i+1; j<len; ++j)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return true;
}

void Show(int *arr,int len)
{
    if(len <= 0)
        return;
    int i = 0;
    while(i < len)
    {
        printf("%d",arr[i]);
        ++i;
    }
    printf("\n");
}

int main()
{
    int arr[6] = {3,5,4,2,1,6};
    Bubble_Sort(arr,sizeof(arr)/sizeof(arr[0]));
    Show(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}