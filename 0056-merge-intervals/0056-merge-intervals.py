class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = []
        intervals.sort()
        i=0
        while i<len(intervals):
            j=i+1
            while j<len(intervals) and intervals[i][1]>=intervals[j][0]:
                intervals[i][0] = min(intervals[i][0],intervals[j][0])
                intervals[i][1] = max(intervals[i][1],intervals[j][1])
                j+=1
            ans.append(intervals[i])
            i=j
        return ans
            


        