class MinStack
{
public:
    /** initialize your data structure here. */
    long long int *arr;
    long long int tp;
    long long int mini;
    MinStack()
    {
        arr = new long long int[30000];
        tp = -1;
        mini = LONG_MAX;
    }

    void push(long long int val)
    {
        if (val >= mini || tp == -1)
            arr[++tp] = val;
        else
            arr[++tp] = 2 * val - mini;
        if(tp==0)
            mini=val;
        else
            mini = val < mini ? val : mini;
    }

    void pop()
    {
        if (arr[tp] < mini)
            mini = 2 * mini - arr[tp];
        tp--;
    }

    long long int top()
    {
        return arr[tp]<mini?mini:arr[tp];
    }

    long long int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */