/*
I/p ->  { {1,2,3},
          {4,5,6},
          {7,8,9} }

O/p ->  { {4,1,2},
          {7,5,3},
          {8,9,6} }
*/


#include<iostream>
#include<vector>
using namespace std;

void rotateMatrix(vector<vector<int> > &mat, int n, int m)
{
    int row = 0, col = 0;
    int lastRow = n, lastCol = m;
    int prev,curr;

    while(row < lastRow && col < lastCol)
    {
        if(row + 1 == lastRow || col + 1 == lastCol) break;

        prev = mat[row+1][col];

        for(int i=col; i<lastCol; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for(int i=row; i<lastRow; i++)
        {
            curr = mat[i][lastCol-1];
            mat[i][lastCol-1] = prev;
            prev = curr;
        }
        lastCol--;

        if(row < lastRow)
        {
            for(int i = lastCol-1; i >= col; i--)
            {
                curr = mat[lastRow-1][i];
                mat[lastRow-1][i] = prev;
                prev = curr;
            }
        }
        lastRow--;

        if(col < lastCol)
        {
            for(int i = lastRow-1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

}