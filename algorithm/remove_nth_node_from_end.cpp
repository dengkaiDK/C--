#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first;
        ListNode* second;
        ListNode* p;
        first = second = head;
        p = first;
        while (n--) second = second->next;
        while(second){
            p = first;
            first = first->next;
            second = second->next;
        }
        
        if(first->next){
            first->val = first->next->val;
            first->next = first->next->next;
        }
        else{
          if(p == first)
              head = nullptr;
            else
                p->next = nullptr;
        }
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i < 6; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    ListNode* ans = s.removeNthFromEnd(head, 2);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}