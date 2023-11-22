struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *fuckingTLE(ListNode *head) {

    auto sorted = head;

    if (!head)
        return head; // probably bad taste but imagine sorting a empty list

    auto const start = head->next;

    // make the sorted list a separate list
    sorted->next = nullptr;

    auto current = start;
    while (current) {
        auto next = current->next;

        // now we insert the node into the sorted list
        if (current->val <= sorted->val) {
            current->next = sorted;
            sorted = current;
        } else {
            auto sorted_current = sorted;
            while (sorted_current->next && sorted_current->next->val < current->val) {
                sorted_current = sorted_current->next;
            }

            current->next = sorted_current->next;
            sorted_current->next = current;
        }

        current = next;
    }

    return sorted;
}

