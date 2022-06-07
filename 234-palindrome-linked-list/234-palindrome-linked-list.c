struct ListNode *middleNode(struct ListNode *head)
{

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
struct ListNode *reverseList(struct ListNode *head)
{

    struct ListNode *prev = NULL;
    while (head != NULL)
    {
        struct ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *middle = middleNode(head);
    middle->next = reverseList(middle->next);

    middle = middle->next;

    while (middle)
    {
        if (head->val != middle->val)
            return false;
        head = head->next;
        middle = middle->next;
    }

    return true;
}