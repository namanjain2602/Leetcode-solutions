class MyStack {
public:
    int arr[100];
    int rear=-1;
    int front =-1;
    MyStack() {
        
    }
    
    void push(int x) {
        arr[++rear]=x;
    }
    
    int pop() {
        int x=arr[rear--];
        return x;
    }
    
    int top() {
        return arr[rear];
    }
    
    bool empty() {
        if(front==rear)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */