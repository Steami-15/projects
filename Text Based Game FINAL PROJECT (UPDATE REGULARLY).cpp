#include<iostream>
#include<string>
using namespace std;

void ClosetBattle(); //Battle that distracts the player and wastes time

int health = 150; // health that you can upgrade

int coins = 0;

string inventory[5];

void shop();

//The story is that you are a middle aged man that has to save the world from a zombie apocalypse 

int main() {
	int room = 1;
	string input = "skibidi";
	bool room5 = false;

	while (input != "quit") {

		cout << endl << "--------------" << endl;
		cout << "your inventory: ";
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " | ";
		cout << endl;
		cout << "your health: ";
		cout << health;
		cout << endl << "--------------" << endl;
		cout << endl;
		switch (room) {
		case 1:
			cout << "you are in your hotel room that you started living in for a year and a zombie outbreak starts and you need to get gearedup in this hotel floor you are on. You see a key on the table next to your bed type q to grab. You can go east to leave" << endl;
			getline(cin, input);

			if (input == "east" || input == "East" || input.compare("go east") == 0 || input.compare("Go east") == 0)
			room = 2;

			else if (inventory[0] == "key") {
			cout << "you already have the key..." << endl;
			cout << endl;
			}
			

			else if (inventory[0] != "key" && input == "Q" || input == "q") {
				inventory[0] = "key";
				cout << "you grabbed the key!" << endl;
				cout << endl;
			}

			else
				cout << "thats not an option" << endl;
			break;
		case 2:
			cout << "you are outside of your hotel door you can go south or west to go to the hallway or back to your room" << endl;
			cin >> input;
			if (input == "south" || input == "South" || input.compare("go south") == 0 || input.compare("Go south") == 0)
				room = 3;
			else if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
			room = 1;
			break;
			case 3:
				cout << "you are in the main hallway you can go east for more of the hallway or north back up to the door or south for the hotel closet" << endl;
				cin >> input;
				if (input == "east" || input == "East" || input.compare("go east") == 0 || input.compare("Go east") == 0)
					room = 6;
				else if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
					room = 2;
				else if (input == "south" || input == "South" || input.compare("go south") == 0 || input.compare("Go south") == 0)
					room = 4;
				else
					cout << "thats not an option" << endl;
				break;
			case 4:
				cout << "you are in front of a closet door but you need to key to open it. You can go west to try and open the door or north backto the hallway" << endl;
				cin >> input;
				if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
					if (inventory[0] == "key") {
						cout << "you unlock the door with key" << endl;
						inventory[0] = " ";
						room = 5;
					}
					else {
						cout << "the door is locked (womp womp)" << endl;
					}

				else if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
					room = 3;
				break;

			case 5:
				if (room5 == false) {
					ClosetBattle();
					cout << "you found coins on the floor after fighting that swatting the spider!" << endl;
					coins += 30;
					room5 = true;
				}
				cout << "you are in the closet. You can leave the room by going east" << endl;
				cin >> input;
				if (input == "east" || input == "East" || input.compare("go east") == 0 || input.compare("Go east") == 0)
					room = 4;
				else
					cout << "thats not an option" << endl;
				break;

			case 6:
				cout << "you are in an intersection of the hallway you can go west to go back to the hotel doors hallway or east to go further in the hallway" << endl;
				cin >> input;
				if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
					room = 3;
				else if (input == "East" || input == "east" || input.compare("go east") == 0 || input.compare("Go east") == 0)
					room = 7;
				else
					cout << "thats not an option" << endl;
				break;
			case 7:
				cout << "you are in an intersection 2 of the hallway you can go west to go back to the first intersection or north to go into a bartenders boutique or south for your neighbors room east to go further in the hallway" << endl;
				cin >> input;
				if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
					room = 6;
				else if (input == "East" || input == "east" || input.compare("go east") == 0 || input.compare("Go east") == 0)
					room = 10;
				else if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
					room = 8;
				else if (input == "south" || input == "South" || input.compare("go south") == 0 || input.compare("Go south") == 0)
					room = 9;
				else
					cout << "thats not an option" << endl;
				break;
			case 8:
				shop();
				cout << "you are in the Bartenders Boutique! You can buy weapons here from coins you find throughout the hotel! you can go south to leave into the second intersection" << endl;
				cin >> input;
				if (input == "south" || input == "South" || input.compare("go south") == 0 || input.compare("Go south") == 0)
					room = 7;
				else
					cout << "thats not an option" << endl;
				break;
			}




		}
	}

	void shop() {
		char input = 'o';
	cout << endl << endl << "----------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "press p for potion(10$), s for sword(20$), a for armor(50$), q to leave shop" << endl;
		cin >> input;
		switch (input) {
		case 'p':
			if (coins >= 10) {
				cout << "you got a potion!" << endl;
				inventory[0] = "potion";
				coins -= 10;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 's':
			if (coins >= 20) {
				cout << "you got a sword!" << endl;
				inventory[1] = "sword";
				coins -= 20;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'a':
			if (coins >= 20) {
				cout << "you got armor!" << endl;
				inventory[2] = "armor";
				coins -= 50;
			}
			else
				cout << "you're broke" << endl;
			break;
		}
	}
	cout << endl << "----------------------" << endl;

}


void ClosetBattle() {
	int SpiderHealth = 10; //global variable for spiderhealth because idk how to only do locals
	char dummy;
	cout << endl << endl << "----Basic Fight----" << endl;
	cout << endl << "A spider jumps at you swat it off!" << endl;
	while (health > 0 && SpiderHealth > 0) {
		cout << "spider bites you for 1 damage" << endl;
		health -= 1;
		cout << "press any key to continue..." << endl << endl;
		cin >> dummy;

		cout << "you hit spider for 5 damage" << endl;
		SpiderHealth -= 5;
		cout << endl;
		cout << "press any key to continue..." << endl << endl;
		cin >> dummy;

		cout << "Your health is now: " << health << endl;
		cout << "Spider health is now: " << SpiderHealth << endl << endl;
	}
	if (health > 0)
		cout << "you beat the spider" << endl;
	else
		cout << "you lost game over" << endl;
	cout << endl << "---end of battle---" << endl << endl;
}
