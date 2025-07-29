class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda x:x[1])
        i=0
        ans = 0
        while i<len(intervals):
            j=i+1
            while j<len(intervals) and intervals[i][1]>intervals[j][0]:
                j+=1
                ans+=1
            i=j
        return ans
            
        