class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(left.empty() || left.top()>num) left.push(num);
       else right.push(num);

    
       if(right.size()>left.size()) 
           {left.push(right.top());right.pop();}
        if(left.size()>(right.size()+1)){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            // even
            return (left.top()+right.top())/2.0;
        }
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */