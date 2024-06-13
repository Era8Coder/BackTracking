#include<bits/stdc++.h>
using namespace std;

void solve(int i, string &s, string &temp, vector<string> &ans, map<char,string> &mp){          // All are passed as reference since we don't wanted to Make Copy at each level of Recursion
    if(i == s.size()){
        ans.push_back(temp);
        return;
    }
    string str = mp[s[i]];
    for(int j=0; j<str.size(); j++){
        temp.push_back(str[j]);               // Pushing in the Temp string :)-> Making all the Combination possible
        solve(i+1, s, temp, ans, mp);               // Calling Recursino Again and Again
        temp.pop_back();                    // Popping Back <<-- To give chance to other characters to take place and make possible permutations :)
    }
}

vector<string> letter_combinations(string digits){
    map<char,string> mp;
    mp['2'] = "abc"; mp['3'] = "def";
    mp['4'] = "ghi"; mp['5'] = "jkl";
    mp['6'] = "mno"; mp['7'] = "pqrs";
    mp['8'] = "tuv"; mp['9'] = "wxyz";
    vector<string> ans;
    string temp;
    solve(0,digits,temp,ans,mp);
    return ans;
}

int main(){
    string digits;   cin>>digits;
    vector<string> ans = letter_combinations(digits);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}