#include <stdio.h>

#define ARR_LEN 50

/*
 * Shifts the next i elements in arr one spot to the "right". Assumes there is space for i+1 elements in the array. Overrides the n+1 element.
 */
void shift_element(int* arr, int i)
{
    for(int j = i; j > 0; j--)
    {
        *(arr+j) = *(arr+j-1);
    }
}

/*
 * An implementation of insertion sort.
 */
void insertion_sort(int* arr , int arr_len)
{
    int key = 0;
    for (int i = 1; i < arr_len; i++) {
        key = *(arr+i);

        int j = i - 1;
        while (0 <= j)
        {
            if (*(arr+j) < key)
                break;
            j--;
        }
        j++;
        shift_element(arr+j, i-j);

        *(arr+j) = key;
    }
}

int main()
{
    int mat[ARR_LEN];

    for (int i = 0; i < ARR_LEN; i++)
    {
        scanf("%d", (mat+i));
    }

    insertion_sort(mat, ARR_LEN);

    printf("%d", *(mat+0));
    for (int i = 1; i < ARR_LEN; i++)
    {
        printf(",%d", *(mat+i));
    }
}
