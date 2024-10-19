#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;

// declaring variables
int tree[10][10];
int i, j, k;
int n;

// queue
int qu[10];
int front = 0, rare = 0;
int v; // initial vertex


// main
int main(){
    int ed; // edge

    // clrscr();

    // user inputs
    cout << "Enter no. of Vertices: ";
    cin >> n;
    
    cout << "Enter no. of Edges: ";
    cin >> ed;


    // Enter EDGES
    cout << "\nEnter EDGES\n";
    for(k=1; k<=ed; k++){
        cin >> i >> j;
        tree[i][j] = 1;  // edge present, edge filled
        // cout << "edge present, edge filled: " << tree[i][j] << endl << endl;
    }


    // initial vertex
    cout << "Enter initial vertex: ";
    cin >> v;


    // Visited vertices - BFS Output
    cout << "Visited vertices: \n";
    cout << v << " ";


    // BFS loop - Queue
    k=1;
    while(k<n){
        for(j=1;j<=n;j++){
            // when visited, if present - input in rare of BFS queue      [visit and input in queue]
            if(tree[v][j]!=0){
                qu[rare++] = j;
            }
        }

        // output from front of queue
        v = qu[front++];
        cout << v << " ";
        k++;

    }

    getch();
    return 0;

}


























// Notes:
// vertex = corner
// edge = straight line


