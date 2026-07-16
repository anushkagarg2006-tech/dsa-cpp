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
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)return true;
        if(head->next->next==nullptr){
            if(head->val==head->next->val){
                return true;
            }else{
                return false;
            }
        }
        ListNode* s=head;
        ListNode* f=head;
        while(f!=nullptr&&f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        ListNode* mid=s;
        ListNode* curr=mid;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            mid=curr->next;
            curr->next=prev;
            prev=curr;
            curr=mid;
        }
        ListNode* j=prev;
        while(j!=nullptr){
            if(head->val!=j->val){
                return false;
            }
            head=head->next;
            j=j->next;
        }return true;
    }
};