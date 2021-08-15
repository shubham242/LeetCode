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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* ptr;
        ptr=head;
        while(ptr->next)
        {
            if(ptr->val==ptr->next->val)
            {
                ListNode* temp=ptr->next;
                ptr->next=ptr->next->next;
            }
            else
                ptr=ptr->next;
        }
        return head;
    }
};