#include <iostream>
#include <vector>
#include<set>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int addIndex = 1;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            nums[addIndex] = nums[i + 1];
            addIndex++;
        }
    }
    return addIndex;

    // Bruteforce
    /*
    
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
        arr[j++] = x;
    }
    return k;
    */
}