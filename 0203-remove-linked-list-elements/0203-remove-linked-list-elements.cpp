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
    ListNode* removeElements(ListNode* head, int val) {
       
        if(head == NULL){
            return NULL;
        }else if(head->next == NULL and head->val == val){
            return NULL;
        }else if(head->next == NULL and head->val != val){
            return head;
        }
        
        
        ListNode *ans = head;
        ListNode *temp = NULL;
        ListNode *prev = NULL;
        
        
        while(ans != NULL and ans->val == val){
            ans = ans->next;
        }
        if(ans == NULL) return ans;
        temp = ans ->next;
        prev = ans;
        
        
        
        while(temp != NULL){
            if(temp->val == val){
                prev -> next = temp->next;
                temp = temp->next;
            }else{
                temp = temp->next;
                prev = prev->next;
            }
            
        }
        
        return ans;
        
        
        
        
        
    }
};