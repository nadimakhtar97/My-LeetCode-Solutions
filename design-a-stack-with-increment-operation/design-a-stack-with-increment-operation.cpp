class CustomStack {
public:
    
    int* arr;
    int top = -1;
    int size = 0;
    CustomStack(int maxSize) {
      arr = new int[maxSize];
      this->size = maxSize;
    }
    
    void push(int x) {

      top<size-1 ? arr[++top]=x : NULL;
        
    }
    
    int pop() {
      return top>=0 ? arr[top--]  : -1;
    }
    
    void increment(int k, int val) {
        
        for(int i=0;i<k;i++)
        {
          if(i<=size-1)
          arr[i]+=val;
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */