//Class Card

#ifndef DACKOFCARDS_CARD_H
#define DACKOFCARDS_CARD_H

#include <iostream>

using namespace std;

enum Suit {
    Clubs, Diamonds, Hearts, Spades
};

class Card {
    Suit suits;
    int number;
    string description;
public:

    Card() {
        suits = Clubs;
        number = 0;
        description = "Error! 2";
    }

    void setDescription(string str){
        description = str;
    }

    void setNum(int i){
        number = i;
    }

    void setSuit(Suit i){
        suits = i;
    }
    void setDate(int, int);

    bool operator<(Card &obj) {

        if (suits != obj.getSuits() && suits > obj.getSuits())
            return false;

        if (suits != obj.getSuits() && suits < obj.getSuits())
            return true;

        if (number != 1 && obj.getNum() != 1 && number > obj.getNum())
            return false;

        if (number != 1 && obj.getNum() != 1 && number < obj.getNum())
            return true;

        if (number == 1)
            return false;

        if (obj.getNum() == 1)
            return true;

        return false;
    }

    Suit getSuits() {
        return suits;
    }

    int getNum() {
        return number;
    }

    string getDescription() {
        return description;
    }

    Card isBigger(Suit suit, Card cards[]){
        int count=0;
        for(int i=0; i<4; i++){
            if(cards[i].getSuits()==suit){
                count++;
            }
        }

        Card temp[count];
        Card tempor;
        int y=0;
        for(int i=0; i<4; i++){
            if(cards[i].getSuits()==suit){
                temp[y]=cards[i];
                y++;
            }
        }

        tempor = temp[0];
        for(int i=0; i<count-1; i++){
            if(tempor.getNum() < temp[i+1].getNum()){
                tempor=temp[i+1];
            }
        }

        return tempor;

    }

    static int ifHearts(Card temps[]) {
        int tempNum=0;
        for(int i=0; i<4; i++) {
            if (temps[i].getSuits() == Hearts)
                tempNum++;
            if(temps[i].getDescription() == "Club Queen")
                tempNum+=13;
        }
        return tempNum;
    }

};

void Card::setDate(int suit1, int num) {
    switch (suit1) {
        case 1:
            suits = Spades;
            number = num;
            if (number == 1)
                description = "Spade Ace";
            else if (number == 11)
                description = "Spade Jack";
            else if (number == 12)
                description = "Spade Queen";
            else if (number == 13)
                description = "Spade King";
            else {
                string str = to_string(number);
                description = "Spade " + str;
            }
            break;
        case 2:
            suits = Hearts;
            number = num;
            if (number == 1)
                description = "Heart Ace";
            else if (number == 11)
                description = "Heart Jack";
            else if (number == 12)
                description = "Heart Queen";
            else if (number == 13)
                description = "Heart King";
            else {
                string str = to_string(number);
                description = "Heart " + str;
            }
            break;
        case 3:
            suits = Diamonds;
            number = num;
            if (number == 1)
                description = "Diamond Ace";
            else if (number == 11)
                description = "Diamond Jack";
            else if (number == 12)
                description = "Diamond Queen";
            else if (number == 13)
                description = "Diamond King";
            else {
                string str = to_string(number);
                description = "Diamond " + str;
            }
            break;
        case 4:
            suits = Clubs;
            number = num;
            if (number == 1)
                description = "Club Ace";
            else if (number == 11)
                description = "Club Jack";
            else if (number == 12)
                description = "Club Queen";
            else if (number == 13)
                description = "Club King";
            else {
                string str = to_string(number);
                description = "Club " + str;
            }
            break;
        default:
            cout << "Error! 1";
    }
}

#endif //DACKOFCARDS_CARD_H
