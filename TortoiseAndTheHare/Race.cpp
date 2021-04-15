#include "Race.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Race::Begin() {
	this->PrintStart;

	while (!this->IsWon()) {
		int current = this->GetMoveValue();
		this->_hare->Move(current);
		this->_tortoise->Move(current);

		this->PrintStatus;
	}

	this->PrintEnd;
}

bool Race::IsWon() {
	return this->_tortoise->Position == 70 || this->_hare->Position == 70;
}

int Race::GetMoveValue() {
	srand(time(NULL));
	return rand() % 10 + 1;
}

void Race::PrintStart() {
	cout << "Bang! Off they Go!";
}

void Race::PrintStatus() {
	
}

void Race::PrintEnd() {

}

void Square::Top() {

	cout << " _____ ";
}

void Square::MiddleEmpty() {
	cout << "|     |";
}

void Square::MiddlePlayer(char displayCharacter) { 
	cout << "|  " << displayCharacter << "  |";
}

void Square::MiddleBump() {
	cout << "|BUMP!|";
}

void Square::Bottom() {
	cout << "‾‾‾‾‾‾‾";
}

void Contestant::UpdatePosition(int current) {
	if (current < 0) {
		this->Position = 0;
	} 
	else if (current > 70) {
		this->Position = 70;
	}
	else {
		this->Position = current;
	}
}



void Tortoise::Move(int current) {
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

void Hare::Move(int current) {
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