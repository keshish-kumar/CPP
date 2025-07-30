class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i in range(0,len(numbers)):
            if target-numbers[i] in mp:
                return [mp[target-numbers[i]],i+1]
            mp[numbers[i]]=i+1
        return []
        
           

            
        