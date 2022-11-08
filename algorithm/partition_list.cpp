#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode vrt = ListNode(0, head); // virtual head
        ListNode* p1 = &vrt;
        ListNode* p2 = &vrt;
        ListNode* p3 = head;
        while(p3 != nullptr){
            if (p3->val < x){
                if (p1 == p2){
                    p1 = p3;
                    p2 = p3;
                    p3 = p3->next;
                }
                else{
                    p2->next = p3->next;
                    p3->next = p1->next;
                    p1->next = p3;
                    p1 = p3;
                    p3 = p2->next;
                }
            }
            else{
                p2 = p3;
                p3 = p3->next;
            }
        }
        return vrt.next;
    }
};

int main(void){
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(2);
    Solution s;
    ListNode* result = s.partition(head, 3);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}