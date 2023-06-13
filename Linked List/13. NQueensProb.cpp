#include<iostream>
#include<vector>
#include<string>
using namespace std; 
 
bool isSafe(int row, int col, vector<string>& chessboard, int n)
    {
        int r = row;
        int c = col;

        // upper diagonal
        while(row >=0 && col >=0)
        {
            if(chessboard[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = r;
        col = c;

        // left
        while(col >= 0)
        {
            if(chessboard[row][col] == 'Q') return false;
            col--;
        }

        row = r;
        col = c;

        while(row < n && col >= 0)
        {
            if(chessboard[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& chessboard, vector<vector<string> >& ans)
    {
        if(col == n)
        {
            ans.push_back(chessboard);
            return;
        }

        for(int row = 0; row<n; row++)
        {
            if(isSafe(row,col,chessboard,n))
            {
                chessboard[row][col] = 'Q';
                solve(col+1, n, chessboard, ans);
                chessboard[row][col] = '.';
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> chessboard(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        {
            chessboard[i] = s;
        }
        solve(0,n,chessboard,ans);
        return ans;
    }