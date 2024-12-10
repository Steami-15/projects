#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

void ClosetBattle(); //Battle that distracts the player and wastes time

int health = 150; // health that you can upgrade

int coins = 0; // coins for buying juggernog and weapons

string inventory[5]; // inventory 

string perks[3];

void PerkShop();

void Horde();

void shop(); // shop function

void juggernog();


int main() {
	int room = 1;
	string input = "skibidi";
	bool room5 = false;
	bool grabcoins = false;


	while (input != "quit" && 0 < health) {

		cout << endl << "--------------" << endl;
		cout << "your inventory: ";
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " | ";
		cout << endl;
		cout << "your perks: ";
		for (int i = 0; i < 4; i++)
			cout << perks[i] << " | ";
		cout << endl;
		cout << "your health: ";
		cout << health;
		cout << endl << "--------------" << endl;
		cout << endl;

		switch (room) {
		case 1:
			cout << "you are in your hotel room that you started living in for a year and a zombie outbreak starts and you need to get gearedup in this hotel floor you are on. You see a key on the table next to your bed type q to grab. You can go east to leave" << endl << endl << endl;
			if (grabcoins == false) {
				cout << "you found some coins" << endl;
				coins += 30;
				cout << "your coins: " << coins << endl;
				grabcoins = true;
			}
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

			if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
				room = 3;

			else if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
				if (inventory[0] == "key") {
					cout << "you unlock the door with key" << endl;
					inventory[0] = " ";
					room = 5;
				}
				else {
					cout << "the door is locked (womp womp)" << endl;
				}

			break;

		case 5:
			if (room5 == false) {
				ClosetBattle();
				cout << "you found a few coins after that fight" << endl << endl;
				cout << "plus 30 coins!" << endl;
				coins += 30;
				cout << "your coins: " << coins << endl;
				room5 = true;
			}
			cout << "you are in the closet of the hotel. you see a vending machine type p to buy perks. Type east to leave the closet of the hotel" << endl;
			cin >> input;
			if (input == "east" || input == "East" || input.compare("go east") == 0 || input.compare("Go east") == 0)
				room = 4;
			else if (input == "p" || input == "P")
				PerkShop();
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
			cout << "you are in the Bartenders Stash! You can buy weapons here from coins you find throughout the hotel! you can go south to leave into the second intersection" << endl;
			cin >> input;
			if (input == "south" || input == "South" || input.compare("go south") == 0 || input.compare("Go south") == 0)
				room = 7;
			else
				cout << "thats not an option" << endl;
			break;
		case 9:
			cout << "you are in your neighbors room there is a stim shot in here do you grab it?" << endl;
			cin >> input;

			if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
				room = 7;


			break;

		case 10:
			cout << "you are in the 3rd intersection of the hallway you can go west to go back to the second intersection or east for the last intersection" << endl;
			cin >> input;
			if (input == "East" || input == "east" || input.compare("go east") == 0 || input.compare("Go east") == 0)
				room = 11;
			else if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
				room = 7;
			break;


		case 11:
			cout << "you are in the last intersection of the hallway you can go west to go back to the third intersection or north for the horde room (MAKE SURE YOU'RE PREPARED)" << endl;
			cin >> input;
			if (input == "north" || input == "North" || input.compare("go north") == 0 || input.compare("Go north") == 0)
				room = 12;
			else if (input == "west" || input == "West" || input.compare("go west") == 0 || input.compare("Go west") == 0)
				room = 10;
			break;
		case 12:
			cout << "ARE YOU SURE YOU ARE READY TO ENTER type yes if you are, type no to go back" << endl;
			cin >> input;
			if (input == "yes" || input == "Yes")
				Horde();
			else if (input == "no" || "No")
				room = 11;
			else 
				room = 11;
		}

	}
	cout << "thanks for playing!" << endl;
}

void juggernog() {
	cout << "you bought the JuggerNog perk!" << endl;
	health = 250;
}

void PerkShop() {
	char input = 'o';
	cout << endl << endl << "----------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "type JG for JuggerNog(10$), DW for Dying Wish(20$), DHRB for Double Hit Root Beer(5$), q to leave shop" << endl;
		cin >> input;
		switch (input) {
		case 'JG':
			if (coins >= 10) {
				cout << "you have the JuggerNog Perk!" << endl;
				perks[0] = "JuggerNog";
				coins -= 10;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 's':
			if (coins >= 20) {
				cout << "you have the Dying Wish Perk!" << endl;
				perks[1] = "Dying Wish";
				coins -= 20;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'a':
			if (coins >= 20) {
				cout << "you got Double Hit Root Beer!" << endl;
				perks[2] = "Double Hit";
				coins -= 50;
			}
			else
				cout << "you're broke" << endl;
			break;
		}
	}
	cout << endl << "----------------------" << endl;

}

void shop() {
	char input = 'o';
	cout << endl << endl << "----------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "press p for stim(10$), c for Caliburn sword(20$), d for Durendal sword(20$), b for Balmung sword aka the most powerful(30$), s for Solais sword(20$), a for armor(50$), q to leave shop" << endl;
		cin >> input;
		switch (input) {
		case 'p':
			if (coins >= 10) {
				cout << "you got a stim!" << endl;
				inventory[0] = "stim";
				coins -= 10;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'c':
			if (coins >= 20) {
				cout << "you got the Caliburn sword!" << endl;
				inventory[1] = "sword";
				coins -= 20;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'd':
			if (coins >= 20) {
				cout << "you got the Durendal sword!" << endl;
				inventory[1] = "sword";
				coins -= 20;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'b':
			if (coins >= 30) {
				cout << "you got the Balmung sword!" << endl;
				inventory[1] = "sword";
				coins -= 30;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 's':
			if (coins >= 20) {
				cout << "you got the Solais sword!" << endl;
				inventory[1] = "sword";
				coins -= 20;
			}
			else
				cout << "you're broke" << endl;
			break;
		case 'a':
			if (coins >= 20) {
				cout << "you got armor plates make sure to type G at any point to equip them!" << endl;
				inventory[2] = "armor";
				coins -= 10;
			}
			else
				cout << "you're broke" << endl;
			break;
		}
	}
	cout << endl << "----------------------" << endl;


}


void Horde() {
	int zombie1 = 30;
	int zombie2 = 30;
	int zombie3 = 30;
	int zombie4 = 30;
	int zombie5 = 30;
	int zombie6 = 30;
	int zombie7 = 30;
	int zombie8 = 30;
	int zombie9 = 30;
	int zombie10 = 30;
	int zombie11 = 30;
	int input;
	int num;
}


void ClosetBattle() {
				int monsterhealth = 10;
				int input;
				int num;
				cout << endl << endl << "-----------" << endl;
				while (health > 0 && monsterhealth > 0) {

					//monster attack
					if (inventory[1] == "armor") {
						num = rand() % 10 + 10; // range from 10-20
						cout << "you get hit by zombie for " << num << " damage (reduced because of armor)" << endl << endl;
						health -= num;
					}
					else {
						num = rand() % 30 + 10; // range from 30-40
						cout << "you get hit by zombie for " << num << " damage" << endl << endl;
						health -= num;

						cout << "press 1 to attack, 2 to drink potion, 3 to try to escape" << endl << endl;
						cin >> input;

						switch (input) {
						case 1:
							//player attack
							if (inventory[1] == "Caliburn sword") {
								num = rand() % 10 + 10; // range from 10-20
								cout << "you hit the zombie with your sword for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							else {
								num = rand() % 5 + 3;
								cout << "you punch the zombie for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							break;
						case 2:
							if (inventory[0] == "stim") {
								cout << "you inject the stim and get health!" << endl << endl;
								health = 150;
								inventory[0] = " "; // erases stim
							}
							else cout << "you dont have a stim equipped" << endl << endl;
							break;
						case 3: // run from zombie
							num = rand() % 100;
							if (num > 75) {
								cout << "you ran away succesfully" << endl << endl;
								monsterhealth = 0;
							}
							else cout << "you are cornered" << endl;
							break;
						case 4:
							//player attack
							if (inventory[1] == "Durendal sword") {
								num = rand() % 10 + 10; // range from 10-20
								cout << "you hit the zombie with your sword for" << num << " damage" << endl << endl;
								monsterhealth -= num;
						case 5:
							//player attack
							if (inventory[1] == "Balmung sword") {
								num = rand() % 13 + 15; // range from 13-28
								cout << "you hit the zombie with your sword for" << num << " damage" << endl << endl;
								monsterhealth -= num;
						case 6:
							//player attack
							if (inventory[1] == "Solais sword") {
								num = rand() % 10 + 10; // range from 10-20
								cout << "you hit the zombie with your sword for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							else {
								num = rand() % 5 + 3;
								cout << "you punch the zombie for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							break;
							}
							else {
								num = rand() % 5 + 3;
								cout << "you punch the zombie for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							break;
							}
							else {
								num = rand() % 5 + 3;
								cout << "you punch the zombie for" << num << " damage" << endl << endl;
								monsterhealth -= num;
							}
							break;
						}

						cout << "your health:" << health << endl << endl;
						cout << "the zombies health is:" << monsterhealth << endl << endl;

					}
				}
				cout << "       _______________        " << endl;
				cout << "      /               \\      " << endl;
				cout << "      |  __      __   |" << endl;
				cout << "      |  |_|     |_|  |" << endl;
				cout << "      |               |" << endl;
				cout << "      |               |" << endl;
				cout << "      |               |" << endl;
				cout << "      |   \\\\_____//   |" << endl;
				cout << "      |   //     \\\\   |" << endl;
				cout << "      \\______________/" << endl;
				cout << "end of battle------------------------" << endl;
			}
