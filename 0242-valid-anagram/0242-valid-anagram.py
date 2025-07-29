class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mp1 = {}
        mp2 = {}
        ls = len(s)
        lt = len(t)
        if ls!=lt:
            return False
        for i in range(0,ls):
            if s[i] in mp1:
                mp1[s[i]]+=1
            else:
                mp1[s[i]]=1
            if t[i] in mp2:
                mp2[t[i]]+=1
            else:
                mp2[t[i]]=1
        if mp1==mp2:
            return True
        else:
            return False

        