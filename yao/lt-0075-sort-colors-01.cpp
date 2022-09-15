   void sortColors(vector<int>& nums) {

        int length = nums.size();
        if (length <= 1) return;
        
        //colors[0]: store the next pos of color "0", and also the first pos of color "1"
        //colors[1]: store the next pos of color "1", and also the first pos of color "2"
        //colors[2]: store the next pos of color "2"
        //all point to pos 0 at the beginning.
        std::vector<int> colors(3, 0);
        const int COLOR_NUMS = 3;
        //int colors[COLOR_NUMS] = {0, 0, 0};
        
        for (int i = 0; i < length; i++ ) {
            int num = nums[i];
            if (colors[num] < i) {
                int pos = i;
                for (int j = COLOR_NUMS; j>num; j--) {
                    if (colors[j-1] < pos) {
                        //replace
                        nums[colors[j-1]] = num;
                        nums[pos] = j;

                        pos = colors[j-1];
                    }
                }
            }

            for (int j = num; j < COLOR_NUMS; j++) {
                colors[j] += 1;
            }
        }
        
    }
