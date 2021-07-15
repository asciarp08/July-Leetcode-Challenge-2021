class MedianFinder {
public:
    /** initialize your data structure here. */
    int n = 0; //total numbers
    //first half numbers : sorted in decreasing order
    priority_queue<int> q1;
    //second half : sorted in increasing order
    priority_queue<int, vector<int>, greater<int>> q2;
    
    MedianFinder() {
        n = 0;
        q1 = priority_queue<int>();
        q2 = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        n++;
        
        if(n%2){
            q1.push(num);
        }
        else{
            q2.push(num);
        }
        
        if(n>1){
            if(q1.top()>q2.top()){
                q2.push(q1.top());
                q1.pop();
                q1.push(q2.top());
                q2.pop();
            }
        }
    }
    
    double findMedian() {
        
        if(n%2){
            return q1.top();
        }
        else{
            return (q1.top()+q2.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
