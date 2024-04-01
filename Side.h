#pragma once
#include "Layer.h"

class Side
{
public:
	Color side[3][3];
	Side();
	Side(Color sides[3][3]);
	Side(Layer layers[3]);

	Layer getRowColors(int rownum);
	Layer getColColors(int colnum);
	Color getColor(int row, int col);
	void setColor(int row, int col, Color c);
	void setRowColors(int rownum, Layer l, bool reversed);
	void setColColors(int colnum, Layer l, bool reversed);
};

