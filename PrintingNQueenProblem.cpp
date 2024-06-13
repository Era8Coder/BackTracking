#include<bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                cout << " Q ";
            }else{
                cout << " * ";
            }
        }
        cout << endl;
    }
}

bool is_safe(vector<vector<int>> &board, int row, int col, int n){
    int i,j;
    for(i=0; i<col; i++)
    {
        if(board[row][i]){
            return false;
        }
    }

    // CHECKING UPPER DIAGONAL
    for(i=row, j=col; i>=0 && j>=0; i--, j--){                  // -->> THE BEST LOOP I HAD EVEN SEEN TO TRAVERSE IN DIAGONAL DIRECTION <<--
        if(board[i][j]){        // That implies that Queen Already Exists there
            return false;
        }
    }

    // CHECKING LOWER DIAGONAL
    for(i=row, i=col; j>=0 && i<n; i++, j--){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board, int n, int col){
    // If All Queens are placed then return True
    if(col >= n) return true;

    // Placing queen in all rows one by one
    for(int i=0; i<n; i++){
        if(is_safe(board, i, col, n)){
            board[i][col] = true;
            if(solve(board, n, col+1)){             // Moving to the Next Column 
                return true;
            }
            board[i][col] = false;  
        }
    }        
    return false;
}

bool solve_NQ(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    if(!solve(board, n, 0)){           // That is if it return false   
        cout << "N Queen's Cannot Be Placed" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main(){
    int n;  cin>>n;
    solve_NQ(n);
    return 0;
}