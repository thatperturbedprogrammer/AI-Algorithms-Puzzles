#include<stdio.h>
#include<stdlib.h>

// #include<conio.h>
// #include<stdlib>

#include<iostream>
#include<time.h>
#include<string.h>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(){

    // clrscr();

    int suitNum = 4;                                             // suits in a deck
    int facesNum = 13;                                          // cards in each suit
    int cardNum = 0;                                            // variable to keep track of number of cards
    string card = "";                                           // variable to hold array combos being assigned to vector


    // arrays for card labels
    string suit[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    string face[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};


    // vector to store deck in
    vector<string> Cards;

    // 1 - Generate deck
    // iterate through suits
    for(int i=0; i<suitNum; i++){
        // iterate through faces
        for(int j=0; j<facesNum; j++){

            // declare card
            card = face[j] + " of " + suit[i];

            // add card to vector
            Cards.push_back(card);

            // raise card number
            cardNum++;
        }
    }


    // Shuffle deck
    while(cardNum > 0){
        // random number based on cards left in deck
        int RCard = rand()%cardNum;

        // access
        string drawCard = Cards.at(RCard);

        // remove
        Cards.erase(Cards.begin() + RCard);

        cardNum--;

        cout << drawCard << endl;

    } 

    // getch();

    return 0;
}