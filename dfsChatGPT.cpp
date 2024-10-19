#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

#define MAX_VERTICES 10

int main() {
    // declaring variables
    int i, j, k;
    int n, iv, ed;

    // stack
    int stk[MAX_VERTICES];
    int top = -1;

    // adjacency matrix
    int tree[MAX_VERTICES][MAX_VERTICES] = {0}; // initialize to 0

    // user inputs
    cout << "Enter no. of Vertices: ";
    cin >> n;

    cout << "Enter no. of edges: ";
    cin >> ed;

    // Enter EDGES
    cout << "\nEnter EDGES (format: vertex1 vertex2):\n";
    for (k = 0; k < ed; k++) {
        cin >> i >> j;
        // Assuming the input vertices are 1-based, adjust them to 0-based
        tree[i - 1][j - 1] = 1; // edge present
        tree[j - 1][i - 1] = 1; // if undirected graph, add this line
    }

    // initial vertex
    cout << "Enter initial vertex (1 to " << n << "): ";
    cin >> iv;
    iv--; // adjusting for 0-based index

    // Visited vertices
    bool visited[MAX_VERTICES] = {false}; // initialize visited array
    visited[iv] = true; // mark the initial vertex as visited

    // DFS loop - Stack
    stk[++top] = iv; // push initial vertex onto the stack

    cout << "Visited vertices: ";

    while (top != -1) {
        // Output the vertex at the top of the stack
        iv = stk[top--]; // pop from stack
        cout << iv + 1 << " "; // output, adjusting for 1-based index

        // Explore neighbors
        for (j = 0; j < n; j++) {
            if (tree[iv][j] == 1 && !visited[j]) { // check for edges and if not visited
                visited[j] = true; // mark as visited
                stk[++top] = j; // push onto stack
            }
        }
    }

    cout << endl;
    return 0;
}
