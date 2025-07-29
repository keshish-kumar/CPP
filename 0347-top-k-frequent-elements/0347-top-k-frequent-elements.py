class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # first we will store everything in dictionary 
        mp= {}
        for i in nums:
            if i not in mp:
                mp[i]=1
            else:
                mp[i]+=1
        pq = []
        for i in mp:
            heapq.heappush(pq,(-mp[i],i))
        ans = []
        for i in range(0,k):
            ans.append(heapq.heappop(pq)[1])
        return ans