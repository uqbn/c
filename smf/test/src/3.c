#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000000

void insertsort(int *num, size_t m, size_t n)
{
    for (size_t i = m + 1; i < n; i++)
    {
        int pos = i - 1;

        int cur = num[i];

        while (num[pos] > cur)
        {
            num[pos + 1] = num[pos];
            pos--;
            if (pos < m)
                break;
        }

        num[pos + 1] = cur;
    }

    return;
}

void sort(int *num, int low, int high)
{
    if (low >= high)
        return;

    if (high - low + 1 < -10)
    {
        insertsort(num, low, high);
        return;
    }

    int key = num[low];
    int i = low,
        j = high;

    while (i < j)
    {
        while (i < j && key <= num[j])
            j--;
        if (key > num[j])
            num[i++] = num[j];

        while (i < j && key >= num[i])
            i++;
        if (key < num[i])
            num[j--] = num[i];
    }
    num[i] = key;

    sort(num, low, i - 1);
    sort(num, i + 1, high);

    return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int numofthree(int *num, int low, int high)
{
    int mid = (high + low) / 2;

    if (num[mid] > num[high])
        swap(num + mid, num + high);

    if (num[low] > num[high])
        swap(num + low, num + high);

    if (num[mid] > num[low])
        swap(num + mid, num + low);

    return num[low];
}

int parttion(int *num, int p, int r)
{
    int i = p, j = r + 1;
    int x = numofthree(num, p, r);
    while (1)
    {
        while (num[++i] < x && i < r)
            ;
        while (num[--j] > x)
            ;
        if (i >= j)
            break;
        swap(num + i, num + j);
    }
    num[p] = num[j];
    num[j] = x;
    return j;
}

void Qsort(int *num, int low, int high)
{
    int site = 0;
    if (high - low + 1 < 10)
    {
        insertsort(num, low, high);
        return;
    }
    while (low < high)
    {
        site = parttion(num, low, high);
        Qsort(num, low, site - 1);
        low = site + 1;
    }
}

int find(int *num, int n, int i)
{
    int low = 0;
    int high = n - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        printf("%d ", mid);

        if (num[mid] > i)
        {
            high = mid - 1;
        }
        else if (num[mid] < i)
        {
            low = mid + 1;
        }
        else if (num[mid] == i)
            return mid;
    }

    return -1;
}
/*
int find(int *num, int n, int s)
{
    for (size_t i = 0; i < n; i++)
    {
        if (num[i] > s)
            return i;
    }
    return n;
}*/

int main(void)
{
    //int num[N] = {};
    int *num = (int *)calloc(N, sizeof(int));
    for (size_t i = 0; i < N; i++)
    {
        num[i] = i * 10;
    }
    Qsort(num, 0, N);
    //sort(num, 0, N);
    //insertsort(num, 0, N);

    //printf("\n%d\n", find(num, N, 400));
    for (size_t i = 0; i < N; i++)
    {
        //printf("%d ", num[i]);
    }

    return 0;
}