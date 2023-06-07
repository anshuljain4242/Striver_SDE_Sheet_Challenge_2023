#include <iostream>
#include <unordered_map>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    // Optimal
    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        // starting a new check
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
            cnt++;
        else
            cnt--;
    }
    // verifying if ele is the majority element or not
    int verifyCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            verifyCnt++;
    }

    if (verifyCnt > n / 2)
        return ele;
    return -1;

    // Taking extra space
    /*
    int occ = n/2;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)
    {
        m[arr[i]]++;
    }

    for(auto i:m)
    {
        if(i.second > occ)
            return i.first;
    }
    return -1;
    */
}