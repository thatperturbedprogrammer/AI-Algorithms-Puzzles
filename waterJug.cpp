#include<stdio.h>
#include<stdlib.h>

#include<iostream>
// #include<conio.h>

using std::cout;
using std::cin;
using std::endl;

// declaring variables for capacities
int xcapacity, ycapacity;

// display
void display(int a, int b){
    cout << a << " " << b << endl;
}


// min
int min(int a, int b){
    if(a < b){
        return a;
    }
    else {
        return b;
    }
}


// steps
int steps(int n){
    int x = 0, y = 0, step = 0;

    int temp;

    cout << "Jar A  Jar B" << endl;

    while(x != n){
        if(x == 0){
            x = xcapacity;
            step += 1;

            cout << "\nFill A ";
            display(x, y);
        }
        else if(y == ycapacity){
            y = 0;
            step++;

            cout << "\nEmpty B";
            display(x, y);
        }

        else{
            temp = min(ycapacity - y, x);
            x = x - temp;        // x mein se ghatao.   x mein se nikalo
            y = y + temp;       // y mein badhao.       y mein daalo
            step++;

            cout << "\nPour A in B";
            display(x, y);

        }
    }

    return step;
}


// main
int main(){
    int n, ans;

    // clrscr();

    cout << "Enter the litres of water required to be filled in Jar A: ";                       // Enter Goal for A
    cin >> n;

    cout << "Enter the capacity of Jar A: ";
    cin >> xcapacity;

    cout << "Enter the capacity of Jar B: ";
    cin >> ycapacity;

    ans = steps(n);

    cout << "Steps required: " << ans;

    // getch();

    return 0;
}


// Note :
/*
Steps:

1 - Fill A  (x)
2 - Empty B  (y)
3 - Pour (x in y) [A in B]

*/


/*
Logic:

1 - while(x != n)

2 - if( x == 0 ){                                   [Fill]
    x = xcapacity;
    step += 1;
    cout << "Fill A";
    display(x, y)
}


3 - else if( y == ycapacity){                       [Empty]
    y = 0;
    step++;

    cout << "Empty B";
    display(x, y)
}


4 - else{                                           [Pour]
    temp = min(ycapacity - y, x)
    x = x - temp
    y = y + temp
    step++

    cout << "Pour A in B";
    display(x, y)

}

*/




// Logic explained:
/*

while(x != n)

1 - if (x == 0)
agar x khali hai toh                    [Fill A]   x = xcapacity

2 - else if(y == ycapcity)
agar y bhara hai toh                    [Empty B]  y = 0

3 - else                                [Pour A in B]     'x' ka 'y' mein daalo 
temp = min(ycapacity - y, x)
x = x - temp
y = y + temp
*/