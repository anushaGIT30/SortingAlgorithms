#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int l1 = mid - start + 1;
    int l2 = end - mid;

    // creating 2 arrays
    int *firstarr = new int[l1];
    int *secondarr = new int[l2];

    // copying values to both arrays
    int mainArrayIndex = start;
    for (int i = 0; i < l1; i++)
    {
        firstarr[i] = arr[mainArrayIndex++];
    }
    int k = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        secondarr[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    // merging the two arrays
    while (index1 < l1 && index2 < l2)
    {
        if (firstarr[index1] < secondarr[index2])
        {
            arr[mainArrayIndex++] = firstarr[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = secondarr[index2++];
        }
    }

    // copying the remaining elements
    while (index1 < l1)
    {
        arr[mainArrayIndex++] = firstarr[index1++];
    }
    while (index2 < l2)
    {
        arr[mainArrayIndex++] = secondarr[index2++];
    }

    // deallocate dynamic arrays
    delete[] firstarr;
    delete[] secondarr;
}

void Mergesort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    // left part sorting
    Mergesort(arr, start, mid);

    // right part sorting
    Mergesort(arr, mid + 1, end);

    // merging the sorted parts
    merge(arr, start, end);
}

int main()
{
    int n;
    cin >> n;

    // dynamically allocating array
    int *arr = new int[n];

    // input elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // performing merge sort
    Mergesort(arr, 0, n - 1);

    // output sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deallocate dynamic array
    delete[] arr;

    return 0;
}
