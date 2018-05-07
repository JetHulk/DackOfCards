//Homework 3
//Author: Aleksandra Sukhodolskaia
//The program shuffles and deals cards to 4 people, desplaying them in the order.

#include <iostream>
#include "Card.h"
#include "Desk.h"
#include <iomanip>

using namespace std;

class Player{
    Card hand[13];
    bool played[13];
    int points;
    string name;
public:
    void setName(string str){
        name = str;
    }

    void ifHearts(int choice){
        if(hand[choice].getSuits()==Hearts)
             points+=1;
    }

    int getPoints(){
        return points;
    }

    void setDescriptionHand(string str, int i){
        hand[i].setDescription(str);
    }
    string getName(){
        return name;
    }

    string getDescriptionHand(int number){
        return hand[number].getDescription();
    }

    void sortHand(){
        Card temp;
        bool count = true;
        while (count) {
            count = false;
            for (int i = 0; i < 12; i++) {
                if (hand[i] < hand[i + 1]) {
                    temp = hand[i];
                    hand[i] = hand[i + 1];
                    hand[i + 1] = temp;
                    count = true;
                }

            }
        }

    }

    void displayHand(){

        cout << "My Hand: " << endl;
        cout << "----------" << endl;
        for (int i = 0; i < 13; i++) {
            cout << i+1 << ": " << hand[i].getDescription() << endl;
        }
    }

    void addCard(Desk& obj, int num, int numO){
        hand[num].setDescription(obj.getCardDescription(numO));
        hand[num].setNum(obj.getCardNum(numO));
        hand[num].setSuit(obj.getCardSuit(numO));
    }

    Card playCard(Suit lead, bool leader){

        for(int i=0; i<13; i++){
            if(hand[i].getSuits()==lead)
        }

    }

    int findClubTwo(){

        for(int i=0; i<13; i++){
            if(hand[i].getDescription() == "Club 2")
                return i;
        }
        return -1;

    }
};

void displayPlayers(int, int, int, int, int, int, int, int, int);

void displayCard(int, Player&);

int main() {

    Desk desk;

    desk.initialize();
    desk.shuffle();

    Player one, two, three, four;
    one.setName("Me");
    two.setName("Snoop Dog");
    three.setName("Lady Gaga");
    four.setName("Elton John");

    int num=0;
    for(int i=0; i<52; i++){
        one.addCard(desk, num, i);
        i++;
        two.addCard(desk, num, i);
        i++;
        three.addCard(desk, num, i);
        i++;
        four.addCard(desk, num, i);
        num++;
    }

    int choice;

    displayPlayers(0, 0, 0, 0, 0, 0, 0, 0, 0);

    int oneT = 0, twoT=0, threeT=0, fourT=0;

    cout << "Round " << 1 << endl;

    if(one.findClubTwo() != -1){
        choice = one.findClubTwo();
        displayCard(choice, one);
        one.displayHand();
    } else if(two.findClubTwo() != -1){
        choice = two.findClubTwo();
        displayCard(choice, two);
    } else if(three.findClubTwo()!=-1){
        choice = three.findClubTwo();
        displayCard(choice, three);
    } else
    {
        choice = four.findClubTwo();
        displayCard(choice, four);

    }

    for(int i=1; i<=13; i++){

        oneT +=one.getPoints();
        twoT+=two.getPoints();
        threeT+=three.getPoints();
        fourT+=four.getPoints();
        displayPlayers(i, one.getPoints(), oneT, two.getPoints(), twoT, three.getPoints(), threeT, four.getPoints(), fourT);


    }




    return 0;
}

void displayPlayers(int round, int one, int totalOne, int two, int totalTwo, int three, int totalThree, int four, int totalFour){

    cout << right << setw(30) << "Points" << " " << "Points" << endl;
    cout << setw(24) << left << "Player" << "Round " << round << " "  << "Total" << endl;
    cout << setw(24) << left << "--------" << right << "-----" << " -----" << endl;
    cout << setw(28) << left << "Me" << one << "   " << totalOne << endl;
    cout << setw(28) << "Snoop Dog" << left << two << "   " << totalTwo << endl;
    cout << setw(28) << "Lady Gaga" << left << three << "   " << totalThree << endl;
    cout << setw(28) << "Elton John" << left << four << "   " << totalFour << endl;
 }

void displayCard(int choice, Player& firstOne){

    cout << firstOne.getName() << ": " << firstOne.getDescriptionHand(choice) << endl;
    firstOne.ifHearts(choice);
    firstOne.setDescriptionHand(" ", choice);

}

