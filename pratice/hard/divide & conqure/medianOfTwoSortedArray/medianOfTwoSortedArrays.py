"""
    rule A,B are two sorted arrays
    return median of (A+B) in time O(log(n))
    * A+B <=> list generated after merging A and B
"""
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        A,B,n,m = nums1,nums2,len(nums1),len(nums2)
        if n > m :#we do binary search on A
            A,B = nums2,nums1
            n,m = len(A),len(B)
        if n == 0:#empty array
            if m == 0:
                return 0.0
            else:
                if m % 2 == 1:
                    return B[int(m/2)]
                else:
                    return (B[int(m/2)] + B[int(m/2) - 1])/2.0
            
        i_min = 0
        mid = int((n+m+1)/2)
        i_max = n
        while i_min <= i_max :#binary search on A
            i = int((i_min + i_max)/2)
            j = mid - i
            if i > 0 and A[i-1] > B[j]:
                i_max = i - 1 #focus on lower half of old(A)
            elif i < n and B[j-1] > A[i]:
                i_min = i + 1 #focus on higher half of old(A)
            else:
                #the desired i
                if i == 0:
                    left_max = B[j-1]
                elif j == 0:
                    left_max = A[i-1]
                else:
                    left_max = max(A[i-1],B[j-1])
                
                if (m+n) % 2 == 1: 
                    return left_max
                
                if i == n:
                    right_min = B[j]
                elif j == m:
                    right_min = A[i]
                else:
                    right_min = min(A[i],B[j])
                
                return (left_max + right_min)/2.0
                    