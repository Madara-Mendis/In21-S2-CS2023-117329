#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;// Label of the node
    list<int> neighbours;// List of neighbours
};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        nodes[u-1].neighbours.push_back(v);// Adding v to the neighbours of u
        nodes[v-1].neighbours.push_back(u);// Adding u to the neighbours of v
    }

    void print(){
        for (int i = 0; i < n; i++) {// Looping through each node
            cout << nodes[i].label << " --> ";// Printing the label of the current node
            for (int neighbour : nodes[i].neighbours) {// Looping through each neighbour of the current node
                cout << neighbour << " ";// Printing the label of the neighbour
            }
            cout << endl;// Printing a new line after printing all neighbours of the current node
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 4);
    g->addedge(1, 5);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    //print the graph adjaceny list
    g->print();
}
