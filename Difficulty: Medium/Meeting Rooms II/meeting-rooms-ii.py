import heapq
class Solution:
    def minMeetingRooms(self, start, end):
        min_heap=[]
        intervals = []
        for i in range(0,len(start)):
            intervals.append([start[i],end[i]])
        intervals.sort()
        i=0
        ans =0
        while i<len(intervals):
            while len(min_heap)!=0 and min_heap[0]<=intervals[i][0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap,intervals[i][1])
            ans = max(ans,len(min_heap))
            i+=1
        return ans
