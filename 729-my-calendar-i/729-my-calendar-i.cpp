class MyCalendar
{
public:
    map<int, int> tree;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = tree.upper_bound(start);
        if (it != tree.end() && (*it).second < end)
            return false;
        tree.insert({end, start});
        return true;
    }
};