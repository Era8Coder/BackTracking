#include<bits/stdc++.h>
using namespace std;

/*
                                -->> More Efficient Solution Using Trie Data Structure <<--
*/

// Trie Node structure
struct Node {
    Node* nxt[26] = {nullptr}; // Children nodes for each letter
    bool isEnd = false; // Marks if this node represents the end of a word
};

// Trie class
class Trie {
public:
    Node* root = new Node(); // Root of the Trie

    // Insert a word into the Trie
    void insert(const string& s) {
        auto curr = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (curr->nxt[idx] == nullptr) {
                curr->nxt[idx] = new Node();
            }
            curr = curr->nxt[idx];
        }
        curr->isEnd = true; // Mark end of word
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        auto curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->nxt[idx] == nullptr) {
                return false; // Not found
            }
            curr = curr->nxt[idx];
        }
        return curr->isEnd; // Check if it's the end of a word
    }
    
    // Check if there is any word in the Trie with the given prefix
    bool startsWith(const string& prefix) {
        auto curr = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (curr->nxt[idx] == nullptr) {
                return false; // Prefix not found
            }
            curr = curr->nxt[idx];
        }
        return true; // Prefix found
    }
};

// Solution class
class Solution {
public:
    Trie t; // Trie object to store words
    int dx[4] = {0, 0, 1, -1}; // Offsets for adjacent cells (up, down, right, left)
    int dy[4] = {-1, 1, 0, 0};
    vector<string> ans; // Resultant words found on the board
    vector<string> found; // Found words to avoid duplicates

    // Check if a move to (x, y) is valid
    bool isValidMove(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]);
    }

    // Backtracking helper function to find words starting from position (i, j)
    void helper(vector<vector<char>>& board, int i, int j, string& s, vector<vector<bool>>& visited) {
        // Check if the current prefix is a valid prefix of any word in the Trie
        if (!t.startsWith(s)) {
            return;
        }
        
        // If the current prefix forms a valid word, add it to the result
        if (t.search(s) && find(found.begin(), found.end(), s) == found.end()) {
            ans.push_back(s);
            found.push_back(s);
        }

        visited[i][j] = true; // Mark current cell as visited

        // Explore all adjacent cells
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (isValidMove(ni, nj, board, visited)) {
                s.push_back(board[ni][nj]); // Choose
                helper(board, ni, nj, s, visited); // Explore
                s.pop_back(); // Unchoose (backtrack)
            }
        }

        visited[i][j] = false; // Mark current cell as unvisited (backtrack)
    }

    // Main function to find words on the board
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Insert all words into the Trie
        for (const auto& word : words) {
            t.insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Matrix to mark visited cells

        // Explore each cell on the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string s;
                s.push_back(board[i][j]); // Start from the current cell
                helper(board, i, j, s, visited); // Find words starting from this cell
            }
        }

        return ans; // Return the found words
    }
};

int main(){

    return 0;
}