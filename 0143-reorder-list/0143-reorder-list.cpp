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
    
    ListNode* rev(ListNode *h){
        
        if(h == NULL or h->next == NULL){
            return h;
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
    
    ListNode *middle(ListNode *h){
        
        if(h == NULL or h->next == NULL){
            return h;
        }
        
        ListNode *slow = h;
        ListNode *fast = h->next;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL or head->next == NULL)
            return;
        
        
        
        ListNode *s = middle(head);
        ListNode* next_half = s->next;
        s->next = NULL;
        ListNode *k = rev(next_half);
        
        
        while(k != NULL){
            ListNode *next1 = head->next;
            head->next = k;
            ListNode *next2 = k->next;
            k->next = next1;
            k = next2;
            head = next1;
        }
    }
};