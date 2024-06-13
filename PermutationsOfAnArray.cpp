#include<bits/stdc++.h>
using namespace std;
// Permutations -/> Rearrangement of members of a sequence into a new sequence

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void permutations(vector<vector<int>> &ans, vector<int> &nums, int l, int h){
    if(l == h){             // BASE CASE
        ans.push_back(nums);
        return;
    }

    // Making permutations By Swapping
    for(int i=l; i<=h; i++){
        swap(nums[l],nums[i]);          // Swapping of Nums -> Lower One and Upper One
        // Calling Permutations for next greater Value of "l"
        permutations(ans, nums, l+1, h);
        swap(nums[l],nums[i]);          // Take them to their Original Index After Using :)
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    int high = nums.size() - 1;
    // Calling permutations for first time by passing l = 0 and h = nums.size() - 1
    permutations(ans, nums, 0, high);
    return ans;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<int>> ans = permute(v);
    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
   return 0;
}