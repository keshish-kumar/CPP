class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp = {}
        for i in range(0,len(strs)):
            temp = ''.join(sorted(strs[i]))
            if temp not in mp:
                mp[temp]=[]
            mp[temp].append(i)
        ans = []

        for i in mp:
            temp=[]
            for j in mp[i]:
                temp.append(strs[j])
            ans.append(temp)
        return ans


        