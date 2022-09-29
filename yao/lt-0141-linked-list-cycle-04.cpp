class Solution {
public:
    bool hasCycle(ListNode *head) {

        /*
                            c   c    c    
        a -> a -> a -> a -> b ->b -> b -> b -> b 
                            ^                  |
                            |                  |
                            --------------------

        ****** step 1:
        pacer1 start from head with pace 1, 
        pacer2 start from head with pace 2. 
        if there is loop, they must meet, suppose they meet at c.
           
        */

        if (head == nullptr) return false;

        bool ret {false};
                
        ListNode* pacer1 = head;
        ListNode* pacer2 = head;


        while (pacer1 != nullptr) {

            pacer1 = pacer1->next;
            if (pacer1 == nullptr) {
                break;
            } 
            pacer1 = pacer1->next;
            pacer2 = pacer2->next;
            if (pacer1 == pacer2) {
                ret = true;
                break;
            }        

        }

        return ret;        
    }
};
