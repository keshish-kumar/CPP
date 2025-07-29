#User function Template for python3

class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,start,end):
        # code here
        ans = []
        for i in range(0,len(start)):
            ans.append([start[i],end[i]])
        ans.sort(key=lambda x:x[1])
        
        i=0
        count =0
        while i<len(ans):
            j=i+1
            while j<len(ans) and ans[i][1]>=ans[j][0]:
                count+=1
                j+=1
            i=j
        return len(ans)-count