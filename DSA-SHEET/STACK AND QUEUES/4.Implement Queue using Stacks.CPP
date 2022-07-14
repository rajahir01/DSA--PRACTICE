// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
   public:
   stack<int> que1, que2;
    MyQueue() {
        
    }
    
    void push(int x) {
        que1.push(x);
        
    }
    
    int pop() {
        
        if(que2.size()!=0)
        {
            int xx = que2.top();
            que2.pop();
            return xx;
        }
        
        while(que1.size()!=0)
        {
            que2.push(que1.top());
            que1.pop();
        }
        
        int x = que2.top();
        que2.pop();
        return x;
        
    }
    
    int peek() {
        
        if(que2.size()!=0)
        {return que2.top();}
        
        
        while(que1.size()!=0)
        {
            que2.push(que1.top());
            que1.pop();
        }
        
        int x = que2.top();
        
        
        return x;
        
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
