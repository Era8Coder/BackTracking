#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &temp, int n, int left, int k){
    // This implies that we had made the k-sized Array Now it's time to push it into the Answer Array/List
    if(k == 0){
        ans.push_back(temp);    // Append a copy of temp
        return;
    }
    // # Loop iterates from left to n -> First Time left will be "1"
    for(int i=left; i<n+1; i++){
        temp.push_back(i);
        solve(ans, temp, n, i+1, k-1);      // # Decreasing k till it reaches Zero and increasing the index
        temp.pop_back();
    }
}

vector<vector<int>> make_combinations(int n, int k){
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, n, 1, k);
    return ans;
}

int main(){
    int n;  cin>>n;
    int k;  cin>>k;
    // vector<int> v(n);
    // for(int i=0; i<n; i++){
    //     cin >> v[i];
    // }
    vector<vector<int>> ans = make_combinations(n, k);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}