int longestMountain(vector<int>& nums) {
        int length = nums.size();
        if (length < 3) return 0;

        int pre_num = nums[0];
        int pre_trend {0}; // 0 - flat; -1 - down; 1 - up; 
        int u {0}, d {0}, maxm {0};
        for (int i = 1; i < length; i++) {
            // flat
            if (nums[i] == pre_num) {                
                if (pre_trend == 0) {
                    //do nothing
                }
                else if (pre_trend == -1) {
                    if(u>0 && d>0) maxm = max(maxm, u+d+1);
                    u = 0;
                    d = 0;
                    pre_trend = 0;
                }
                else {
                    u = 0;
                    //d = 0;
                    pre_trend = 0;
                }
                
            }
            // down
            else if (nums[i] < pre_num) {
                if (pre_trend == 0) {
                    //do nothing
                }
                else if (pre_trend == -1) {
                    d++;
                }
                else { //pre_trend == 1                    
                    d++;
                    pre_trend = -1;
                }
            }
            // up
            else {
                if (pre_trend == 0) {
                    u++;
                    pre_trend = 1;
                }
                else if (pre_trend == -1) {
                    if(u>0 && d>0) maxm = max(maxm, u+d+1);
                    d=0;
                    u=1;
                    pre_trend = 1;
                }
                else { //pre_trend == 1
                    u++;
                }
            }
            pre_num = nums[i];
        }

        if(u>0 && d>0) maxm = max(maxm, u+d+1);
        return maxm;        
    }
