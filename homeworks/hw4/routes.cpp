#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Distance
{
private:
    string target;
    int distance;

public:
    Distance(const string &city, int dist)
    {
        target = city;
        distance = dist;
    }
    string getTarget() const
    {
        return target;
    }
    int getDistance() const
    {
        return distance;
    }
    int compare(const Distance &other) const
    {
        return distance - other.distance;
    }
    // needed this operator since we are using a set of distances in the mapping
    bool operator<(const Distance &other) const
    {
        return compare(other) < 0;
    }
};

// a helper struct to compare two distances
struct DistanceComparator
{
    bool operator()(const Distance &d1, const Distance &d2) const
    {
        return d1.compare(d2) > 0;
    }
};

class Routes
{
private:
    map<string, set<Distance>> route_map;
    string input_file;
    string start_city;

public:
    Routes(const string &fileName)
    {
        input_file = fileName;
        populateFiles();
    }

    // reads the map.txt file and places the destination and distance in the corresponding src city's spot
    // in the route map
    void populateFiles()
    {
        ifstream map_file(input_file);
        string src, dest;
        int distance;

        if (!map_file)
        {
            cout << "Cannot open map file!" << endl;
            return;
        }

        // this just reads in the first line and sets the start city as the first city (which is pendleton)
        if (map_file >> src >> dest >> distance)
        {
            start_city = src;
            route_map[src].emplace(dest, distance);
            //  route_map[dest].emplace(src, distance);
        }
        // makes the undirected graph connection
        while (map_file >> src >> dest >> distance)
        {
            route_map[src].emplace(dest, distance);
            // route_map[dest].emplace(src, distance);
        }
    }

    // finds the shortest known distance using priority queue/ dijrstka's algo
    map<string, int> findShortestKnownDistance()
    {
        map<string, int> shortestKnownDistance;
        priority_queue<Distance, vector<Distance>, DistanceComparator> distance_queue;

        distance_queue.emplace(start_city, 0);

        while (!distance_queue.empty())
        {
            Distance curr = distance_queue.top();
            distance_queue.pop();
            string target = curr.getTarget();
            int distance = curr.getDistance();

            if (shortestKnownDistance.find(target) != shortestKnownDistance.end())
                continue;

            shortestKnownDistance[target] = distance;

            for (const auto &neighbor : route_map[target])
            {
                distance_queue.emplace(neighbor.getTarget(), distance + neighbor.getDistance());
            }
        }

        return shortestKnownDistance;
    }
};

// comparator to sort the map<string, int> in ascending order by distances
bool compareDistances(const pair<string, int> &d1, const pair<string, int> &d2)
{
    return d1.second < d2.second;
}

int main()
{
    Routes routes("map.txt");

    map<string, int> shortestDistances = routes.findShortestKnownDistance();
    vector<pair<string, int>> distancesVector(shortestDistances.begin(), shortestDistances.end());
    sort(distancesVector.begin(), distancesVector.end(), compareDistances);

    // Write the shortest distances to "shortestDistances.txt"
    ofstream outputFile("shortestDistances.txt");
    if (outputFile)
    {
        int curr_pos = 0;
        for (const auto &entry : distancesVector)
        {

            if (curr_pos == 0)
            {
                outputFile << "shortest distances from " << entry.first << ":" << endl;

                curr_pos += 1;
            }
            else
            {
                outputFile << "- " << entry.first << " " << entry.second << endl;
            }
        }
        cout << "check shortestDistances.txt for shortest distances" << endl;
    }
    else
    {
        cout << "Cannot open shortestDistances.txt! " << endl;
        return 1;
    }

    return 0;
}
