#include<iostream>
#include<vector>

using namespace std;

// Most Optimal : TC -> O(m-1), SC -> O(1)
int uniquePaths(int m, int n) {
	// Using combination N C r
	int N = m + n -2; 
	int r = m-1;
	double res = 1;

	for(int i=1; i<=r; i++)
	{
		res = res * (N-r+i)/i;
	}
	return (int)res;

}

// Optimal - DP : TC -> O(m*n), SC -> O(m*n)
int countPaths(int i, int j, int m, int n, vector< vector<int> > &dp)
{
	if(i == m-1 && j == n-1) return 1;
	if(i >= m || j >= n) return 0;

	if(dp[i][j] != -1) return dp[i][j];
	else return dp[i][j] = countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp);
}
int uniquePathsDP(int m, int n) {
	vector< vector<int> > dp(m, vector<int> (n,-1)); // initialising m*n vector with -1
	return countPaths(0,0,m,n,dp);
}

// Brute force - Recursive Approach : TC, SC -> exponential
int recursivePath(int i, int j, int m ,int n)
{
    if(i >= m  || j >= n) return 0;
    if(i == m-1 && j == n-1) return 1;
    else
        return recursivePath(i,j+1,m,n) + recursivePath(i+1,j,m,n); 
}

