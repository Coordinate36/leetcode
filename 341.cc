#include <iostream>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto && n : nestedList) {
            nested2List(n);
        }
        cur = 0;
    }

    int next()
    {
        return intList[cur++];
    }

    bool hasNext()
    {
        return cur < intList.size();
    }
private:
    vector<int> intList;
    int cur;
    void nested2List(NestedInteger& nestedInt) {
        if (nestedInt.isInteger()) {
            intList.emplace_back(nestedInt.getInteger());
        } else {
            const vector<NestedInteger> &list = nestedInt.getList();
            for (auto n : list) {
                nested2List(n);
            }
        }
    }
};

/*
    Your NestedIterator object will be instantiated and called as such : NestedIterator i(nestedList);
while (i.hasNext())
    cout << i.next();
*/