class MedianFinder
{
public:
    priority_queue<long> s, l;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        s.push(num);
        l.push(-s.top());
        s.pop();
        if (s.size() < l.size())
        {
            s.push(-l.top());
            l.pop();
        }
    }

    double findMedian()
    {
        if (s.size() == l.size())
            return ((double)s.top() - (double)l.top()) / 2;
        else
            return s.top();
    }
};