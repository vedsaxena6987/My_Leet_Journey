class Solution {
public:
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while(l && r) {
            if(l->val < r->val) {
                tail->next = l;
                l = l->next;
            } else {
                tail->next = r;
                r = r->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l ? l : r);
        return dummy.next;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* ms(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* mid = middle(head);
        ListNode* right = mid->next;
        mid->next = nullptr; 
        
        ListNode* left = ms(head);
        right = ms(right);
        
        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return ms(head);
    }
};