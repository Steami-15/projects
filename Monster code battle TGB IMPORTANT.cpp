#include <iostream>
using namespace std;

//function
void FirstBattle();

//global
int PlayerHealth = 150;


int main() {
	int room = 1;
	char input;
	while (PlayerHealth > 0) { //start of game loop
		switch (room) {
		case 1:
			cout << "you're in room one you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:
			FirstBattle();
			cout << "you're in room two you can go (s)outh or (n)orth" << endl;
			cin >> input;
			if (input == 's')
				room = 3;
			else if (input == 'n')
				room = 1;
			break;
		case 3:
			cout << "you're in room three you can go (n)orth" << endl;
			cin >> input;
			if (input == 'n')
				room = 2;
			break;
		}


	} //END OF GAME LOOP
	//game over message
} // end of main



void FirstBattle() {
	int SpiderHealth = 10;//Local variable only seen and used by FirstBattle()
	char dummy;
	cout << endl << endl << "----Basic Fight----" << endl;
	cout << endl <<  "A spider jumps at you swat it off!" << endl;
	while (PlayerHealth > 0 && SpiderHealth > 0) {
		cout << "spider bites you for 1 damage" << endl;
		PlayerHealth -= 1;
		cout << "press any key to continue..." << endl<<endl;
		cin >> dummy;

		cout << "you hit spider for 5 damage" << endl;
		SpiderHealth -= 5;
		cout << endl;
		cout << "press any key to continue..." << endl << endl;
		cin >> dummy;

		cout << "Your health is now: " << PlayerHealth << endl;
		cout << "Spider health is now: " << SpiderHealth << endl << endl;
	}
	if (PlayerHealth > 0)
		cout << "you beat the spider" << endl;
	else
		cout << "you lost game over" << endl;
	cout << endl << "---end of battle---" << endl << endl;
}
