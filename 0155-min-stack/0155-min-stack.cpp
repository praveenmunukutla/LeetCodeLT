class MinStack {
    stack<int> sta;
    stack<int> msta;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        if(sta.size() == 0){
            sta.push(x);
            msta.push(x);
        }else{
            int top = msta.top();
            if(x < top)
                msta.push(x);
            else
                msta.push(msta.top());
            sta.push(x);
        }
    }
    
    void pop() {
        if(sta.size() == 0)
            return;
        
        sta.pop();
        msta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return msta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */