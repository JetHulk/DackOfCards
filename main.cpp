//Homework 3
//Author: Aleksandra Sukhodolskaia
//The program shuffles and deals cards to 4 people, desplaying them in the order.

#include <iostream>
#include "Card.h"
#include "Desk.h"
#include <iomanip>

using namespace std;

class Player {
    bool played[13];
    int points;
    string name;
public:
    Card hand[13];

    Player(string str, int num) {
        points = num;
        name = str;
    }

    void setName(string str) {
        name = str;
    }

    int getPoints() {
        return points;
    }

    void setPoints(int num){
        points += num;
    }

    void setDescriptionHand(string str, int i) {
        hand[i].setDescription(str);
    }

    string getName() {
        return name;
    }

    string getDescriptionHand(int number) {
        return hand[number].getDescription();
    }

    void sortHand() {
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

    void displayHand() {

        cout << "My Hand: " << endl;
        cout << "----------" << endl;
        for (int i = 0; i < 13; i++) {
            cout << i + 1 << ": " << hand[i].getDescription() << endl;
        }
    }

    void addCard(Desk &obj, int num, int numO) {
        hand[num].setDescription(obj.getCardDescription(numO));
        hand[num].setNum(obj.getCardNum(numO));
        hand[num].setSuit(obj.getCardSuit(numO));
    }

    Card playCard(Suit lead, bool leader) {

        if(findClubTwo()!=-1 && played[findClubTwo()]==false){
            played[findClubTwo()]=true;
            return hand[findClubTwo()];
        }

        if (leader) {
            for (int i = 0; i < 13; i++) {
                if (played[i]==false) {
                    played[i] = true;
                    return hand[i];
                }
            }
        } else {
            for (int i = 0; i < 13; i++) {
                if (hand[i].getSuits() == lead && played[i]==false) {
                    played[i]=true;
                    return hand[i];
                }
            }

            for (int i = 0; i < 13; i++) {
                if (played[i] ==false) {
                    played[i]=true;
                    return hand[i];
                }
            }
        }
    }

    int findClubTwo() {

        for (int i = 0; i < 13; i++) {
            if (hand[i].getDescription() == "Club 2")
                return i;
        }
        return -1;

    }

    Suit getSuitHand(int num){
      return hand[num].getSuits();
    }

};

void displayPlayers(int, int, int, int, int, int, int, int, int);

void displayCard(Player&, string cont);

int main() {

    Desk desk;
    Card played[4];
    string playedName[4];

    desk.initialize();
    desk.shuffle();

    Player people[4] = {Player("Me",0),
                        Player("Snoop Dog",0),
                        Player("Lady Gaga",0),
                        Player("Elton John",0)};

    int num=0;
    for(int i=0; i<52; i++){
        people[0].addCard(desk, num, i);
        i++;
        people[1].addCard(desk, num, i);
        i++;
        people[2].addCard(desk, num, i);
        i++;
        people[3].addCard(desk, num, i);
        num++;
    }


    displayPlayers(0, 0, 0, 0, 0, 0, 0, 0, 0);
    cout << endl;

    int oneR = 0, twoR=0, threeR=0, fourR=0;


    int choice;
    int firstPlay;
    Suit suit = Clubs;
    for(int i=0; i<4; i++){
       if(people[i].findClubTwo()!=-1){
           choice = i;
       }
   }


    for(int u=1; u<=13; u++) {
        cout << "Round " << u << endl;

        firstPlay=choice;
        played[0] = people[choice].playCard(suit, true);
        suit = played[0].getSuits();
        displayCard(people[choice], played[0].getDescription());
        playedName[0] = people[choice].getName();
        choice++;
        for (int i = 1; i < 4; i++) {
            if (choice > 3) {
                choice = 0;
            }
            played[i] = people[choice].playCard(suit, false);
            displayCard(people[choice], played[i].getDescription());
            playedName[i] = people[i].getName();
            choice++;

        }
        Card winnerCar;
        int numCar;
        winnerCar = winnerCar.isBigger(suit, played);

        for (int i = 0; i < 4; i++) {
            if (played[i].getDescription() == winnerCar.getDescription()) {
                numCar = i;
            }
        }

        choice = (firstPlay + numCar)%4;
        int hearts = Card::ifHearts(played);
        people[choice].setPoints(hearts);

            oneR = people[0].getPoints() - oneR;
            twoR = people[1].getPoints() - twoR;
            threeR = people[2].getPoints() - threeR;
            fourR = people[3].getPoints() - fourR;
            displayPlayers(u, oneR, people[0].getPoints(), twoR, people[1].getPoints(), threeR, people[2].getPoints(),fourR
                           , people[3].getPoints());

        oneR = people[0].getPoints();
        twoR = people[1].getPoints();
        threeR = people[2].getPoints();
        fourR = people[3].getPoints();

        cout << endl;


    }



    //todo: it sometimes counts something else despite hearts.


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

void displayCard(Player& firstOne, string const str){

    cout << firstOne.getName() << ": " << str << endl;


}

