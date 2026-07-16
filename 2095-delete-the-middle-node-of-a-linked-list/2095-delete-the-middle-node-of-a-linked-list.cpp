/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        if(head->next->next==nullptr||head->next->next->next==nullptr){
            head->next=head->next->next;
            return head;
        }
        ListNode* s=head;
        ListNode* f=head;
        while(f->next->next!=nullptr&&f->next->next->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        s->next=s->next->next;
        return head;
    }
};