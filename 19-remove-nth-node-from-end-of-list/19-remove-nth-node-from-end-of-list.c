struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *d = (struct ListNode *)malloc(sizeof(struct ListNode));
    d->next = head;
    struct ListNode *f = d;
    struct ListNode *s = d;
    while (n--)
    {
        f = f->next;
    }

    while (f->next != NULL)
    {
        f = f->next;
        s = s->next;
    }
    s->next = s->next->next;
    return d->next;
}