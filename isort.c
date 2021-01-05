#include <stdio.h>
#define NUM 50

void print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if(i != len-1){
            printf("%d,", *arr);
            arr++;
        }
        else
        {
            printf("%d", *arr);
            arr++;
        }
        
    }
    printf("\n");
}

void shift_element(int *arr, int i)
{
    int k;
    for (k = *(arr+i); (arr+i) > arr && *(arr+i-1) > k; i--)
    {
        *(arr+i) = *(arr+i-1);
    }
    *(arr+i) = k;
    
}


void insertion_sort(int* arr, int len)
{
    for (int i=1; i<len; i++)
    {
        if(*(arr+i) < *(arr+i-1)) {
            shift_element(arr, i);
        }
    }
    
}

int main()
{
    int arr[NUM] = {0};
    int len = NUM;
    for (int i=0; i<len; i++)
    {
        scanf("%d", arr+i);
    }
    insertion_sort(arr, len);
    print_arr(arr, len);
    
    return 0;
}
