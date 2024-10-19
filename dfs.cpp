#include<stdio.h>
#include<stdlib.h>

#include<iostream>
// #include<conio.h>

using std::cout;
using std::cin;
using std::endl;

int main(){
    // clrscr();

    // declaring variables
    int i,j,k;

    int n,iv;

    int ed;

    int t=-1;

    // stack
    int stk[10];

    int tree[10][10]={0};

    // user inputs
    cout << "Enter no. of Vertices: ";
    cin >> n;

    cout << "Enter no. of edges: ";
    cin >> ed;


    // Enter EDGES
    cout << "\nEnter EDGES:\n";

    for(k=0; k<ed; k++){
        cin >> i >> j;
        tree[i-1][j-1] = 1; // edge present, edge filled
        tree[j-1][i-1] = 1; // undirected graph
    }


    // initial vertex
    cout << "Enter initial vertex: ";
    cin >> iv;
    iv--; // adusting for 0-based index


    // Visited vertices checking
    bool visited[10] = {false}; // initialize visited[] array

    visited[iv] = true; // mark the initial vertex as visited
    stk[++t] = iv;  // push initial vertex in stack


    // Visited vertices - DFS Output
    cout << "Visited vertices: \n";


    // DFS loop - Stack
    while(t!=-1){

        // output from top of stack
        iv = stk[t--];
        cout << iv+1 << " ";  // convert 0-based to 1-based

        // Explore neighbors
        for(j=0; j<n ;j++){

            // when visited, if present - input in top of DFS stack     [visit and input in stack]
            if(tree[iv][j] == 1 && !visited[j]){ // check for edges and if not visited

                visited[j] = true; // mark as visited
                stk[++t] = j;  // push in stack
            }
        }

    }

    // getch();
    cout << endl;
    return 0;
}