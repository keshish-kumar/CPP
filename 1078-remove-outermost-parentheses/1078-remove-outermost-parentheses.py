class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ""
        cnt = 0
        for char in s:
            if cnt == 0 and char == '(':
                cnt +=1
            elif char == '(':
                cnt +=1
                ans += char
            elif cnt ==1 and char == ')':
                cnt-=1
            else:
                cnt -=1
                ans += char
        return ans
            


        