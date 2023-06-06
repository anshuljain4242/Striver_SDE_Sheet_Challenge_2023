#include<iostream>
#include<vector>
using namespace std;

/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int> > mergeIntervals(vector<vector<int> > &intervals)
{
    // OPTIMAL
    
    vector<vector<int> > merged;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    for(int i=0; i<n; i++)
    {
        if(merged.empty() || intervals[i][0] > merged.back()[1])
            merged.push_back(intervals[i]);
        else
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);    
    }
    
    return merged;

    // BETTER

    // vector<vector<int> > merged;
    // sort(intervals.begin(), intervals.end());
    // int n = intervals.size();
    // for(int i=0; i<n; i++)
    // {
    //     int first = intervals[i][0];
    //     int second = intervals[i][1];

    //     if(!merged.empty() && second <= merged.back()[1])
    //         continue;
        
    //     for(int j = i+1; j<n; j++)
    //     {
    //         if(intervals[j][0] <= second)
    //             second = max(second, intervals[j][1]);
    //         else
    //             break;    
    //     }
    //     merged.push_back({first,second});
    // }
    // return merged;

}
