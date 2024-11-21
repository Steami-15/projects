#include <iostream>
using namespace std;

//global variables
string inventory[10];
int playerHealth = 150;

int main() {// start of main
	//local variables
	int room = 1;
	string input = "sigma";
	
		
	while (input != "quit") { // start of game loop

		cout << endl << "--------------" << endl;
		cout << "your inventory: ";
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " | ";
		cout << endl;

		switch (room) {
		case 1:
			cout << "you are in room 1 you can go east for room 2" << endl;
			cout << "you found a pineapple!" << endl;
			inventory[0] = "pineapple";
			cout << "theres a dusty rug on the floor." << endl;
			cin >> input;
			if (input == "east" || input == "go east")
				room = 2;
			if (input == "rug" || input == "look") {
				if(inventory[2]!="key")
					cout << "you found a shiny key!" << endl;
				inventory[2] = "key";
			}
			break;

		case 2:
			cout << "you are in room 2 you can go north or west for room 3 and 1" << endl;
			if(inventory[1]!= "sword")
				cout << "you see a sword on the ground." << endl;
			cin >> input;
			if (input == "north" || input == "go north")
				if (inventory[2] == "key") {
					cout << "you unlock the door with key" << endl;
					inventory[2] = " ";
					room = 3;
				}
				else {
					cout << "the door is locked (womp womp)" << endl;
				}
			else if (input == "west" || input == "go west")
				room = 1;
			if (input == "sword" || input == "pick up sword" || input == "get sword") {
				inventory[1] = "sword";
				cout << "you picked up the sword!" << endl;
			}
			break;
		case 3:
			cout << "you are in room 3, THERES A DRAGON!!!!!!!" << endl;
			if (inventory[1] == "sword") {
				cout << "you slayed the dragon with your sword and escaped the castle" << endl;
				input = "quit";
			}
			else {
				cout << "you dead." << endl;
				input = "quit";
			}
			break;
		}// room




	} // game loop
	cout << "thanks for playing..." << endl;
}// end of main
