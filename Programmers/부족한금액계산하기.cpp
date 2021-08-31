using namespace std;

long long solution(int price, int money, int count)
{
    long long dp[2500] = {0,};
    long long sum=price;
    dp[0] = price;
    for(int i=1;i<count;i++) {
        dp[i] = dp[i-1]+price;
        sum+=dp[i];
    }
    return sum-money < 0 ? 0 : sum-money;
}