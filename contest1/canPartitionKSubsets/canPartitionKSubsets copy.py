# true iff can partition nums[0..len(nums)] into K equal sum subsets
#first solution is brute force
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
        if rem: return False # k must divide sum(nums)
        #search function in function body
        #treat nums,target as global (in function scope)
        def search(groups):
            if not nums: return True
            v = nums.pop()
            for i, group in enumerate(groups): #iterate list, with indices
                if group + v <= target: #can allocate v into group[i]
                    groups[i] += v #update value of groups[i]
                    if search(groups): return True #if this state leads to a good end
                    groups[i] -= v #else, restore groups[i]
                if not group: break #the configuration of putting v into group[i] is a dead end
                # in another word, no matter where u put v in, it will lead to a dead end
                # thus we break this loop and return false
                # to save some time (as the following groups must be zeros)
            nums.append(v)
            return False
        
        nums.sort() #sort nums first
        if nums[-1] > target: return False #if the last (maximal) element in nums is greater than target
        while nums and nums[-1] == target: #while nums is not empty and the last element of nums is eq to target
            nums.pop() #pop it out
            k -= 1 #its a group of itself

        return search([0] * k) #do search on the remaining nums and groups

"""
        Time complexity: O(k!k^(N-k))

"""
# second solution applies dynamic programming
# by keeping track with memo
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
        if rem or max(nums) > target: return False

        memo = [None] * (1 << len(nums)) #space:O(2^N)
        memo[-1] = True
        def search(used, todo):
            if memo[used] is None:
                targ = (todo - 1) % target + 1
                memo[used] = any(search(used | (1<<i), todo - num)
                                 for i, num in enumerate(nums)
                                 if (used >> i) & 1 == 0 and num <= targ)
            return memo[used]

        return search(0, target * k)

#Time complexity: O(N*2^N)
#a very scary dp solution