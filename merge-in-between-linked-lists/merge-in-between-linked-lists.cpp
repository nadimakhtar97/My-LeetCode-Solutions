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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      
      ListNode* aa = list1;
      ListNode* end = list2;
      ListNode* bb = nullptr;
      
      while(end->next)
      end = end->next;
      
      for(int i=0;i<a-1;i++)
        if(aa->next)
          aa = aa->next;
      
      bb = aa;
      for(int i=0;i<(b-a+2);i++)
        if(bb->next)
          bb=bb->next;
      
      aa->next = list2;
      end->next = bb;
      
      return list1;
      
    }
};