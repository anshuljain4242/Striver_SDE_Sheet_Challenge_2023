#include<iostream>
#include<vector>
using namespace std;

bool sortprofit(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1] || v1[1] == v2[1] && v1[0] >= v2[0];
}
int jobScheduling(vector<vector<int> > &jobs)
{
    sort(jobs.begin(), jobs.end(), sortprofit);

    int maxi = jobs[0][0];
    for(int i=1; i<jobs.size(); i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }

    vector<int> slot(maxi+1);

    for(int i=0; i<=maxi; i++)
        slot[i] = -1;

    int profit = 0;

    for(int i=0; i<jobs.size(); i++)
    {
        for(int j=jobs[i][0]; j>0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                profit += jobs[i][1];
                break;
            }
        }
    }    
    return profit;
}