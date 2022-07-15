class SmallestInfiniteSet {
public:
    
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<bool> isPopped;
    
    SmallestInfiniteSet() {
        
        for(int i=1;i<1001;i++){
            pq.push(i);
        }
        isPopped.resize(1001);
        
    }
    
    int popSmallest() {
        
        int top = pq.top();
        pq.pop();
        isPopped[top] = true;
        return top;
        
    }
    
    void addBack(int num) {
        
        if(isPopped[num]){
            pq.push(num);
            isPopped[num] = false;
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */