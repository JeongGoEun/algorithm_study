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
- dp[i-1]�� �����θ� ó���Ϸ��� �ؼ� ������ ���� �ʾҴ�.
- �ٸ� ����(cur)�� ���� �����ϴ� ���� ���ذ� �ƴ�.
*/