// it is a divide and conquer method
#include <iostream>
using namespace std;

int partitionIndex(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the pivot element
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1) // Compare with pivot value, not index
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) // Compare with pivot value, not arr[pivot]
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]); // Place pivot in correct position
    return j;               // Return the pivot index
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIdx = partitionIndex(arr, low, high); // Call partition function
        quickSort(arr, low, partitionIdx - 1);             // Sort left subarray
        quickSort(arr, partitionIdx + 1, high);            // Sort right subarray
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1); // Call quickSort
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
