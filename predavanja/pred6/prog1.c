#include <stdio.h>
#include <stdlib.h>
// iterative
void sort1(int nums[],const int len)
{
    for (int i = 0; i < len; i++)
    {
        int idxMin = i;
        for (int j = i + 1; j < len; j++)
            if (nums[j] < nums[idxMin]) idxMin = j;
        const int temp = nums[i];
        nums[i] = nums[idxMin];
        nums[idxMin] = temp;

    }
}

//sort1 sam za recursion
void sort2(int arr[],const int len, int ordered_len)
{
    if (ordered_len == len) return;
    int min_idx = ordered_len;
    for (int i = ordered_len + 1; i < len; i++)
        if (arr[i] < arr[min_idx]) min_idx = i;
    const int temp = arr[ordered_len];
    arr[ordered_len] = arr[min_idx];
    arr[min_idx] = temp;
    return sort2(arr, len, ++ordered_len);
}

//med 2 in 3 je razlika, samo kko programsko napises
void sort3(int arr[], int len)
{
    if (len == 1) return;
    int min_idx = 0;
    for (int j = 1; j < len; j++)
        if (arr[j] < arr[min_idx]) min_idx = j;
    const int t = arr[0];
    arr[0] = arr[min_idx];
    arr[min_idx] = t;
    sort3(&(arr[1]), --len); //poslje sub array
}


int main(int argc, char *argv[])
{
    int arr[] = {5,4,3,2,1};
    sort3(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%2d", arr[i]);
    printf("\n");

}
