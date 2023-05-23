class KthLargest(object):

    def __init__(self, k, nums):
        self.heap = []
        self.k = k
        
        for num in nums:
            self.add(num)
        
    def add(self, val):
        
        heapq.heappush(self.heap, val)
        
        # if after adding the new item causes 
        # the heap size to increase beyond k, 
        # then pop out the smallest element 
        if len(self.heap) > self.k: 
            heapq.heappop(self.heap)
            
        return self.heap[0]