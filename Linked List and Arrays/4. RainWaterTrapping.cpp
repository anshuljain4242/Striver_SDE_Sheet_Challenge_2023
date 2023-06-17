#include<iostream>
#include<vector>
using namespace std;

long getTrappedWater(long *arr, int n){
    
    // Optimal : TC -> O(n), SC-> O(1)

    long trap = 0;
    long leftMax = 0;
    long rightMax = 0;
    int l = 0, r = n-1;

    while(l<=r)
    {
        if(arr[l] <= arr[r])
        {
            if(arr[l] >= leftMax) 
                leftMax = arr[l];
            else
                trap += leftMax - arr[l]; 
            l++;       
        }
        else
        {
            if(arr[r] >= rightMax)
                rightMax = arr[r];
            else
                trap += rightMax - arr[r]; 
            r--;       
        }
    }
    return trap;


    // Better : TC -> O(n) + O(n) + O(n), SC ->O(2n)

    /*
    vector<long> prefixMax(n);
    vector<long> suffixMax(n);

    prefixMax[0] = arr[0];
    
    for(int i=1; i<n; i++)
    {
        prefixMax[i] = max(arr[i],prefixMax[i-1]);
    }

    suffixMax[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--)
    {
        suffixMax[i] = max(arr[i],suffixMax[i+1]);
    }

    long trap = 0;
    for(int i=0; i<n; i++)
    {
        trap += min(prefixMax[i], suffixMax[i]) - arr[i];
    }
    return trap;
    */
}  