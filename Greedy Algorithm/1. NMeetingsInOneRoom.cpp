#include <iostream>
#include<vector>
using namespace std;


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    vector<int> ans;
    vector<vector<int> > meeting(start.size());

    for(int i=0; i<meeting.size(); i++)
    {
        meeting[i] = {end[i], i+1, start[i]};
    }
    sort(meeting.begin(), meeting.end());
    int limit = meeting[0][0];
    ans.push_back(meeting[0][1]);

    for(int i = 1; i<meeting.size(); i++)
    {
        if(meeting[i][2] > limit)
        {
            limit = meeting[i][0];
            ans.push_back(meeting[i][1]);
        }
    }
    return ans;
}