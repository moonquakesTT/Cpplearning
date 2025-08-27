#include<iostream>
#include<stack>
using namespace std;

class queue{
    private:
    stack<int> in;
    stack<int> out;
    public:
    queue(){};
    void push(int val){
        in.push(val);
    }
    int pop(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int result=out.top();
        out.pop();
        return result;
    }

    int peek(){
        int res = this->pop();
        out.push(res);
        return res;
    }
    bool isempty(){
        return in.empty()&&out.empty();
    }
    
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.isempty()<<endl;
    return 0;
}
