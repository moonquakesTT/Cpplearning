#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
Node* reverse(Node* head,int left,int right){
    if(!head||left>right){
        return nullptr;
    }
    Node* dump = new Node(-1);
    dump->next = head;
    Node* pre = dump;
    for(int i = 0;i<left;i++){
        pre=pre->next;
    } 
    Node* cur=pre->next;
    Node* next=nullptr;
    for(int i = 0;i<right-left;i++){
        next = cur->next;
        cur->next=next->next;
        next->next = pre->next;
        pre->next = next;
    }
    //code here
    return dump->next;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    Node* ans = reverse(head,1,3);
    while(ans){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
}