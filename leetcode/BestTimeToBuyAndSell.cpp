class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = 0, sellPrice = 0, j = 0, sum = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            // ������ �� Ŭ ������ ���� - buy
            if (prices[i] < prices[i + 1]) {
                buyPrice = prices[i];   //�� ���� ����

                // �� ���� ���� - i+1���ĺ��� ���� ū ���� ��
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

                //i�� �缳��
                i = j - 1;
            }
        }
        return sum;
    }
};