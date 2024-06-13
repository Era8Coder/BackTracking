#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int target, vector<vector<int>> &ans, vector<int> &temp, int i){
    // If target Becomes Zero this means we go tthe Answer :_
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    // -->> Recursion for all Reamining Elements <<--           // CAN ALSO USE THE FASCINATING FOR LOOP <<--
    while(i < v.size() && target - v[i] >= 0){
        temp.push_back(v[i]);
        solve(v, target-v[i], ans, temp, i);                // Recursively aflter using that Index :_
        i++;                // Then moving further to
        temp.pop_back();                // To analyse other ones also -> It's the Method Of Backtracking :)
    }
}

vector<vector<int>> combinations(vector<int> v, int target){
    vector<int> temp;
    vector<vector<int>> ans;
    solve(v, target, ans, temp, 0);
    return ans;
}

int main(){
    int n;  cin>>n;
    int target;  cin>>target;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());                   // Inbuilt for sorting an Array
    v.erase(unique(v.begin(),v.end()), v.end());        // To remove all the Duplicates
    vector<vector<int>> ans = combinations(v, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}