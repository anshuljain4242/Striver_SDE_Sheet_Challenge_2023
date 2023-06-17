#include<iostream>
#include<vector>
using namespace std;

struct activity{
    int start;
    int end;
};

bool comp(struct activity a, struct activity b)
{
    return a.end < b.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    struct activity v[start.size()];
    vector<vector<int> > activity(start.size());
    int ans = 1;
    for(int i=0; i<start.size(); i++)
    {
        v[i].start = start[i];
        v[i].end = finish[i];
    }

    sort(v , v+start.size(), comp);

    int limit = v[0].end;

    for(int i = 1; i<start.size(); i++)
    {
        if(v[i].start >= limit)
        {
            limit = v[i].end;
            ans++;
        }
    }
    return ans;
}