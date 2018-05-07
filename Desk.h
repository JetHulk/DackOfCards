//Class Desk

#ifndef DACKOFCARDS_DESK_H
#define DACKOFCARDS_DESK_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Card.h"

class Desk {
    Card cards[52];
public:
    void initialize();

    void shuffle();

    string getCardDescription(int num){
        return cards[num].getDescription();
    }

    Suit getCardSuit(int num){
        return cards[num].getSuits();
    }

    int getCardNum(int num){
        return cards[num].getNum();
    }



    //void deal(Card[], Card[], Card[], Card[]);

    //void sort(Card[]);

   // void display(Card[], Card[], Card[], Card[]);
};

void Desk::initialize() {

    int num = 1;
    for (int i = 0; i < 13; i++) {
        cards[i].setDate(1, num);
        num++;
    }

    num = 1;
    for (int i = 13; i < 26; i++) {
        cards[i].setDate(2, num);
        num++;
    }

    num = 1;
    for (int i = 26; i < 39; i++) {
        cards[i].setDate(3, num);
        num++;
    }

    num = 1;
    for (int i = 39; i < 52; i++) {
        cards[i].setDate(4, num);
        num++;
    }
}

void Desk::shuffle() {
    srand(time(nullptr));
    Card temp;
    int num;

    for (int i = 0; i < 52; i++) {
        num = rand() % (52);
        temp = cards[num];
        cards[num] = cards[i];
        cards[i] = temp;
    }
}

/*void Desk::deal(Card hand1[], Card hand2[], Card hand3[], Card hand4[]) {

    int num = 0;
    for (int i = 0; i < 13; i++) {
        hand1[num] = cards[i];
        num++;
    }

    num = 0;
    for (int i = 13; i < 26; i++) {
        hand2[num] = cards[i];
        num++;
    }

    num = 0;
    for (int i = 26; i < 39; i++) {
        hand3[num] = cards[i];
        num++;
    }

    num = 0;
    for (int i = 39; i < 52; i++) {
        hand4[num] = cards[i];
        num++;
    }
}

void Desk::sort(Card obj[]) {
    Card temp;
    bool count = true;
    while (count) {
        count = false;
        for (int i = 0; i < 12; i++) {
            if (obj[i] < obj[i + 1]) {
                temp = obj[i];
                obj[i] = obj[i + 1];
                obj[i + 1] = temp;
                count = true;
            }

        }
    }
}

void Desk::display(Card hand1[], Card hand2[], Card hand3[], Card hand4[]) {
    cout << left << setw(15) << "HAND 1 " << setw(15) << "HAND 2 " << setw(15) << "HAND 3 " << setw(15) << "HAND 4"
         << endl;
    cout << setw(15) << "----------" << setw(15) << "----------" << setw(15) << "----------" << setw(15) << "----------"
         << endl;
    for (int i = 0; i < 13; i++) {
        cout << left << setw(15) << hand1[i].getDescription()
             << setw(15) << hand2[i].getDescription()
             << setw(15) << hand3[i].getDescription()
             << setw(15) << hand4[i].getDescription() << endl;
    }
}*/

#endif //DACKOFCARDS_DESK_H
