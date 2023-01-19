#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* p1 = head;
        if(head->next == nullptr) return nullptr;
        ListNode* p2 = head->next;
        if (p1 == p2) return p1;

        p1 = p2;
        p2 = p2->next;
        while(p1 != p2){
            p1 = p1->next;
            if(p1 == nullptr) return nullptr;
            if(p2 == nullptr || p2->next == nullptr) return nullptr;
            p2 = p2->next->next;
        }
        // p2 is the meeting point , located at l - m % l in the cycle.
        //(l is the length of the cycle, m is the distance from head to the start of the cycle)

        p1 = head;
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        // after m % l steps, p1 and p2 will meet at the start of the cycle.

        return p2;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    cout << s.detectCycle(head)->val << endl;
    return 0;
}