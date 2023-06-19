#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Repository
{
public:
    map<int, T> items;

public:
    Repository(){}; // default
    Repository(vector<T> &init_items)
    {
        for (const T &item : init_items)
        {
            items[items.size()] = item;
        }
    }
    // copy constructor
    Repository(const Repository &other)
    {
        cout << "Copy constructor" << endl;
        items.clear();
        items = other.items;
    }

    // move constructor
    Repository(Repository &&other)
    {
        cout << "Move constructor" << endl;
        items.clear();
        items = move(other.items);
        other.items.clear();
    }

    // move assignment operator
    Repository &operator=(Repository &&other)
    {
        cout << "Move assignment operator" << endl;
        if (this != &other)
        {
            items = move(other.items);
        }
        return *this;
    }

    // copy assignment operator
    Repository &operator=(const Repository &other)
    {
        cout << "Copy assignment operator" << endl;
        if (this != &other)
        {
            items = other.items;
        }
        return *this;
    }

    // destructor
    ~Repository()
    {
        cout << "Destructor" << endl;
        items.clear();
    }

    // find the index of the given item in the repo
    int findIndex(const T &item) const
    {
        for (const auto &pair : items)
        {
            if (pair.second == item)
            {
                return pair.first;
            }
        }
        return -1;
    }

    // adds an item to the repo
    void add(const T &item)
    {
        int index = findIndex(item);
        if (index == -1)
        {
            items.insert(pair<int, T>(size(), item));
            cout << "Added item " << item << " at id " << size() << endl;
        }
        else
        {
            cout << "Item " << item << " already exists at id " << index << endl;
        }
    }

    // addss a vector of items to the repo
    void addItems(const vector<T> &to_add)
    {
        for (const T &item : to_add)
        {
            add(item);
        }
        cout << "items after adding: " << endl;
        displayItems();
    }

    // removed the given item to the repo
    void remove(const T &item)
    {
        auto it = find_if(items.begin(), items.end(), [&](const pair<int, T> &element)
                          { return element.second == item; });

        if (it != items.end())
        {
            cout << "Removed item " << item << " at id " << it->first << endl;
            items.erase(it);
        }
        else
        {
            cout << "Item " << item << " does not exist in the repository" << endl;
        }
    }

    // removes the given vector of items to the repo
    void removeItems(vector<T> &to_remove)
    {
        for (const T &item : to_remove)
        {
            remove(item);
        }
        cout << "items after removing: " << endl;
        displayItems();
    }

    // returns repo size
    int size()
    {
        if (items.empty())
        {
            return 0;
        }
        else
        {
            return items.rbegin()->first + 1;
        }
    }

    // prints out repo items
    void displayItems()
    {
        for (const auto &i : items)
        {
            cout << "Rank: " << i.first << ", Val: " << i.second << endl;
        }
        cout << endl;
    }
};
