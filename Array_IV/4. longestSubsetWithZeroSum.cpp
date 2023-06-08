#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) 
{
    int maxLen = 0;
    int sum = 0;
    unordered_map<int,int> m; // sum : idx
    m[0] = -1; // index starting from -1 having sum 0
    for(int i=0; i<arr.size(); i++)
    {
        sum += arr[i];
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }
        else{
            int len = i - m[sum];
            maxLen = max(maxLen, len);
        }

    }
    return maxLen;
}