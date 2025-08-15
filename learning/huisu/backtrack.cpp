#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(int n,int k,int startind){
        if(k == path.size()){
            ans.push_back(path);
            return;
        }
        for(int i=startind;i<=n;i++){
            path.push_back(i);
            backtrack(n,k,i+1);
            path.pop_back();
        }

    }

    vector<vector<int>> combine(int n,int k)
    {
        backtrack(n,k,1);
        return ans;
    }
};
int main(){
    Solution S;
    vector<vector<int>> ans=  S.combine(9,2);
    for(auto i:ans){
        cout<<"["<<i[0]<<","<<i[1]<<"]";
        cout<<endl;
    }
}