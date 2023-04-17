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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head, *res= head;
    
        while(n--){
            temp = temp->next;
        }
        
        if(temp == NULL){
            return head->next;
        }
        
        while(temp->next != NULL){
            temp = temp->next;
            res = res -> next;
        }
        
        res->next = res->next->next;
        
        return head;
    }
};