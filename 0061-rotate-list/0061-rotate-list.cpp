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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        k=k%n;
        delete(temp);
        
        while(k>0){
ListNode* prev=head;
prev=prevdede(head,prev);
ListNode* temp=prev->next;
temp->next=head;
head=temp;
prev->next=nullptr;
k--;
        }return head;
    }

    ListNode* prevdede(ListNode* head,ListNode* prev){
        while(prev->next->next!=nullptr){
            prev=prev->next;
        }return prev;
    }
};