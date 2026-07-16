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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* mid=getmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next= nullptr;

        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
    ListNode* getmid(ListNode* head){
        ListNode* s=head;
        ListNode* f=head->next;
        while(f!=nullptr&&f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }return s;
    }
    ListNode* merge(ListNode* left,ListNode* right){
      ListNode newlist(0);
      ListNode* tail=&newlist;
        while(left!=nullptr&&right!=nullptr){
            if(left->val<right->val){
                tail->next=left;
                left=left->next;

            }else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if(left!=nullptr){
            while(left!=nullptr){
                tail->next=left;
                left=left->next;
                tail=tail->next;
            }
        }if(right!=nullptr){
            while(right!=nullptr){
                 tail->next=right;
                right=right->next;
                tail=tail->next;
            }
        }
return newlist.next;

    }
};