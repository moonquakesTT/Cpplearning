#include<iostream>
using namespace std;

class MyLinkedList {

public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){};
    };
    MyLinkedList() {
        dumphead=new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        ListNode* cur = dumphead;
        while(index--){
            cur=cur->next; 
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* cur = new ListNode(val);
        cur->next=dumphead->next;
        dumphead->next=cur;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dumphead;
        ListNode* new_ = new ListNode(val);
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=new_;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur =dumphead;
        while(index--){
            cur=cur->next;
        }
        ListNode* new_=new ListNode(val);
        new_->next=cur->next;
        cur->next=new_;
    }
    
    void deleteAtIndex(int index) {
        ListNode* cur =dumphead;
        while(index--){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        
    }
    void printLinkedList() {
        ListNode* cur = dumphead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    private:
    ListNode* dumphead;
    int size;
};
int main(){
    MyLinkedList list;          // 1. 创建链表（此时空链表，只有 dummyHead）

       // 2. 头插法 3 个节点：10 -> 20 -> 30
    list.addAtHead(10);
    list.addAtHead(20);
    list.addAtHead(30);
    list.printLinkedList();     // 输出: 30 20 10

    // 3. 尾插法 2 个节点：30 20 10 40 50
    list.addAtTail(40);
    list.addAtTail(50);
    list.printLinkedList();     // 输出: 30 20 10 40 50

    // 4. 按索引插入
    list.addAtIndex(2, 99);     // 把 99 插入到下标 2 之前（即 10 之前）
    list.printLinkedList();     // 输出: 30 20 99 10 40 50]

    //5.按索引删除
    list.deleteAtIndex(2);
    list.printLinkedList();
}