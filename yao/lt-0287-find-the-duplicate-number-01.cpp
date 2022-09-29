class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        think the array as a Linked List
        say nums[i],
        i is current pos,
        while the value of nums[i] is the next pos.

        nums[i] -> nums[nums[i]] -> nums[nums[nums[i]]]

        because it contains duplicate numbers (more than one times), so the Linked List must have cycle.
        */

        int pacer1 = nums[0];
        int pacer2 = nums[0];

        //step 1
        while (true) {
            pacer1 = nums[nums[pacer1]];
            pacer2 = nums[pacer2];
            if (pacer1 == pacer2) {
                break;
            }
        }

        //step 2
        pacer1 = nums[0];
        while (pacer1 != pacer2) {
            pacer1 = nums[pacer1];
            pacer2 = nums[pacer2];
        }
        return pacer1;        
    }

};
