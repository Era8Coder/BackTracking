#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(vector<vector<bool>> &board, int row, int col){
        int n = board.size();
        
        // Check this column
        for (int i = 0; i < row; ++i) {
            if (board[i][col]) return false;
        }
        
        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j]) return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j]) return false;
        }

        return true;
    }

    int find_paths(int row, int n, vector<vector<bool>> &board){
        if(row == n){
            return 1;
        }

        int cnt = 0;
        for(int col = 0; col < n; ++col){
            if(is_valid(board, row, col)){
                board[row][col] = true;  // Placing queen
                cnt += find_paths(row + 1, n, board);
                board[row][col] = false;  // Backtracking
            }
        }
        return cnt;
    }

    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return find_paths(0, n, board); 
    }
};

int main(){
    int n;  cin>>n;
    Solution s;
    cout << s.totalNQueens(n) << endl;
    return 0;
}