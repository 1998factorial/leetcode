class Solution:
    
    def one_zero(self,s,i,j):
        if i < 0 or j >= len(s):
            return 0
        if s[i] == '1' and s[j] == '0':
            return 1 + self.one_zero(s,i-1,j+1)
        return 0
    
    def zero_one(self,s,i,j):#string center at (i,j)
        if i < 0 or j >= len(s):
            return 0
        if s[i] == '0' and s[j] == '1':
            return 1 + self.zero_one(s,i-1,j+1)
        return 0
        
        
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        """
        this one is a simple linear search + recursion
        """
        if len(s) < 2:
            return 0
        i = 0
        num = 0
        while i < len(s) - 1:
            if s[i] != s[i+1]:
                num += 1
                if s[i] == '0':
                    num += self.zero_one(s,i-1,i+2)
                else:
                    num += self.one_zero(s,i-1,i+2)
            i += 1
        return num
                
                
                
        