// dpは & 1 を使うと空間が 2つ で済む
int dp[2];
int i; dp[i & 1]; dp[(i + 1) & 1];