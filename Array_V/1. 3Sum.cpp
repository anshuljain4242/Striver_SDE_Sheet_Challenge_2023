#include <iostream>
#include <map>
#include<vector>
using namespace std;

vector<vector<int> > findTriplets(vector<int>arr, int n, int K) {
	// set<vector<int> > st;

	// for(int i=0; i<n; i++)
	// {
	// 	set<int> hashset;
	// 	for(int j=i+1; j<n; j++)
	// 	{
	// 		int third = K-(arr[i] + arr[j]);
	// 		if(hashset.find(third) != hashset.end()){
    //             vector<int> temp = {arr[i], arr[j], third};
    //             sort(temp.begin(), temp.end());
    //         	st.insert(temp);
    //         }
    //         hashset.insert(arr[j]);
    //     }

    // }
	// vector<vector<int>> ans(st.begin(),st.end());
	// sort(ans.begin(),ans.end());
	// return ans;

	// vector<vector<int>> ans;
	// sort(ans.begin(), ans.end());
	// for(int i=0; i<n; i++)
	// {
	// 	if(i>0 && arr[i] == arr[i-1]) 
	// 		continue;
	// 	int j = i+1;
	// 	int k = n-1;
	// 	while(j < k)
	// 	{
	// 		int sum = arr[i] + arr[j] + arr[k];
	// 		if(sum == K)
	// 		{
	// 			ans.push_back({arr[i],arr[j],arr[k]});
	// 			j++;
	// 			k--;
	// 			while(j < k && arr[j] == arr[j-1]) j++;
	// 			while(j < k && arr[k] == arr[k+1])  k--;
	// 		}	
	// 		else if(sum < K)
	// 		{
	// 			j++;
	// 		}	
	// 		else
	// 		{
	// 			k--;
	// 		}		
			
	// 	}
		
	// }
	// return ans;

	sort(arr.begin(), arr.end());
	vector<vector<int> > ans;

	for(int i = 0; i < n-2; i++){
		int j = i+1;
		int k = n-1;

		while(j < k){
			if(arr[i]+arr[j]+arr[k] == K){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
				ans.push_back(temp);
				j++;
				k--;
			}
			else if(arr[i]+arr[j]+arr[k] > K){
				k--;
			}
			else{
				j++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	return ans;
}