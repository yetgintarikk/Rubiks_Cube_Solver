#pragma once
#include "types.h"
#include <iostream>

class Layer
{
public:
	Color layer[3];
	Layer();
	Layer(Color c1, Color c2, Color c3);
	Layer(Color c1[3]);
	Color &operator[] (int i);
	bool operator ==(Layer l);
	bool operator !=(Layer l);
};

