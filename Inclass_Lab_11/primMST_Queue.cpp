#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define NUM_STREETS 6   //defines a constant value for the number of nodes in the graph

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(NUM_STREETS, -1);//store the parent vertex and is initialized with -1 for all vertices, indicating that no parent has been assigned yet.
    vector<int> key(NUM_STREETS, INT_MAX);//store the key values and is initialized with a maximum value INT_MAX for all vertices, indicating that their key values are initially set to infinity.
    vector<bool> mstSet(NUM_STREETS, false);//store the MST set information for each vertex and is initialized with false for all vertices, indicating that no vertices have been included in the MST yet.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//stores pairs of key values and vertex indicesand pairs are sorted in ascending order based on key values.

    key[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {//continues until the priority queue becomes empty.
        int u = pq.top().second;//retrieves the vertex index associated with the minimum key value.
        pq.pop();//the pair is removed from the queue

        mstSet[u] = true;//vertex u is marked as visited

        for (int v = 0; v < NUM_STREETS; v++) {
                //checks if there exists an edge between vertices u and v in the graph. If the value is non-zero, it indicates the presence of an edge.
                //checks if the vertex v has not been included in the minimum spanning tree (MST) yet.
                //checks if the weight of the edge between u and v is smaller than the current key value of v. key[v] represents the minimum weight of an edge connecting vertex v to the partial MST constructed so far.
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;//if satisfied conditions,vertex v can be reached from u with a smaller weight edge than its current key value and so update parent of vertex v to u
                key[v] = graph[u][v];//update the key value of vertex v to the weight of the edge between u and v
                pq.push(make_pair(key[v], v));//updates the priority queue with the new key value for vertex v
            }
        }
    }

    cout << "Wiring Connections \tDistance\n";
    int min_tot_dist = 0;//initialising the minimum total distance or cost of the MST to 0.
    for (int i = 1; i < NUM_STREETS; i++) {
        min_tot_dist += graph[i][parent[i]];//calculate the minimum total distance of the MST.
        cout << parent[i] << " - " << i << "\t\t\t" << graph[i][parent[i]] << "\n";//prints the wiring connection between the parent vertex and the current vertex, along with the corresponding distance or weight.
    }
    cout << "Minimum total distance : " << min_tot_dist;//prints the minimum total distance of the MST.
}

int main() {
    vector<vector<int>> graph = {{0, 3, 0, 0, 0, 1},
                                 {3, 0, 2, 1, 10, 0},
                                 {0, 2, 0, 3, 0, 5},
                                 {0, 1, 3, 0, 5, 0},
                                 {0, 10, 0, 5, 0, 4},
                                 {1, 0, 5, 0, 4, 0}};

    primMST(graph);

    return 0;
}
