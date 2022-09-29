class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

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

        pacer1's travel distance: a + mb + c
        pacer2's travel distance: a + nb + c

        2 * (a + mb + c) = a + nb + c
        a = (n-2m) * b - c

        ****** Step 2: 
        pacer1 start from head with pace 1, 
        pacer2 start from c with pace 1.
        they must meet at the start of the loop.  



        NOTE: not all paces works
        1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |         |
                   ---------
        Suppose pacer2 takes pace 4,
        then they meet at 4 in step 1;
        then they never meet in step 2.

        */

        if (head == nullptr) return nullptr;

        bool ret {false};
                
        ListNode* pacer1 = head;
        ListNode* pacer2 = head;

        //step 1
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

        if (!ret) return nullptr;

        //step 2
        pacer1 = head;
        while (pacer1 != pacer2) {
            pacer1 = pacer1->next;
            pacer2 = pacer2->next;
        }
        return pacer1;

    }
};
