# this is a navie solution, it excceeds time limit unfortunately.
class Solution:
    def overlap(self,sqr,pos):
        f = True
        if sqr.get('left') <= pos[0]:
            if sqr.get('right') < pos[0]:
                f = False
        else:
            if pos[0]+pos[1]-1 < sqr.get('left'):
                f = False
        return f
    
    def get_height(self,pre,pos,n):
        height = 0
        i = 0
        while i < len(pre): #for all members in pre
            if self.overlap(pre[i],pos): # if their base overlap
                height = max(height,pos[1]+pre[i].get('height')) # pick higher one
            i += 1
        if height == 0:
            pre[n] = {'left': pos[0],'right': pos[1]+pos[0]-1,'height':pos[1]} # no overlap
        else:
            pre[n] = {'left': pos[0],'right': pos[1]+pos[0]-1,'height':height} # has overlap

        i = 0
        while i < len(pre):
            if height < pre[i].get('height'):
                height = pre[i].get('height')
            i += 1
        return height #max height at this moment
        
    def fallingSquares(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        v = [0] * len(positions)
        pre = {}
        i = 0
        while i < len(positions):
            height = self.get_height(pre,positions[i],i)
            v[i] = height
            i += 1
        return v
        
        