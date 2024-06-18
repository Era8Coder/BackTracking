/*It had just passed 42/65 on LeetCode and time limit Exceeded -> I had uploaded copy paste Solution :_*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, int index, string &word, vector<vector<bool>> &visited, vector<vector<char>> &board) {
    if (index == word.size()) {
        return true; // If we have traversed the whole word
    }

    int m = visited.size();
    int n = visited[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[index]) {
        return false; // If word doesn't match or already visited or out of bounds
    }

    visited[i][j] = true;

    bool found = dfs(i + 1, j, index + 1, word, visited, board) ||
                 dfs(i - 1, j, index + 1, word, visited, board) ||
                 dfs(i, j + 1, index + 1, word, visited, board) ||
                 dfs(i, j - 1, index + 1, word, visited, board);

    visited[i][j] = false; // Backtracking
    return found;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // Creating a 2D visited array
    vector<string> ans;

    for (auto &word : words) {
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) { // If initial letters match
                    if (dfs(i, j, 0, word, visited, board)) { // Start dfs from (i, j)
                        ans.push_back(word);
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> ans = findWords(board, words);
    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}
