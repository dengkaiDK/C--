#include<iostream>
#include<map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    // O(n) space , O(n) time
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> hash;
        if (head == nullptr) return nullptr;
        Node* copy_head = new Node(head->val);
        Node* ori = head;
        Node* cur = copy_head;
        hash[ori] = cur;
        cur->random = ori->random;

        hash[nullptr] = nullptr;
        
        while(ori->next){
            ori = ori->next;
            cur->next = new Node(ori->val);
            cur = cur->next;
            hash[ori] = cur;
            cur->random = ori->random;
        }

        cur = copy_head;
        while(cur){
            cur->random = hash[cur->random];
            cur = cur->next;
        }

        return copy_head;
    }

    // O(1) space, O(n) time
    Node* copyRandomList2(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        while(cur){
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        cur = head;
        while(cur){
            if (cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        Node* copy_head = head->next;
        while(cur){
            Node* copy = cur->next;
            cur->next = copy->next;
            if (copy->next){
                copy->next = copy->next->next;
            }
            cur = cur->next;
        }

        return copy_head;
    }
};

int main(){
    Solution s;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node* copy_head = s.copyRandomList(head);
    Node* copy_head2 = s.copyRandomList2(head);
    while(copy_head){
        cout << copy_head->val << " ";
        if (copy_head->random)
            cout << "random: " << copy_head->random->val << " | ";
        else
            cout << "random: " << "nullptr" << " | ";
        copy_head = copy_head->next;
    }

    cout << endl;

    while(copy_head2){
        cout << copy_head2->val << " ";
        if (copy_head2->random)
            cout << "random: " << copy_head2->random->val << " | ";
        else
            cout << "random: " << "nullptr" << " | ";
        copy_head2 = copy_head2->next;
    }

    cout << endl;
    return 0;
}