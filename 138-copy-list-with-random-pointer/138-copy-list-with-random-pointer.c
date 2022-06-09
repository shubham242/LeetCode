struct Node *copyRandomList(struct Node *head)
{
    if (head == NULL)
        return head;
    struct Node *node = head;
    while (node != NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = node->val;
        temp->next = node->next;
        node->next = temp;
        node = node->next->next;
    }
    node = head;
    while (node != NULL)
    {
        node->next->random = node->random == NULL ? NULL : node->random->next;
        node = node->next->next;
    }

    struct Node *res = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ans = res;
    node = head;
    while (node != NULL)
    {
        res->next = node->next;
        node->next = node->next->next;
        node = node->next;
        res = res->next;
    }
    return ans->next;
}