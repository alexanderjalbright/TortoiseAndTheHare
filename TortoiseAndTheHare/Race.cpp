#include <string>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include<windows.h>

using namespace std;

class Square {
public:
	void Top() {
		cout << "_______";
	}
	void Number(int num) {
		int displayNum = num + 1;
		if (displayNum < 10) {
			cout << "|  " << displayNum << "  |";
		}
		else {
			cout << "|  " << displayNum << " |";
		}
	}
	void MiddleEmpty() {
		cout << "|     |";
	}
	void MiddlePlayer(char displayCharacter) {
		cout << "|  " << displayCharacter << "  |";
	}
	void MiddleBump() {
		cout << "|BUMP!|";
	}
	void Bottom() {
		cout << "|_____|";
	}
};

class Contestant {
public:
	Contestant() : Position(0) {}
	int Position;
	char DisplayCharacter = 'a';
	virtual void Move(int current) {
		return;
	}
	void UpdatePosition(int current) {
		this->Position += current;
		if (this->Position < 0) {
			this->Position = 0;
		}
		else if (this->Position > 69) {
			this->Position = 69;
		}
	}
	void PrintPosition() {
		cout << DisplayCharacter << ": " << Position + 1 << endl;
	}
};
//
class Tortoise : public Contestant {
public:
	Tortoise() {
		DisplayCharacter = 'T';
	}
	void Move(int current) override {
		if (1 <= current && current <= 5) {
			this->UpdatePosition(this->_fastPlod);
		}
		else if (1 <= current && current <= 5) {
			this->UpdatePosition(this->_slip);
		}
		else {
			this->UpdatePosition(this->_slowPlod);
		}
	}
private:
	int _fastPlod = 3;
	int _slip = -6;
	int _slowPlod = 1;
};

class Hare : public Contestant {
public:
	Hare() {
		DisplayCharacter = 'H';
	}
	void Move(int current) override {
		if (1 <= current && current <= 2) {
			this->UpdatePosition(this->_sleep);
		}
		else if (3 <= current && current <= 4) {
			this->UpdatePosition(this->_bigHop);
		}
		else if (current == 5) {
			this->UpdatePosition(this->_bigSlip);
		}
		else if (6 <= current && current <= 8) {
			this->UpdatePosition(this->_smallHop);
		}
		else {
			this->UpdatePosition(this->_smallSlip);
		}
	}
private:
	int _sleep = 0;
	int _bigHop = 9;
	int _bigSlip = -12;
	int _smallHop = 1;
	int _smallSlip = -2;
};

class Race {
public:
	Race() {

	};
	Tortoise tortoise;
	Hare hare;
	string winner;

	void Begin() {
		this->PrintStart();
		while (!this->IsWon()) {
			int current = this->GetMoveValue();
			this->hare.Move(current);
			this->tortoise.Move(current);

			this->PrintStatus();
			this->hare.PrintPosition();
			this->tortoise.PrintPosition();
			Sleep(1000);
		}
		if (this->tortoise.Position == 70) {
			this->PrintEnd(this->tortoise.DisplayCharacter);
		}
		else {
			this->PrintEnd(this->hare.DisplayCharacter);
		}
	}
	int GetMoveValue() {
		srand(time(NULL));
		return rand() % 10 + 1;
	}
	bool IsWon() {
		return this->tortoise.Position == 69 || this->hare.Position == 69;
	}
	void PrintStart() {
		cout << "Bang! Off they Go!" << endl;
	}
	void PrintStatus() {
		system("cls");
		Square square;
		for (int row = 0; row < 7; row++) {
			for (int squareLine = 0; squareLine < 5; squareLine++) {
				for (int column = 0; column < 10; column++) {
					int squareNumber = (row * 10) + column;
					switch (squareLine) {
					case 0:
						square.Top();
						break;
					case 1:
						square.Number(squareNumber);
						break;
					case 2:
						if (this->tortoise.Position == squareNumber && this->hare.Position == squareNumber) {
							square.MiddleBump();
						}
						else if (this->tortoise.Position == squareNumber) {
							square.MiddlePlayer(this->tortoise.DisplayCharacter);
						}
						else if (this->hare.Position == squareNumber) {
							square.MiddlePlayer(this->hare.DisplayCharacter);
						}
						else {
							square.MiddleEmpty();
						}
						break;
					case 3:
						square.Bottom();
						break;
					}
				}
				cout << endl;
			}
		}
	}
	void PrintEnd(char winner) {
		cout << "WHAT A RACE!" << endl;
		if (winner == 'T') {
			cout << "The Tortoise won!" << endl;
		}
		else {
			cout << "The Hare won!" << endl;
		}
		cout << "I knew it from the start..." << endl;
	}
};

int main() {
	cout << "Welcome to the Tortoise and the Hare?" << endl;
	cout << "Please adjust your console window to allow 70 characters across and 31 lines down." << endl;
	cout << "Are you ready to start the race?" << endl;
	string x;
	cin >> x;
	cout << "Doesn't matter! Starting regardless!" << endl;
	Sleep(2000);
	Race race;
	race.Begin();
	return 0;
};