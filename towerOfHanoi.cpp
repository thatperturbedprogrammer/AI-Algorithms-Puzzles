#include<stdio.h>
#include<stdlib.h>

#include<iostream>
// #include<conio.h>

using std::cout;
using std::cin;
using std::endl;

void tower(int a, char from, char aux, char to){
    if(a==1){
        cout << "Move disk 1 from " << from << " to " << to << endl;        // no aux 
        return;
    }

    else {
        tower(a-1, from, to, aux);
        cout << "Move disk " << a <<" from " << from << " to " << to << endl;        // aux 
        tower(a-1, aux, from, to);
    }
}

int main(){
    // clrscr();

    cout << "Tower of Hanoi" << endl;

    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    tower(n, 'A', 'B', 'C');

    // getch();
    return 0;
}










// Notes:
/*

tower(a, from, aux, to)

else{
tower(a-1, from, to, aux)
cout
tower(a-1, aux, from, to)
}


1 - aux bich me
2 - aux last me
3 - aux pehle
*/