#include<iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	
    // Iterative Approach
    
    int ans = 1;
	while(n>0)
	{
		if(n&1)
		{
			ans = (1LL*ans*x)%m;
			n--;	
		}	
		x = (1LL*x*x)%m;
		n = n >> 1;
	}
	return ans;

    // Recursive Approach
    /*
    if(n == 0) return 1;
    int ans = modularExponentiation(x, n/2, m);
    if(n&1)
        return (x * ((ans * 1LL * ans) % m)) % m;
    else
        return (ans * 1LL * ans) % m;
    */
        

}