#include<iostream>
using namespace std;

/// global variables
string inventory[10];
int money = 60;

//function declarations
void shop();




int main() { /// start of main
	///local variables 
	int room = 1;
	string input = "sigma";
	do {

		cout << "your inventory: ";
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " | ";
			cout << endl << endl;


		switch (room) {
		case 1:
			cout << "you are in room 1, you can go south" << endl;
			cin >> input;
			if (input == "south");
			room = 2;
			break;
		case 2:
			shop();
			cout << "you are in room 2, you can go north" << endl;
			cin >> input;
			if (input == "north");
			room = 1;
			break;
		} /// end of switch
	} while (input != "quit");

}/// end of main


/// define functions
void shop() {
	char input = 'o';
	cout << endl << endl << "----------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "press p for potion(10$), s for sword(20$), a for armor(50$), q to leave shop" << endl;
		cin >> input;
		switch(input) {
		case 'p':
			if (money >= 10) {
				cout << "you got a potion!" << endl;
				inventory[0] = "potion";
				money -= 10;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 's':
			if (money >= 20) {
				cout << "you got a sword!" << endl;
				inventory[1] = "sword";
				money -= 20;
			}
			else
			cout << "you're broke" << endl;
			break;
		case 'a':
			if (money >= 20) {
				cout << "you got armor!" << endl;
				inventory[2] = "armor";
				money -= 50;
			}
			else
				cout << "you're broke" << endl;
			break;
		}
	}
	cout << endl << "----------------------" << endl;

}
