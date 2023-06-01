#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));

    vector<string> items = {"iPhone14", "IPad", "Headphones", "BackRoller", "Bike"};
    vector<string> stores = {"BestBuy", "Amazon", "eBay", "OfficeMax", "Staples"};
    map<string, map<string, double>> black_friday_wishlist;

    // filling in random prices
    for (int i = 0; i < items.size(); i++)
    {
        for (int j = 0; j < stores.size(); j++)
        {
            black_friday_wishlist[items[i]][stores[j]] = rand() % 1500 + 50;
        }
    }

    vector<string> my_items;
    vector<string> my_stores;

    for (const auto &my_pair : black_friday_wishlist)
    {
        const string &item = my_pair.first;
        my_items.push_back(item);
        for (const auto &with_price : my_pair.second)
        {
            const string &store = with_price.first;
            if (find(my_stores.begin(), my_stores.end(), store) == my_stores.end())
            {
                my_stores.push_back(store);
            }
        }
    }

    sort(my_items.begin(), my_items.end());
    sort(my_stores.begin(), my_stores.end());

    items = my_items;
    stores = my_stores;
    // printing out the grid of stores x items
    cout << "Name:       ";
    for (int i = 0; i < stores.size(); i++)
    {
        cout << setw(10) << stores[i] << "   ";
    }
    cout << endl;

    cout << fixed << setprecision(2);
    for (const auto &thing : black_friday_wishlist)
    {
        cout << setw(10) << thing.first << "  ";
        for (const auto &shop : thing.second)
        {
            cout << setw(10) << shop.second << "   ";
        }
        cout << endl;
    }
    cout << endl;

    // avg calculation
    vector<pair<string, double>> average_prices;
    for (const auto &thing : black_friday_wishlist)
    {
        double sum = 0;
        for (const auto &shop : thing.second)
        {
            sum += shop.second;
        }
        double average = sum / stores.size();
        average_prices.push_back(make_pair(thing.first, average));
    }

    sort(average_prices.begin(), average_prices.end(), [](const pair<string, double> &a, const pair<string, double> &b)
         { return a.second < b.second; });

    cout << endl;
    cout << "Average Prices (Ascending Order):" << endl;
    for (const auto &price : average_prices)
    {
        cout << setw(12) << price.first << ", Avg: " << price.second << endl;
    }
    cout << endl;

    for (const auto &item : items)
    {
        string best_store;
        double best_price = numeric_limits<double>::max();

        for_each(stores.begin(), stores.end(), [&](const string &store)
                 {
        
            if (black_friday_wishlist[item][store] < best_price) {
                best_price = black_friday_wishlist[item][store];
                best_store = store;
            } });

        cout << item << ", Best Price offered by: " << best_store << ", with a cost of $" << best_price << endl;
    }

    return 0;
}