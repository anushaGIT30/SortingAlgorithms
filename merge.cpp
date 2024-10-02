
// merge sort using pointers approach
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int l, int h)
{
    int mid = (l + h) / 2;
    vector<int> temp;
    int left = l;
    int right = mid + 1;
    while (left <= mid && right <= h)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if there is any element remaing then we can add using this condition
    // if it is on left copy them
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if it is on the right copy them
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // all the elemnts aare in the temporary array but we have to put them in the original array using low &high
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
}
void Mergesort(vector<int> &arr, int l, int h)
{
    int mid = (l + h) / 2;
    if (l >= h)
    {
        return;
    }
    Mergesort(arr, l, mid);
    Mergesort(arr, mid + 1, h);
    merge(arr, l, h);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// tc:nlog(n)
// sc:o(n)