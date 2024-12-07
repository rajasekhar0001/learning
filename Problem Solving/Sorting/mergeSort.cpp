/**
 * Merge sort algorithm
 * Deviding the array using recursion and changing the original array by using two temporary arrays left and right
 * Dividing and Conquer technique
 * 
 * INversion count also performed : means if (arr[i] > arr[j]) if (i < j), increase inversionCOunt by 1
 * 
 * T.C: O(n logn)
 * S.C: O(n) // Extra space is used
 * Add a point: If you dont want me to change original array, will use a copy of that
 */

/**
 * FOr only merge Sort: remove cnt
 */

#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    int mergeSort(vector<int> &arr, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        int cnt = 0;
        int mid = left + (right - left) / 2;
        cnt += mergeSort(arr, left, mid);
        cnt += mergeSort(arr, mid + 1, right);
        cnt += merge(arr, left, mid, right);
        return cnt;
    }

    int merge(vector<int> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int cnt = 0;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            R[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])   // if teh element is samller or equal
            {
                arr[k++] = L[i++];
            }
            else // element is large
            {
                arr[k++] = R[j++];
                cnt += (n1 - i); // Count inversions // for the purpose of inversion count
            }
        }

        while (i < n1)
        {
            arr[k++] = L[i++];
        }

        while (j < n2)
        {
            arr[k++] = R[j++];
        }
        return cnt;
    }

    void printArr(vector<int> arr, int n) {
        for (int i=0;i<n;i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }
};

int main()
{
    A obj;
    vector<int> arr = {5, 1, 24, 5, 3};
    int invCount = obj.mergeSort(arr, 0, 4);
    obj.printArr(arr, 5);
    cout << invCount << endl;
}