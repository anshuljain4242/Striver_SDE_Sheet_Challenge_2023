#include<iostream>
using namespace std;

int findMinimumCoins(int amount) 
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int num = 0;
    int n=9;
    for(int i=n-1; i>=0; i--)
    {
        while(amount >= coins[i])
        {
            amount -= coins[i];
            num++;
        }
    }
    return num;
}