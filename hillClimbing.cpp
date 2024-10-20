#include<stdio.h>
#include<stdlib.h>

#include<iostream>
// #include<conio.h>

using std::cout;
using std::cin;
using std::endl;

int cost(int arr[10], int n){
    int c = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){      // is -> 5 , 1  we need -> 1 , 5   (chota pehle)
                c++;                // matlab cost hai

                // agar aage ka chota toh c++
                // a[j] chota a[i] se toh c++
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
    // clrscr();

    int n, arr[10];

    int i;

    int bestCost, newCost;


    // user input
    cout << "Enter total no. of elements: ";
    cin >> n;
    cout << "Enter array elements: "<< endl;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    bestCost = cost(arr, n);

    // hill climbing
    while(bestCost > 0){

        // matlab cost hai
        // is -> 5,1 we want 1,5 
        for(i=0; i<n-1; i++){
            swap(arr, i, i+1);

            newCost = cost(arr, n);  // after swapaping
            if(newCost < bestCost){

                // means newCost is better so we swapped
                cout << "After swap: " << endl;

                // printing array after swap
                for(i=0; i<n; i++){
                    cout << arr[i] << " ";

                }
                cout << "\n";
                bestCost = newCost;   // updating best cost

            }

            else {
                swap(arr, i, i+1);  // newCost is bigger 
            }
        }
    }

    cout << "\nFinal answer: \n";
    for(i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // getch();
    return 0;
}