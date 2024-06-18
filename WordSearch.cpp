#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &board, string word, int x, int y, int m, int n, int level){            
    // What the hell is level now ??
    /*
                        Level here is basivally till what extent the Strings are matched :)
    */
    int len = word.size();

    if(level == len){                   // Strings are matched Fully :_  
        return true;
    }

    if(x<0 || y<0 || x>=m || y>=n){    // Basically we had crossed the Bound <<--
        return false;                       
    }

    if(board[x][y] == word[level]){         // That is they are matched at i'th level also then We can say that <<-->> We can proceed further :)
        char temp = board[x][y];
        board[x][y] = '*';              // Marking it as visited or Garbage value so that we don't visit again and again :)

        bool res = solve(board, word, x-1, y, m, n, level+1) || solve(board, word, x+1, y, m, n, level+1) || solve(board, word, x, y-1, m, n, level+1) || solve(board, word, x, y+1, m, n, level+1);              // Exploring the all possible cases :)

        board[x][y] = temp;
        return res;
    }

    return false;
}

bool exist(vector<vector<char>> &board, string word, int m, int n){
    int l = word.size();
    if(l > m*n){
        return false;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == word[0]){
                if(solve(board, word, i, j, m, n, 0)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word1 = "ABCCED";
    string word2 = "ADCSFG";
    int m = board.size();
    int n = board[0].size();
    cout << exist(board, word1, m, n) << endl;
    cout << exist(board, word2, m, n) << endl;
    return 0;
}