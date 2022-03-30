/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        // 返回最小数组小标->遍历时从到小
        int n = nums.size();
        int bigscore = -1;
        int bigk = -1;
        for(int k = n - 1; k >= 0; k--){
            int score = 0;
            for(int i = 0; i < k; i++){
                if(nums[i] <= i + n - k) score+=1;
            }
            for(int j = k; j <= n - 1; j++){      //bug为j <= 少写了=
                if(nums[j] <= j - k) score+=1;
            }
            if(score >= bigscore){
                 bigscore = score;
                 bigk = k;
            }
        }

        return bigk;
    }
};
// @lc code=end


