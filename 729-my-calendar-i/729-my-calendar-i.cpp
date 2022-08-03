class MyCalendar
{
public:
    map<int, int> tree;
    MyCalendar()
    {
        tree = *(new map<int, int>);
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