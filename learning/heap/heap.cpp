#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int> v;
    public:
    void buildHeap(vector<int> &arr){
        v=arr;
        for(int i=(int)v.size()/2-1;i>=0;i--){
            heapify(i);
        }
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int x){
        v.push_back(x);
        int i = v.size()-1;
        while(i!=0 && v[parent(i)]<v[i]){
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
    void heapify_up(int i){
        while(i!=0 && v[parent(i)]<v[i]){
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
        
    }
    void heapify(int i){
        while(true){
            int left = 2*i+1;
            int right = 2*i+2;
            int maxidx = i;
            if(left<v.size() && v[left]>v[maxidx]){
                maxidx=left;
            }
            if(right<v.size() && v[right]>v[maxidx]){
                maxidx=right;
            }
            if(maxidx!=i){
                swap(v[i],v[maxidx]);
                i = maxidx;
            }
            else{
                break;
            }
        }  
    }
    void printHeap(){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }


};


int main(){
    vector<int> v={2,3,1,0,6,4,3,9,3,5,2};
    MaxHeap h;
    h.buildHeap(v);
    h.insert(10);
    h.printHeap();
    
    
}