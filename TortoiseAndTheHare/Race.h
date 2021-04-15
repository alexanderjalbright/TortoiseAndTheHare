#include <string>

using namespace std;

class Square {
	void Top();
	void MiddleEmpty();
	void MiddlePlayer(char);
	void MiddleBump();
	void Bottom();
};

class Race {
	private: 
		Tortoise& _tortoise;
		Hare& _hare;

	public:		
		void Begin();
		int GetMoveValue();
		bool IsWon();
		string Winner;
		void PrintStart();		
		void PrintStatus();
		void PrintEnd();
};

class Contestant {
	public:
		int Position = 0;
		char DisplayCharacter;
		virtual void Move(int);
		void UpdatePosition(int);

};

class Tortoise : Contestant {
	public:
		Tortoise() {
			DisplayCharacter = 'T';
		}
		void Move(int) override;
	private:
		int _fastPlod = 3;
		int _slip = -6;
		int _slowPlod = 1;
};

class Hare : Contestant {
	public: 
		Hare() {
			DisplayCharacter = 'H';
		}
		void Move(int) override;
	private:
		int _sleep = 0;
		int _bigHop = 9;
		int _bigSlip = -12;
		int _smallHop = 1;
		int _smallSlip = -2
};


