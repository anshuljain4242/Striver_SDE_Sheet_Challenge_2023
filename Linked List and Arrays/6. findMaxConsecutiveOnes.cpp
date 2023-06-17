#include <iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{

    int ones = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        ones = max(count, ones);
    }
    return ones;
}