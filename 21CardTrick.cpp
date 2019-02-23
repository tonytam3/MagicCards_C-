#include <iostream>

using namespace std;

int cardStack[7][3];
int masterStack[21];
bool progExit;

void progIntro() {
	cout <<"Think of a number between 1 - 21\n Keep the number to yourself\n"<<endl;
}
int selectStack() {   // function for selecting which stack contains chosen number
	int selectedStack = 5;
	do {
		cout << "\nWhich stack has your number?" << endl;
		cin >> selectedStack;
	} while (selectedStack >= 3);
	return selectedStack;
}
void masterStackPop() { //Populating the initial 21 cards
	int size = sizeof(masterStack) / sizeof(masterStack[0]);
	for (int i = 0; i < size; i++) {
		masterStack[i] = i + 1;
	}
}
void dealMasterStack() { //dealing the initial 21 cards in 3 columns, 1 row at a time
	int i = 0;
	while (i < 20) {
		for (int y = 0; y < 7; y++) {
			for (int x = 0; x < 3; x++) {
				cardStack[y][x] = masterStack[i];
				i++;
			}
		}
	}
}
void printCardStack() {// self explanatory
	int sizeCardStack_Y = sizeof(cardStack) / sizeof(cardStack[0]);
	int sizeCardStack_X = sizeof(cardStack[0]) / sizeof(cardStack[0][0]);
	for (int x = 0; x < sizeCardStack_X; x++) {
		cout<<"Stack"<<x<<": ";
		for (int y = 0; y < sizeCardStack_Y; y++) {
			cout << cardStack[y][x] << " ";
		}
		cout << endl;
	}
}
void redealMasterStack(int i) {//merging each card stack backwards putting the selected stack in the middle.
	int x = 0;
	int MS1 = 0;
	while (x < 3) {
		if (x == 0) {
			if (x == i) {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][x + 1];
					MS1++;
				}
				x++;
			}
			else {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][x];
					MS1++;
				}
				x++;
			}
		}
		if (x == 1) {
			if (x == i) {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][x];
					MS1++;
				}
				x++;
			}
			else {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][i];
					MS1++;
				}
				x++;
			}
		}
		if (x == 2) {
			if (x == i) {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][x - 1];
					MS1++;
				}
				x++;
			}
			else {
				for (int y = 6; y >= 0; y--) {
					masterStack[MS1] = cardStack[y][x];
					MS1++;
				}
				x++;
			}
		}
	}
}
int main() {
	progIntro();
	masterStackPop();

	int n = 0;
	while (n < 3) { //asking 3 times to be safe
		dealMasterStack();
		printCardStack();
		int userInput = selectStack();
		redealMasterStack(userInput);
		n++;
	}
	dealMasterStack();
	printCardStack();
	cout<<"\nThe Number you are thinking of is: "<<cardStack[3][1]<<endl;
}
