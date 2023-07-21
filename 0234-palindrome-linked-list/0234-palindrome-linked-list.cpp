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
    
    ListNode *rev(ListNode *h){
        
        if(h == NULL){
            return NULL;
        }
        
        
        ListNode *temp1 = h;
        ListNode *temp2 = h->next;
        
        h->next = NULL;
        
        while(temp2 != NULL){
            temp1 = temp2;
            temp2 = temp2->next;
            temp1->next = h;
            h = temp1;
        }
        
        return temp1;
        
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        
        if(head == NULL or head->next == NULL){
            return true;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        fast = rev(fast);
        
        
        while(head != NULL and fast != NULL){
            if(head->val != fast->val){
                return false;
            }
            head = head->next;
            fast = fast->next;
        }
        
        return true;
        
    }
};









