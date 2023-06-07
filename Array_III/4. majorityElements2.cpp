#include<iostream>
#include<vector>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    // Optimal : TC -> O(2n), SC -> O(1)
    int n = arr.size();   
    int ele1,ele2;
    int cnt1=0, cnt2=0;

    for(int i=0; i<n; i++)
    {
        if(cnt1 == 0 && arr[i] != ele2){
            cnt1++;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != ele1){
            cnt2++;
            ele2 = arr[i];
        }
        else if(ele1 == arr[i])
            cnt1++;
        else if(ele2 == arr[i])
            cnt2++;
        else{
            cnt1--, cnt2--;
        }        
    }

    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;    
    }
    int min = n/3 + 1;
    vector<int> v;

    if(cnt1 >= min) v.push_back(ele1);
    if(cnt2 >= min) v.push_back(ele2);

    return v;

    // Using hashmap, single iteration : TC -> O(n), SC -> O(n)

    // unordered_map<int,int> m;
    // int n = arr.size();
    // int min = n/3 + 1;
    // vector<int> v;
    // for(int i=0; i<n; i++)
    // {
    //     m[arr[i]]++;
    //     if(m[arr[i]] == min)
    //         v.push_back(arr[i]);

    // }
    // return v;
        
}