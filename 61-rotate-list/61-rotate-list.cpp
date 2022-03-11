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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == nullptr)
            return head;
        
        ListNode* tail = head;
        ListNode* newHead = head;
        int count = 1;
        
        while(tail->next){
            tail = tail->next;
            count++;
        }
        
        tail->next = head;
        
        if( k %= count){
            
            for(int i=0;i< count-k ;i++) tail = tail->next;
            
        }
        
        cout<<tail->val;
        
        newHead = tail->next;
        tail->next = nullptr;
        
        
        return newHead;
        
    }
};