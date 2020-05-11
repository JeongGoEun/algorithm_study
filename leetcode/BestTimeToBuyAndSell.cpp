class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = 0, sellPrice = 0, j = 0, sum = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            // 다음이 더 클 때까지 구함 - buy
            if (prices[i] < prices[i + 1]) {
                buyPrice = prices[i];   //살 가격 정함

                // 팔 가격 선택 - i+1이후부터 가장 큰 증가 값
                sellPrice = 0;
                for (j = i + 1; j < prices.size(); j++) {
                    if (sellPrice < prices[j]) {
                        sellPrice = prices[j];
                    }
                    else {
                        break;
                    }
                }

                sum += (sellPrice - buyPrice);

                //i값 재설정
                i = j - 1;
            }
        }
        return sum;
    }
};