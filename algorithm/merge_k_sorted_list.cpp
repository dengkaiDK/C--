#include<iostream>
#include<vector>

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
    static bool cmp_value(ListNode* a,ListNode* b){
        return a->val < b->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> minList;
        ListNode* head = new ListNode();
        ListNode* cur;
        cur = head;
        if(lists.size() == 0)
            return nullptr;
        
        int i;
        for(i=0; i<lists.size(); i++){
            if(lists[i])
                minList.push_back(lists[i]);
        }
        
        vector<ListNode*>::iterator smallest;
        
        while(minList.size() > 1){
            smallest = min_element(minList.begin(), minList.end(), cmp_value);
            cur->next = *smallest;
            cur = cur->next;
            minList.erase(smallest); // 注意要在cur->next调用前删除，否则smallest指向的值会被删除, 导致重复删除
            if(cur->next)
            {
                minList.push_back(cur->next);
            }
        }
        
        if(!minList.empty()){
            smallest = minList.begin();
            cur->next = *smallest;
        }
       
        cur = head->next;
        delete head;
        minList.clear();
        return cur;
        
    }
    
};

int main(){
    ListNode* head1 = new ListNode(0);
    head1->next = new ListNode(6);
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    ListNode* head3 = new ListNode(4);
    head3->next = new ListNode(5);

    Solution a;
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    ListNode* head = a.mergeKLists(lists);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}