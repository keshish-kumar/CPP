class MedianFinder {
public:
    priority_queue<int> p1; // maximum on top
    priority_queue<int,vector<int>,greater<int>> p2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p1.push(num);

        p2.push(p1.top()) ; p1.pop();

        if(p2.size()>p1.size()){
            p1.push(p2.top()); p2.pop();
        }
    }
    
    double findMedian() {
        if((p1.size()+p2.size())%2 != 0){
            // odd
            return (double) p1.top();
        }
        else{
            return (double)(p1.top()+p2.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */