class Solution(object):
    def largestOddNumber(self, num):
        """
        :type num: str
        :rtype: str
        """
        n = int(num)
        while n>0:
            temp = n%10
            if temp%2 != 0:
                return str(n)
            n = n/10
        return ""

        