class MedianFinder {
public:
    priority_queue<int> maxHeap; // all the items smaller
    priority_queue<int, vector<int>, greater<>> minHeap; // all the items bigger
    // By construction the top of the minHeap is the median  
  
    MedianFinder() {}
    
    void addNum(int num) {
      if(minHeap.empty() || num >= minHeap.top()){
        minHeap.push(num);
        if(minHeap.size() > maxHeap.size()+1){
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
      }else{
        maxHeap.push(num);
        if(maxHeap.size() > minHeap.size()){
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        }
      }
    }
    
    double findMedian() {
      // Check if the size is odd
      if(maxHeap.size() == minHeap.size()){
        return (double)(minHeap.top()+maxHeap.top())/2;
      }else{
        return minHeap.top();
      }
    }
};