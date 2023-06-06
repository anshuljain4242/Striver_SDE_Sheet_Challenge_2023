#include<iostream>
#include<vector>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Optimal Solution - using XOR
    
    pair<int, int> num;
    //Step 1
    int xr = 0;
    for(int i=0; i<n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    // Step 2
    int bitNo = 0;
    while(1){
        if((xr & (1<<bitNo)) != 0)
            break;
        bitNo++;     
    }

    // Step 3
    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++)
    {   
        // part of one club
        if((arr[i] & (1<<bitNo)) != 0)
        {
            one = one ^ arr[i];
        }    
        //part of zero club    
        else    
        {
            zero = zero ^ arr[i]; 
        }
    }
    for(int i=1; i<=n; i++)
    {
        if((i & (1<<bitNo)) != 0)
            one = one ^ i;
        else
            zero = zero ^ i;    
    }
    // Step 4
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == zero) cnt++;
    }
    if(cnt == 2){
        num.first = one;
        num.second = zero;
    }
    else{
        num.first = zero;
        num.second = one;
    }
    return num;

    // Optimal solution  - Mathematical
    /*
    pair<int, int> num;
    long long sumX = 0;
    long long sumN = (n*(n+1))/2;

    long long sumXsq = 0;
    long long sumNsq = (n*(n+1)*(2*n+1))/6;

    for(int i=0; i<n; i++)
    {
        sumX += arr[i];
        sumXsq += (long long)arr[i] * (long long)arr[i];
    }
    
    long long diff = sumX - sumN; // x - y

    long long diffSq = sumXsq - sumNsq; //x^2 - y^2
    
    diffSq = diffSq/diff; // x + y

    long long x = (diff + diffSq)/2;  // repeating
    long long y = x - diff;    // missing

    num.first = (int)y;
    num.second = (int)x;

    return num;
    */

    //Storing count in a temporary array
    /*
	vector<int> tempArr(n+1,0);
	pair<int, int> num;
	for(int i=0; i<n; i++)
	{
		tempArr[arr[i]]++;
	}

	for(int i=1; i<tempArr.size(); i++)
	{
		if(tempArr[i] == 0)
			num.first = i;
		else if(tempArr[i] == 2)
			num.second = i;	
	}

	return num;
    */
}