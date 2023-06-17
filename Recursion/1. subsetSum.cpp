#include <iostream>
#include <vector>
using namespace std;

void getSum(int idx, int sum, vector<int> &ds, vector<int> &arr, int N)
{
    if (idx == N)
    {
        ds.push_back(sum);
        return;
    }

    getSum(idx + 1, sum + arr[idx], ds, arr, N);
    getSum(idx + 1, sum, ds, arr, N);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ds;
    int sum = 0;
    getSum(0, sum, ds, arr, N);
    sort(ds.begin(), ds.end());
    return ds;
}