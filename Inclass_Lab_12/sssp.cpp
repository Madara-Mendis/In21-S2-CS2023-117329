#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

// Function to find the city with the minimum distance value
int findMinTime(const vector<int>& time, const vector<bool>& visited) {
    int minTime = INF;
    int minIndex = -1;

    for (int i = 0; i < time.size(); ++i) {// Iterate through all cities
        if (!visited[i] && time[i] < minTime) { // Check if the city is unvisited and has a smaller time value
            minTime = time[i];//updates minTime with the new minimum time
            minIndex = i;//store the index of the city with the current minimum time.
        }
    }

    return minIndex;
}

// Dijkstra's algorithm implementation
void dijkstra(const vector<vector<int>>& graph, int src,vector<int>& time) {//finds the shortest time from the source city to all other cities in the graph.
    int numCities = graph.size();
    vector<bool> visited(numCities, false);

    // Initialize the distance vector
    time.resize(numCities, INF);
    time[src] = 0;

    for (int i = 0; i < numCities - 1; ++i) {// Iteratively find the shortest time for each city
        int u = findMinTime(time, visited);

        visited[u] = true;

        for (int v = 0; v < numCities; ++v) {
            // Check if the city v is unvisited, there is a connection between u and v,the time from the source city to u is not infinite, and the new timefrom the source city to v is smaller than the current time value
            if (!visited[v] && graph[u][v] != 0 && time[u] != INF && time[u] + graph[u][v] < time[v]) {
                time[v] = time[u] + graph[u][v];//update the shortest time from the source city to city v
            }
        }
    }

}
int main()
{
    vector<vector<int>> graph;

    graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();
    vector<int> times;

    // Choose the starting city as 0
    int sourceCity = 5;
    int sum=0;
    double avg;

    dijkstra(graph, sourceCity, times);

    cout << "Shortest time from City " << (sourceCity) << ":\n";
    for (int i = 0; i < numCities; ++i) {
        if(i!=sourceCity){//taking the shortest times from each city from source city
             cout << "Distance of node " << (i) << ": " << times[i] << "\n";
             sum+=times[i];//taking the total time that spent to travel to every city from the source city
        }

    }
    avg=(sum/5.0);//calculation of average time taken by each city travel
    cout<<"Average time from City "<< (sourceCity)<< " : " << avg << "\n";
    return 0;
}

