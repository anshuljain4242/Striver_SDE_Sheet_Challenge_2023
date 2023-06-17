#include<iostream>
#include<vector>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    double vpw1 = (double)a.second/a.first;
    double vpw2 = (double)b.second/b.first;
    return vpw1>vpw2;
}
double maximumValue (vector<pair<int, int> >& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);

    double maxVal = 0;
    int currWeight = 0;
    for(int i=0; i<items.size(); i++)
    {
        if(currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            maxVal += items[i].second;
        } else {
          int remain = w - currWeight;
          maxVal += (items[i].second / (double)items[i].first) * (double)remain;
          break;
        }
    }
    return maxVal;
}