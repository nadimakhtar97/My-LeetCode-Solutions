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
    
    void deleteNodes(ListNode* prev, ListNode* nxt){
        prev->next = nxt;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr)
            return head;
        
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* prev = fakeHead;
        ListNode* cur = head;
        
        while(cur){
            // cout<<cur->val<<" "<<nxt->val<<endl;  
            
            while(cur->next and cur->val == cur->next->val){
                    cur = cur->next;
                }
            
            if(prev->next == cur){
                prev = prev->next;
            }
            else{
                prev->next = cur->next;
            }
            cur = cur->next;
                

            
        }
        
        return fakeHead->next;
        
    }
};