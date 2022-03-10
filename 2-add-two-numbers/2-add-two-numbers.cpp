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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* it = head;
        ListNode* prev = nullptr;

        while( l1 and l2){
            
            int sum = 0;
            if(carry == 1)
                sum = l1->val + l2->val + 1;
            else 
                sum = l1->val +  l2->val;
            
            
            if(sum > 9){
                it->val = sum%10;
                carry = 1;
            }
            else{
                it->val = sum;
                carry = 0;
            }
            
            
            it->next = new ListNode();
            prev = it;
            it = it->next;
            

            
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while(l1){
            
            int sum = 0;
            if(carry == 1)
                sum = l1->val + 1;
            else 
                sum = l1->val;
            
            if(sum > 9){
                it->val = sum%10;
                carry = 1;
            }
            else{
                it->val = sum;
                carry = 0;
            }
            
            it->next = new ListNode();
            prev = it;
            it = it->next;
            

            
            l1 = l1->next;            
            
        }
        
        while(l2){
            
            int sum = 0;
            if(carry == 1)
                sum = l2->val + 1;
            else 
                sum = l2->val;
            
            if(sum > 9){
                it->val = sum%10;
                carry = 1;
            }
            else{
                it->val = sum;
                carry = 0;
            }
            
            it->next = new ListNode();
            prev = it;
            it = it->next;
            

            
            l2 = l2->next;            
            
        }
        
        if(carry == 1)
            it->val = 1;
        else
            prev->next = nullptr;
        
        return head;
    }
};