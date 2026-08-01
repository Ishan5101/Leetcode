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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;


        ListNode *curr=head;
        ListNode *temp=head->next;
        ListNode *ishan=temp;

        while(temp && temp->next ){
            
            curr->next=temp->next;
            
            curr=curr->next;

            temp->next=curr->next;
            temp=temp->next;
        }
        curr->next=ishan;
        return head;
    }
};