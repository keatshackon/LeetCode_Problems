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
    
    ListNode* rev(ListNode *head){
        
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        
        head->next = NULL;
        
        while(temp2 != NULL){
            temp1 = temp2;
            temp2 = temp2->next;
            temp1->next = head;
            head = temp1;
        }
        
        return temp1;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode *num1 = rev(l1);
        ListNode *num2 = rev(l2);
        
        ListNode *ans = new ListNode(-1);
        ListNode *res = ans;
        
        int carry = 0;
        
        while(num1 != NULL and num2 != NULL){
            carry += num1->val;
            carry += num2->val;
            
            if(carry > 9){
                ListNode *temp = new ListNode(carry%10);
                ans->next = temp;
                ans = temp;
                carry = carry / 10;
            }else{
                ListNode *temp = new ListNode(carry);
                ans->next = temp;
                ans = temp;
                carry = 0;
            }
            
            num1 = num1->next;
            num2 = num2->next;
        }
        
        while(num1 != NULL){
            carry += num1->val;
            if(carry > 9){
                ListNode *temp = new ListNode(carry%10);
                ans->next = temp;
                ans = temp;
                carry = carry / 10;
            }else{
                ListNode *temp = new ListNode(carry);
                ans->next = temp;
                ans = temp;
                carry = 0;
            }
            num1 = num1->next;
        }
        
        
        while(num2 != NULL){
            carry += num2->val;
            if(carry > 9){
                ListNode *temp = new ListNode(carry%10);
                ans->next = temp;
                ans = temp;
                carry = carry / 10;
            }else{
                ListNode *temp = new ListNode(carry);
                ans->next = temp;
                ans = temp;
                carry = 0;
            }
            num2 = num2->next;
        }
        
        if(carry != 0){
            ListNode *temp = new ListNode(carry);
            ans->next = temp;
            ans = temp;
        }
        
        ans = res;
        res = res->next;
        ans->next = NULL;
        return rev(res);
        
    
        
    }
};