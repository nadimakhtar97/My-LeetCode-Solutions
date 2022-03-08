/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i=0;i<2;i++){
            if(fast->next){
                fast = fast->next;
            }
            else{
                return false;
            }
        }
        
        while(fast->next and fast->next->next){
        
                fast = fast->next->next;
                slow = slow->next;
                
            if(fast == slow) return true;
            
        }
        
        return false;
        
    }
};
