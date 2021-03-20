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
        ListNode *l3 = new ListNode(0);
        ListNode *x1=l1,*x2=l2,*x3=l3;
        int c=0;
        while(x1!=NULL||x2!=NULL||c!=0)
        {
            int x,y;
            if(x1!=NULL)
               x=x1->val;
            else
                x=0;
            if(x2!=NULL)
               y=x2->val;
            else
                y=0;
            
            x3->next = new ListNode((x+y+c)%10);
            c=(x+y+c)/10;
            x3=x3->next;
            if(x1!=NULL)
               x1=x1->next;
            if(x2!=NULL)
               x2=x2->next;
            
        }
        
        return l3->next;
    }
};