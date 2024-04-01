#pragma once
#include "Side.h"

class Cube
{
public:
	Side sides[6];
	std::string movesMade;
	Cube();
	Cube(Side sd[6]);
	Cube(Color b[3][3] , Color u[3][3]   , Color l[3][3],
		 Color f[3][3], Color r[3][3], Color d[3][3]);
	Cube(std::string b, std::string u, std::string l,
		 std::string f, std::string r, std::string d);
	void print();
	void longSpace(bool sep);
	void shortSpace();
	void printLine(Direction dir, int line, bool newline);
	bool check();
	void castMove(char c);
	void castMove(std::string s);
	void move_B();
	void move_b();
	void move_U();
	void move_u();
	void move_L();
	void move_l();
	void move_F();
	void move_f();
	void move_R();
	void move_r();
	void move_D();
	void move_d();
	void move_R_trig();
	void move_L_trig();
	void goSide(Direction d);
	std::string solve();
	void daisy();
	bool daisyOK();
	void setWhite();
	void yellowUp();
	void whiteCrossDown();
	void whiteFaceDown();
	bool whiteDown();
	void rotateClockWise(Direction d);
	void rotateCounterClockWise(Direction d);
};

