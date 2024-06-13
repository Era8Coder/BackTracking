#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string perm, int idx){
    if(str.size() == 0){
        cout << perm << endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        char x = str[i];
        string new_str = str.substr(0,i) + str.substr(i+1);
        permutation(new_str,perm+x,idx+1);
    }
}

int main(){
    string str = "ABC";
    int idx = 0;
    string perm = "";
    permutation(str, perm, idx);
    return 0;
}