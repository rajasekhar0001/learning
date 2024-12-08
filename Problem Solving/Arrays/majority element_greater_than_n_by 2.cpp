/**
 * Using Moore's voting algorithm
 */

#include <bits/stdc++.h>

using namespace std;

int findCandidate(int *arr, int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            res = i;
            count = 1;
            cout << "index : " << i << "  ele : " << arr[res] << endl;
        }
    }
    return arr[res];
}

bool isMajority(int *arr, int n, int candidate)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            count++;
    }
    return count > n / 2; // majority element whose frequency is greater than n/2 timess
}

int main()
{
    int arr[] = {1, 3, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int candidate = findCandidate(arr, n);
    if (isMajority(arr, n, candidate))
    {
        cout << "Element " << candidate << " occurs more than " << n / 2 << " times" << endl;
    }
    else
    {
        cout << "No element occurs more than " << n / 2 << " times" << endl;
    }
    return 0;
}