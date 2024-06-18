#include<bits/stdc++.h>
using namespace std;

void generateparanthesis(int left, int right, string &s, vector<string> &ans){
    if(left == 0 && right == 0){                    // Case of Balanced Paranthesis
        ans.push_back(s);
    }

    if(left > right || left < 0 || right < 0){              // Invalid Case             // Right > Left -> Condition is invalid because Left will always decrease first but that case will never come
        return;
    }

    /*
                                    In bactracking remember that After pushing -> Recursion -> Popping 
                                                             PUSHING
                                                              |~|~|
                                                            RECURSION
                                                              |~|~|
                                                             POPPING
    */

    s.push_back('{');               // String also supports push back :')
    generateparanthesis(left-1, right, s, ans);
    s.pop_back();

    s.push_back('}');
    generateparanthesis(left, right-1, s, ans);
    s.pop_back();
}

int main(){
    int n;  cin>>n;
    vector<string> ans;
    string s;
    generateparanthesis(n,n,s,ans);
    for(auto it : ans){
        cout << it << endl;
    }
    return 0;
}