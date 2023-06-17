#include<iostream>
#include<vector>
using namespace std;

void find_combinations2(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int> > &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue; // i>idx suggests that the elements gets repeated, it's not the first time
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);

        find_combinations2(i + 1, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int> > ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    find_combinations2(0, target, candidates, ds, ans);

    return ans;
}