#include <iostream>
using namespace std;
void insertionsort(int n, int arr[], int j)
{
    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
        }
    }
    return insertionsort(n, arr, j - 1);
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
    insertionsort(n, arr, 1);
    printArray(n, arr);
}
