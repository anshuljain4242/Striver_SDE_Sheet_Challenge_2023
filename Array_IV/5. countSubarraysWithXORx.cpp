#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    int cnt = 0;
    map<int,int> m; // {xorvalue, count}
    m[xr]++; // {0,1} inserted in map

    for(int i=0; i<arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int k = xr ^ x;
        cnt += m[k]; // if k doesn't appear in the map, it automatically takes 0
        m[xr]++;
    }
    return cnt;
}