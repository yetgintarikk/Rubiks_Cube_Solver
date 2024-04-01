#include "Cube.h"

Cube::Cube()
{
	Side s;
	for (int i = 0; i < 6; i++)
	{
		sides[i] = s;
	}
	movesMade = "";
}
Cube::Cube(Side sd[6])
{
	for (int i = 0; i < 6; i++)
	{
		sides[i] = sd[i];
	}
	movesMade = "";
}

Cube::Cube(Color b[3][3], Color u[3][3], Color l[3][3],
	       Color f[3][3], Color r[3][3], Color d[3][3])
{
	sides[back]  = b;
	sides[up]    = u;
	sides[left]  = l;
	sides[front] = f;
	sides[right] = r;
	sides[down]  = d;

	movesMade = "";
}

Cube::Cube(std::string b, std::string u, std::string l,
	       std::string f, std::string r, std::string d)
{
	std::string sd[] = {b,u,l,f,r,d};
	for (int x = 0; x < 6; x++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sides[x].setColor(i, j, (Color)((sd[x])[i * 3 + j]));
			}
		}
	}
}
/*
*  Every side's index starts at top left as (0,0)
*
*              --------
*              | Back |
*              |      |
*              --------
*              |  Up  |
*              |      |
*      ------------------------
*      | Left  | Front| Right |
*      |       |      |       |
*      ------------------------
*              | Down |
*              |      |
*              --------
*
*
*/

void Cube::print()
{
	longSpace(false);
	std::cout << "---------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		longSpace(true);
		printLine(back, i, true);
	}
	longSpace(false);
	std::cout << "---------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		longSpace(true);
		printLine(up, i, true);
	}
	longSpace(false);
	std::cout << "----------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		shortSpace();
		for (int j = left; j < right + 1; j++)
		{
			printLine(Direction(j), i, false);
			std::cout << "|";
		}

		std::cout << std::endl;
	}
	longSpace(false);
	std::cout << "----------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		longSpace(true);
		printLine(down, i, true);
	}
	longSpace(false);
	std::cout << "---------" << std::endl;
}

void Cube::longSpace(bool sep)
{
	int space = 12;
	for (int i = 0; i < space; i++) { std::cout << " "; }
	if (sep)
		std::cout << "|";
	else
		std::cout << "-";
}

void Cube::shortSpace()
{
	std::cout << "  |";
}

void Cube::printLine(Direction dir, int line, bool newline)
{
	for (int i = 0; i < 3; i++)
		std::cout << " " << (char)sides[dir].getRowColors(line)[i] << " ";
	if (newline)
		std::cout << "|" << std::endl;
}

bool Cube::check()
{
	int colors[] = { 0,0,0,0,0,0 };

	for (int face = 0; face < 6; face++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Color col = sides[face].getColor(i, j);
				if (col == white)
					colors[0]++;
				else if (col == orange)
					colors[1]++;
				else if (col == green)
					colors[2]++;
				else if (col == red)
					colors[3]++;
				else if (col == blue)
					colors[4]++;
				else if (col == yellow)
					colors[5]++;
			}
		}
	}

	for (int i = 0; i < 6; i++)
		if (colors[i] != 9)
		{
			return false;
		}
	return true;
}

void Cube::move_B()
{
	goSide(up);
	goSide(up);
	move_F();
	goSide(down);
	goSide(down);
}
void Cube::move_b()
{
	goSide(up);
	goSide(up);
	move_f();
	goSide(down);
	goSide(down);
}
void Cube::move_U()
{
	goSide(up);
	move_F();
	goSide(down);
}
void Cube::move_u()
{
	goSide(up);
	move_f();
	goSide(down);
}
void Cube::move_L()
{
	goSide(left);
	move_F();
	goSide(right);
}
void Cube::move_l()
{
	goSide(left);
	move_f();
	goSide(right);
}
void Cube::move_F()
{
	Layer temp = sides[up].getRowColors(2);                            // temp           <- up.row.bottom
	sides[up].setRowColors(2, sides[left].getColColors(2), true);      // up.row.bottom  <- left.col.right
	sides[left].setColColors(2, sides[down].getRowColors(0), false);   // left.col.right <- down.row.up
	sides[down].setRowColors(0, sides[right].getColColors(0), true);   // down.row.up    <- right.col.left
	sides[right].setColColors(0, temp, false);                         // right.colleft  <- temp
	rotateClockWise(front);
}
void Cube::move_f()
{
	Layer temp = sides[up].getRowColors(2);                            
	sides[up].setRowColors(2, sides[right].getColColors(0), false);      
	sides[right].setColColors(0, sides[down].getRowColors(0), true);
	sides[down].setRowColors(0, sides[left].getColColors(2), false);
	sides[left].setColColors(2, temp, true);                         
	rotateCounterClockWise(front);
}
void Cube::move_R()
{
	goSide(right);
	move_F();
	goSide(left);
}
void Cube::move_r()
{
	goSide(right);
	move_f();
	goSide(left);
}
void Cube::move_D()
{
	goSide(down);
	move_F();
	goSide(up);
}
void Cube::move_d()
{
	goSide(down);
	move_f();
	goSide(up);
}
void Cube::move_R_trig()
{
	move_R();
	move_U();
	move_r();
}
void Cube::move_L_trig()
{
	move_l();
	move_u();
	move_L();
}

void Cube::goSide(Direction d)
{
	Side temp = sides[front];

	switch (d)
	{
	case up:
		sides[front] = sides[up];
		sides[up] = sides[back];
		sides[back] = sides[down];
		sides[down] = temp;
		rotateCounterClockWise(right);
		rotateClockWise(left);
		break;

	case down:
		sides[front] = sides[down];
		sides[down] = sides[back];
		sides[back] = sides[up];
		sides[up] = temp;
		rotateCounterClockWise(left);
		rotateClockWise(right);
		break;

	case left:
		sides[front] = sides[left];
		rotateClockWise(back);
		rotateClockWise(back);
		sides[left] = sides[back];
		sides[back] = sides[right];
		rotateClockWise(back);
		rotateClockWise(back);
		sides[right] = temp;
		rotateCounterClockWise(up);
		rotateClockWise(down);
		break;

	case right:
		sides[front] = sides[right];
		rotateClockWise(back);
		rotateClockWise(back);
		sides[right] = sides[back];
		sides[back] = sides[left];
		rotateClockWise(back);
		rotateClockWise(back);
		sides[left] = temp;
		rotateCounterClockWise(down);
		rotateClockWise(up);
		break;
	default:
		break;
	}
}

void Cube::rotateClockWise(Direction d)
{
	Side temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.setColor(j, ((i * 2) + 2) % 3, sides[d].getColor(i, j));
		}
	}
	sides[d] = temp;
}

void Cube::rotateCounterClockWise(Direction d)
{
	Side temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.setColor(((j * 2) + 2) % 3, i, sides[d].getColor(i, j)); // weird calculation, but works!
		}
	}
	sides[d] = temp;
}

void Cube::castMove(char c)
{

	switch (c)
	{
	case 'B':
		move_B();
		movesMade.append("B");
		break;
	case 'b':
		move_b();
		movesMade.append("b");
		break;
	case 'U':
		move_U();
		movesMade.append("U");
		break;
	case 'u':
		move_u();
		movesMade.append("u");
		break;
	case 'L':
		move_L();
		movesMade.append("L");
		break;
	case 'l':
		move_l();
		movesMade.append("l");
		break;
	case 'F':
		move_F();
		movesMade.append("F");
		break;
	case 'f':
		move_f();
		movesMade.append("f");
		break;
	case 'R':
		move_R();
		movesMade.append("R");
		break;
	case 'r':
		move_r();
		movesMade.append("r");
		break;
	case 'D':
		move_D();
		movesMade.append("D");
		break;
	case 'd':
		move_d();
		movesMade.append("d");
		break;
	case 'T':
		move_R_trig();
		movesMade.append("T");
		break;
	case 't':
		move_L_trig();
		movesMade.append("t");
		break;
	case '<':
		goSide(left);
		movesMade.append("<");
		break;
	case '>':
		goSide(right);
		movesMade.append(">");
		break;
	case '^':
		goSide(up);
		movesMade.append("^");
		break;
	case 'v':
		goSide(down);
		movesMade.append("v");
		break;
	default:
		break;
	}

	/*
    char x;
	std::cout << "Move made : " << c << std::endl;
	print();
	std::cout << "Enter a char : ";
	std::cin >> x;
	*/

}

void Cube::castMove(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		castMove(s[i]);
}

std::string Cube::solve()
{
	daisy();

	return movesMade;
}

void Cube::daisy()
{
	while (!daisyOK())
	{
		yellowUp();
		setWhite();
	}
	whiteCrossDown();
	/*
	while (!whiteDown())
	{
		whiteFaceDown();
	}	
	*/
	
}

bool Cube::daisyOK()
{
	if (sides[up].getColor(1,1) == yellow && sides[up].getColor(0, 1) == white && sides[up].getColor(1, 0) == white &&
		sides[up].getColor(1, 2) == white && sides[up].getColor(2, 1) == white)
		return true;

	return false;
}

void Cube::setWhite()
{
	if (sides[front].getColor(0, 1) == white)
	{
		castMove("FuR");
		return;
	}
	else if (sides[front].getColor(2, 1) == white)
	{
		while (sides[up].getColor(2, 1) == white)
			castMove('u');
		castMove("fuR");
		return;
	}
	else if (sides[front].getColor(1, 0) == white)
	{
		while (sides[up].getColor(1, 0) == white)
			castMove('u');
		castMove('l');
		return;
	}
	else if (sides[front].getColor(1, 2) == white)
	{
		while (sides[up].getColor(1, 2) == white)
			castMove('u');
		castMove('R');
		return;
	}
	else if (sides[down].getColor(0, 1) == white)
	{
		while (sides[up].getColor(2, 1) == white)
			castMove('u');
		castMove("FF");
		return;
	}
	else if (sides[down].getColor(2, 1) == white)
	{
		while (sides[up].getColor(0, 1) == white)
			castMove('u');
		castMove("BB");
		return;
	}
	else if (sides[down].getColor(1, 0) == white)
	{
		while (sides[up].getColor(1, 0) == white)
			castMove('u');
		castMove("LL");
		return;
	}
	else if (sides[down].getColor(1, 2) == white)
	{
		while (sides[up].getColor(1, 2) == white)
			castMove('u');
		castMove("RR");
		return;
	}
	else
	{
		castMove('>');
		return;
	}
}

void Cube::yellowUp()
{
	if (sides[up].getColor(1,1) == yellow)
	{
		return;
	}
	else if (sides[down].getColor(1, 1) == yellow)
	{
		castMove("vv");
		return;
	}
	else if (sides[left].getColor(1, 1) == yellow)
	{
		castMove("<v");
		return;
	}
	else if (sides[right].getColor(1, 1) == yellow)
	{
		castMove(">v");
		return;
	}
	else if (sides[front].getColor(1, 1) == yellow)
	{
		castMove("v");
		return;
	}
	else if (sides[back].getColor(1, 1) == yellow)
	{
		castMove("^");
		return;
	}
	return;
}

void Cube::whiteCrossDown()
{
	for (int i = 0; i < 4; i++)
	{
		while (sides[front].getColor(1, 1) != sides[front].getColor(0, 1))
			castMove('U');
		castMove("FF<");
	}
}

bool Cube::whiteDown()
{
	Layer temp(white, white, white);
	for (int i = 0; i < 3; i++)
		if (sides[down].getColColors(i) != temp)
			return false;
	return true;
}

void Cube::whiteFaceDown()
{
	// 
}