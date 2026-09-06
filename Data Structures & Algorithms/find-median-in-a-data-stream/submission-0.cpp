class MedianFinder {
public:
    priority_queue<int> pq;
    
    int size = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        size++;
    }
    
    double findMedian() {
        priority_queue<int> a = pq;
        if (size%2 != 0) {
            while (a.size()-1 > size/2) {
                a.pop();
            }
            return a.top();
        }
        
        while (a.size() > (size/2)+1) {
            a.pop();
        }
        int b = a.top();
        a.pop();
        double res = b + a.top();
        return res/2; 
        
    }
};
