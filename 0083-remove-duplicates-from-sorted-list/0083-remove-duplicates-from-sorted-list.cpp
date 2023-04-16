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
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode *temp = head;
        ListNode *res = head->next;
        
        while(res != NULL){
            if(res->val == temp->val){
                res = res->next;
                temp->next = res;
            }else{
                temp = temp->next;
                res  =  res->next;
            }
        }
        return head;
    }
};