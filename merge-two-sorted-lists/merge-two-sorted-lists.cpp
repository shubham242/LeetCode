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
static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ListNode *a, *res=NULL;
        if(l1==NULL)
        {
            res=l2;
            return res;
        }
        else if(l2==NULL)
        {
            res=l1;
            return res;
        }
        else if(l1==NULL&&l2==NULL)
        return res;
        if (l1->val <= l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        a = res;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l2 != NULL)
            {
                if (l1->val <= l2->val)
                {
                    a->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    a->next = l2;
                    l2 = l2->next;
                }
            }
            else if (l1 == NULL)
            {
                a->next = l2;
                l2 = l2->next;
            }
            else
            {
                a->next = l1;
                l1 = l1->next;
            }
            a=a->next;
        }
        return res;
    }
};