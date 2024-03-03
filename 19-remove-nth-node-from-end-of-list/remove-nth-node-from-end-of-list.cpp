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
    ListNode *removeNthFromEnd(struct ListNode *head, int n) {
        ListNode *res = (struct ListNode *)malloc(sizeof(ListNode));
        res->next = head;
        ListNode *fast = res;
        ListNode *slow = res;

        while (n--)
            fast = fast->next;

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return res->next;
    }
};