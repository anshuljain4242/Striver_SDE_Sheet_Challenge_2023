#include<iostream>
using namespace std;

// Optimal : TC -> O(2nlong) + O(2n)

int calculateMinPatforms(int at[], int dt[], int n) {

    // doesn't matter if the arr time and dept time of a train shuffles. We are only concerned with the time frames of the day.
    sort(at , at+n);
    sort(dt , dt+n);

    int ans = 1;
    int platform_needed = 1;
    int i=1, j=0;

    while(i < n && j < n)
    {
        if(at[i] <= dt[j])
        {
            platform_needed++;
            i++;
        }
        else if(at[i] > dt[j]){
            platform_needed--;
            j++;
        }
        if(platform_needed > ans)
            ans = platform_needed;
    } 
    return ans;
}