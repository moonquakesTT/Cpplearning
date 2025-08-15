#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        vector<vector<int>> res;
        vector<int> path;
    
    void dfs(int n,int k,int startind,int sum){
        if(n>sum){
            return;
        }
        if(path.size()==k){
            if(sum==n){
                res.push_back(path);
            }
            return;
        }
        for(int i=startind;i<=20-(k-path.size())+1;i++){
            n=i+n;
            path.push_back(i);
            dfs(n,k,i+1,sum);
            n=n-i;
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k,int sum) {
        dfs(0,k,1,sum);
        return res;
    }
};
int main(){
    Solution S;
    vector<vector<int>>res= S.combine(20,4,20);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}