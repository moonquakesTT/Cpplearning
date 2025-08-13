#include<iostream>
#include<vector>
using namespace std;
void countsort(vector<int> &num){
    int m=0;
    for(int i=0;i<num.size();i++){
        m = max(m,num[i]);
    }    
    vector<int> count(m+1,0);
    //统计每个元素出现的次数
    for(int i=0;i<num.size();i++)
    {
        count[num[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        count[i+1] += count[i];
    }
    int n = num.size();
    vector<int> res(n);
    for(int j = num.size()-1;j>=0;j--){
        int num_t = num[j];
        res[count[num_t]-1]=num_t;
        count[num_t]--;
    }
    num=res;
}
int main(){
    vector<int> num = {1,3,2,5,4,6,7,8,9,0};
    countsort(num);
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
    }
}