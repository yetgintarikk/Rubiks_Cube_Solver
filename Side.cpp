#include "Side.h"

Side::Side()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			side[i][j] = white;
}

Side::Side(Color sides[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			side[i][j] = sides[i][j];
}

Side::Side(Layer layers[3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			side[i][j] = layers[i].layer[j];
}

Layer Side::getRowColors(int rownum)
{
	Layer temp;
	temp[0] = side[rownum][0];
	temp[1] = side[rownum][1];
	temp[2] = side[rownum][2];

	return temp;
}

Layer Side::getColColors(int colnum)
{
	Layer temp;
	temp[0] = side[0][colnum];
	temp[1] = side[1][colnum];
	temp[2] = side[2][colnum];

	return temp;
}

void Side::setRowColors(int rownum, Layer l, bool reversed)
{
		for (size_t i = 0; i < 3; i++)
		{
			side[rownum][i] = l[(reversed) ? 2 - i : i];
		}
}

void Side::setColColors(int colnum, Layer l, bool reversed)
{
	for (size_t i = 0; i < 3; i++)
	{
		side[i][colnum] = l[(reversed) ? 2 - i : i];
	}
}

Color Side::getColor(int row, int col)
{
	return side[row][col];
}

void Side::setColor(int row, int col, Color c)
{
	side[row][col] = c;
}