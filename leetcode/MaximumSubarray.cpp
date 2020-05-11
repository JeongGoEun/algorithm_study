class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], MAX = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]);
            MAX = max(MAX, cur);
        }

        return MAX;
    }
};
/*
- dp[i-1]의 값으로만 처리하려고 해서 생각이 나지 않았다.
- 다른 변수(cur)을 놓고 정의하니 쉽게 이해가 됐다.
*/