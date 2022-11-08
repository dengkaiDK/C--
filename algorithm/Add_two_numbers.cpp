#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head3 = new ListNode();
        ListNode* head = head3;
        int add = 0;
        while (l1 || l2 || add){
            int val;
            if (l1 == nullptr && l2 != nullptr){
                val = add + l2->val;
            }
            else if (l2 ==  nullptr && l1 != nullptr){
                val = add + l1->val;
            }
            else if (l1 != nullptr && l2 != nullptr){
                val = add + l1->val + l2->val;
            }
            else{
                val = add;
            }
            if (val >= 10){
                val = val -10;
                add = 1;
            }
            else add = 0;
            ListNode* temp = new ListNode(val);
            head3->next = temp;
            head3 = head3->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return head->next;
    }
};

int main(){
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(9);
    ListNode* l3 = new ListNode(9);
    l1->next = l2;
    l2->next = l3;
    ListNode* l4 = new ListNode(9);
    ListNode* l5 = new ListNode(9);
    ListNode* l6 = new ListNode(9);
    l4->next = l5;
    l5->next = l6;
    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l4);
    while (result){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}