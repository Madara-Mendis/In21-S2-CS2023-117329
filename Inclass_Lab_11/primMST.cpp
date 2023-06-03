#include <iostream>
#include <climits>

#define NUM_STREETS 6  //defines a constant value for the number of nodes in the graph
using namespace std;

//find the vertex with the minimum key value
int findMinKey(int key[], bool mstSet[]) {
    //minCost is initialized with the maximum integer value
    //minIndex keeps track of the index of the vertex with the minimum key value.
    int minCost = INT_MAX, minIndex;

    for (int v = 0; v < NUM_STREETS; v++)
        if (mstSet[v] == false && key[v] < minCost)//checks if the vertex v is not yet included in the MST and if the key value of vertex v is less than the current minimum cost
            minCost = key[v], minIndex = v;//updates with the new minimum cost and stored its index

    return minIndex;//returns index of the vertex with the minimum key value.
}
//print the minimum spanning tree (MST) obtained from Prim's algorithm
void printMST(int parent[], int graph[NUM_STREETS][NUM_STREETS]) {
    int min_tot_dist=0;//initialising the minimum total distance or cost of the MST to 0.
    cout << "Wiring Connections \tDistance\n";
    for (int i = 1; i < NUM_STREETS; i++){
        min_tot_dist+=graph[i][parent[i]];//calculate the minimum total distance of the MST.
        cout << parent[i] << " - " << i << "\t\t\t" << graph[i][parent[i]] << "\n";//prints the wiring connection between the parent vertex and the current vertex, along with the corresponding distance or weight.
    }
    cout<<"Minimum total distance : "<<min_tot_dist;//prints the minimum total distance of the MST.
}

void primMST(int graph[NUM_STREETS][NUM_STREETS]) {
    int parent[NUM_STREETS];  // Array to store the MST
    int key[NUM_STREETS];     // Key values used to pick minimum weight edge
    bool mstSet[NUM_STREETS]; // To represent set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < NUM_STREETS; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;         // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;     // First node is always the root of MST

    // The MST will have V-1 edges
    for (int count = 0; count < NUM_STREETS - 1; count++) {
        int u = findMinKey(key, mstSet);

        mstSet[u] = true;

        // Update key and parent array for adjacent vertices of the picked vertex
        for (int v = 0; v < NUM_STREETS; v++)
            //Checks if there is an edge between vertices u and v. If there is no edge (weight is 0), the condition evaluates to false.
            //Checks if the vertex v is not yet included in the MST
            //Checks if the weight of the edge between u and v is less than the current key value of vertex v
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            //if true,updates the parent of vertex v to be u and updates  the key value of vertex v to be the weight of the edge (u, v)
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[NUM_STREETS][NUM_STREETS] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    primMST(graph);

    return 0;
}
