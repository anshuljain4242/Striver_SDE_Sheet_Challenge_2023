#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
    // OPTIMAL 1

    int left = m-1;
    int right = 0;

    while(left >=0 && right < n)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.begin() + m);
    sort(arr2.begin(), arr2.end());
	int j=0;
    for(int i=m; i<m+n; i++)
    {
       		arr1[i] = arr2[j++];
    }
    return arr1;

    // OPTIMAL 2

    // int len = m+n;
    // int gap = ceil(len/2); // len/2 + len%2

    // while(gap > 0)
    // {
    //     int left = 0;
    //     int right = left + gap;
    //     while(right < len)
    //     {
    //         // arr1 and arr2
    //         if(left < m && right >= m)
    //         {
    //             if(arr1[left] > arr2[right-m])
    //                 swap(arr1[left], arr2[right-m]);
    //         }
    //         // arr2 and arr2
    //         else if(left >= m)
    //         {
    //             if(arr2[left-m] > arr2[right-m])
    //                 swap(arr2[left-m], arr2[right-m]);
    //         }
    //         // arr1 and arr1
    //         else
    //         {
    //             if(arr1[left] > arr1[right])
    //                 swap(arr1[left], arr1[right]);
    //         }
    //         left++, right++;
    //     }
    //     if(gap == 1) break;
    //     gap = ceil(gap/2);
    // }
    //     int idx = 0;
    //     for(int i=m; i<len; i++)
    //     {
    //         arr1[i] = arr2[idx++];
    //     }
    // return arr1;
}