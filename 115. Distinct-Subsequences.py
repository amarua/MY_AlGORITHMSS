class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        slen, tlen = len(s), len(t)
        dp = [[0 for j in range(slen+1)] for i in range(tlen+1)]
        for j in range(slen+1):
            dp[0][j]=1
        
        for i in range(tlen):
            for j in range(slen):
                if t[i] == s[j]:
                    dp[i+1][j+1]=dp[i][j] + dp[i+1][j]
                else:
                    dp[i+1][j+1]=dp[i+1][j]
                    
        return dp[tlen][slen]

# Example 1:

# Input: s = "rabbbit", t = "rabbit"
# Output: 3

# Example 2:

# Input: s = "babgbag", t = "bag"
# Output: 5