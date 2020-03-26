#include<iostream>
using namespace std;

enum Note
{
	MIDDLE_C,C_SHARP,B_FLAT
};

class Instrument //³éÏó»ùÀà£¬ÀÖÆ÷
{
public:
	virtual void play(Note n) = 0;
	virtual void adjust() = 0;
};

class Wind :virtual public Instrument
{
public:
	void play(Note n){ cout << "Wind.play()" << n << endl; }
	void adjust(){ cout << "Wind,adjust()" << endl; }
};
class Brass :public Wind{
public:
	void play(Note n){ cout << "Brass.play()" << n << endl; }
	void adjust(){ cout << "Brass,adjust()" << endl; }
};
class Woodwind :public Wind{
public:
	void play(Note n){ cout << "Woodwind.play()" << n << endl; }
};

class Music
{
public:
	void tune(Instrument* i){ i->play(MIDDLE_C); }
	void adjust(Instrument* i){ i->adjust(); }
	void tuneAll(Instrument* e[], int numIns)
	{
		for (int i = 0; i < numIns; i++)
		{
			this->tune(e[i]);
			this->adjust(e[i]);
		}
	}
};

int main()
{
	return 0;
}
