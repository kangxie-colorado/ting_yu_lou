class Solution {
public:

    bool hasCycle(ListNode *head) {

        if (head == nullptr) return false;

        bool ret {false};
                
        ListNode* node = head;
        ListNode* prenode {nullptr};
        ListNode* nextnode {nullptr};

        // first pass: check cycle
        while (node->next != nullptr) {

            nextnode = node->next;                
            node->next = prenode;
            prenode = node;
            node = nextnode;            
            
            if (node == head) {
                ret = true;
            }
        }
        node->next = prenode;

        // second pass: restore linked list for no-cycle-list
        if (!ret) {
            prenode = nullptr;
            nextnode = nullptr;                
            while (node->next != nullptr) {

                nextnode = node->next;                
                node->next = prenode;
                prenode = node;
                node = nextnode;            
                
            }
            node->next = prenode;
        }

        return ret;
        
    }
};
