#include <iostream>
using namespace std;
void selectionsortUsingRecursion(int arr[], int n, int i = 0)
{
    if (i >= n - 1)
    {
        return;
    }

    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    swap(arr[min], arr[i]);

    return selectionsortUsingRecursion(arr, n, i + 1);
}
void printArray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionsortUsingRecursion(arr, n);
    printArray(n, arr);
}