#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    // Optimal
    int longest = 1;
    unordered_set<int> s;

    // Inserting array elements into set
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    // Iterating the set
    for(auto it : s)
    {
        // if prev element not in the set
        if(s.find(it-1) == s.end()){
            // start the sequence from this number
            int curr_cnt = 1; 
            int x = it;

            // if next element of x is in the set, keep increasing the count
            while(s.find(x+1) != s.end()){
                curr_cnt++;
                x = x+1;
            }
            longest = max(longest,curr_cnt);
        } 
    }
    return longest;

    // Better
    /*
    sort(arr.begin(), arr.end());

    int longest = 1;
    int curr_cnt = 0;
    int lastSmaller = INT_MIN; 

    for(int i=0; i<n; i++)
    {
        // 
        if(lastSmaller == arr[i]-1){
            curr_cnt++;
            lastSmaller = arr[i];
        }
        else if(lastSmaller != arr[i]){
            curr_cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, curr_cnt);
    }
    return longest;
    */
    
}