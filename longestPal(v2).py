class Solution:   
    def longestPalindrome(self, s):
        if(s == ""):
            return s
        
        l = len(s)
        dp = [[0 for x in range(l)]for y in range(l)] #declear 2-d table
        
        max = 0
        str = ""
        
        # invariant: 0<=i<=j and 0<=j<=l
        for j in range(0,l):
            for i in range(0,j+1):
                if(i == j): #s[i] is palindrome
                    dp[i][j] = 1
                if(s[i] == s[j]): #s[i] = s[j]
                    if(i == j-1): #s[i..j] = [s[i],s[j]]
                        dp[i][j] = 1
                    if(i < j-1): #s[i..j] = [s[i],...,s[j]]
                        if(dp[i+1][j-1] == 1): #s[i+1..j-1] is palindrome
                            dp[i][j] = 1
                        else: #s[i+1..j-1] is not palindrome
                            dp[i][j] = 0
                    if(dp[i][j] == 1 and j - i + 1 >= max):
                        max = j - i + 1
                        str = s[i:j+1]
        return str

