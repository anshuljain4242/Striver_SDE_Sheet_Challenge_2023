#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &mat, int target)
{
    // Binary Search

    if(mat.size() == 0)
        return false;

    int low = 0;
    int n = mat.size();
    int m = mat[0].size();
    int high = n*m - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;
        if(target == mat[row][col])
            return true;
        else if(target < mat[row][col])
            high = mid - 1;
        else
            low = mid + 1;            
    }
    return false;

    // if row-wise and col-wise sorted
    /*
    int i =0, j = mat[0].size()-1;
    int row = mat.size();
    while(i<row && j >= 0)
    {
        if(mat[i][j] == target)
            return true;
        if(mat[i][j] > target)
            j--;
        else
            i++;        
    }
    return false;
    */ 
}