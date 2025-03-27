class Solution {
public:

    bool canReach(vector<int>& arr, int start, vector<bool>& visited) {
    if (start < 0 || start >= arr.size() || visited[start]) return false;
    if (arr[start] == 0) return true;
    
    visited[start] = true;  // Mark as visited
    
    return canReach(arr, start + arr[start], visited) || 
           canReach(arr, start - arr[start], visited);
}

bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    return canReach(arr, start, visited);
}

};