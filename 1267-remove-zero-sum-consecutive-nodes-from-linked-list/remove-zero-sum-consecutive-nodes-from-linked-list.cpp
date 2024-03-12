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
    ListNode *removeZeroSumSublists(ListNode *head) {
        ListNode *root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode *> Map;
        Map[0] = root;
        int sum = 0;

        while (head != NULL) {
            sum += head->val;
            if (Map.find(sum) != Map.end()) {
                ListNode *prev = Map[sum];
                ListNode *start = prev->next;

                int tempSum = sum;

                while (start != head) {
                    tempSum += start->val;
                    Map.erase(tempSum);
                    if (tempSum == 0)
                        Map[0] = root;
                    start = start->next;
                }

                prev->next = head->next;

            } else {
                Map[sum] = head;
            }
            head = head->next;
        }

        return root->next;
    }
};