#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &arr, int n){

    // Without modifying the array - linked list cycle detection intution

    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    } 
    return slow;

    // in Place modification, TC -> O(n), SC -> O(1)
    /*
	int idx;
	for(int i=0; i<n; i++){
		idx = abs(arr[i]);
		if(arr[idx] >= 0)
			arr[idx] = 0 - arr[idx];
		else
			break;
	}
	return idx;
    */

    
    // using Binary Search
    /*
    int low = 1, high = n-1, cnt = 0;
    
	while(low <= high){
		int mid = low + (high - low)/2;
        cnt = 0;

		// cnt number less than equal to mid
		for(auto num : arr){
			if(num <= mid){
				++cnt;
			}
		}

		if(cnt <= mid){
			low = mid + 1;
		}else{
			high = mid-1;
		}
	}

	return low;
    */
}