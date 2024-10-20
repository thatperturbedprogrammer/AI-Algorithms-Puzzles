#include<stdio.h>
#include<conio.h>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int cost(int arr[10], int n){
    int c = 0;

    for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(arr[j]<arr[i]){     // is -> 5,1  we need -> 1,5
            c++;
        }
    }
    }

    return c;
}


void swap(int arr[10], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){


int arr[10];

int n; // input from user 
int bestCost;
int newCost;

int i;
// cout << "Enter total elements";
// cin >> n;
// cout << "Enter array elements";

// for(i=0;i<n;i++){
//     cin >> arr[i];
// }

bestCost = cost(arr, n);


// After entering array elements

while(bestCost>0){
    for(i=0;i<n-1;i++){

        // first swap then calculate new Cost
        swap(arr, i, i+1);
        newCost = cost(arr, n);

        if(newCost < bestCost){
            
            // print after swap
            cout << "After swap: \n";
            for(i=0;i<n;i++){
                cout << arr[i] << " ";
            }

            cout << "\n";
            bestCost = newCost;    // best cost = new cost (because it is better than best cost)
        }

        else {
            swap(arr, i, i+1);
        }
    }
}

cout << "\nFinal answer:\n";
for(i=0;i<n;i++){
    cout << arr[i] << " ";
}

return 0;
}