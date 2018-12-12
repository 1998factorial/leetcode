class Solution:
    #don't know how to create an array of strings in python yet :(
    #so, strictly speaking, this soln is not dp
    def isPal(self,s,i,j):
        f = True
        while(i <= j):
            if(s[i] != s[j]):
                f = False
                break
            i = i + 1
            j = j - 1
        return f
    
    def Max(self,a,b):
        if(len(a) >= len(b)):
            return a
        return b
    
    def P(self,s,i,j): #return the longest palindrome between s[i] and s[j]
        if(i > j):
            return ""
        if(i == j):
            return s[i:j+1]
        if(s[i] == s[j]):
            if(self.isPal(s,i,j)): # if s[i..j] is palindrome
                return s[i:j+1]
        return self.Max(self.P(s,i+1,j),self.P(s,i,j-1))
        
    def longestPalindrome(self, s):
        str = ""
        str = self.P(s,0,len(s)-1)
        return str

