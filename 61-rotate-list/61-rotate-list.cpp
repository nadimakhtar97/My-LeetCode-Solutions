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
        
        if(head == nullptr or k == 0)
            return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* temp2 = head;
        ListNode* temp1 = dummy;
        int count = 1;
        
        
        while(temp2->next){
            temp2 = temp2->next;
            count++;
        }
        
        if(count == 1)
            return head;
        
        
        temp2 = head;
        k = k%count;
        count  = 1;
        
        if(k == 0)
            return head;
        
        
        while(temp2 and count != k){
            temp2 = temp2->next;
            count++;
        }
        
        
        while(temp2->next){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        
        ListNode* ans = temp1->next;
        temp1->next = nullptr;
        temp2->next = head;
        
        return ans;
        
        
        
        
        
    }
};