#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int> > pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int> > pairs;
   
   sort(arr.begin(), arr.end());
   unordered_map<int, int> m;
   int n = arr.size();

   for(int i=0; i<n; i++)
   {
      int needed = s - arr[i];
      if(m.find(needed) != m.end())
      {
         int cnt = m[needed];
         while(cnt > 0)
         {  
            vector<int> temp_pair;
            temp_pair.push_back(needed);
            temp_pair.push_back(arr[i]);
            pairs.push_back(temp_pair);
            cnt--;
         }
      }
      m[arr[i]]++;
   }
   sort(pairs.begin(),pairs.end());
   return pairs;
   
}