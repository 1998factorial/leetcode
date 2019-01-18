class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #length of seq of x == right(x) - left(x) + 1

        """
        object list in python3 : 
        create : A = {}
        set val: A[x] = ...
        iterate: for a in A: ...
        get values : A.values()
        """

        left,right,count = {},{},{}
        i = 0
        while i < len(nums):
            if nums[i] not in left:
                left[nums[i]] = i
            if nums[i] not in count:
                count[nums[i]] = 1
            elif nums[i] in count:
                count[nums[i]] += 1
            right[nums[i]] = i
            i += 1
            
        deg = max(count.values()) #degree
        length = 50000
        for n in count:
            if count[n] == deg:
                if length > right[n] - left[n] + 1:
                    length = right[n] - left[n] + 1
        
        return length
        
        