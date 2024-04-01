#include "Layer.h"

Layer::Layer()
{
	layer[0] = white;
	layer[1] = white;
	layer[2] = white;
}
Layer::Layer(Color c1, Color c2, Color c3)
{
	layer[0] = c1;
	layer[1] = c2;
	layer[2] = c3;
}
Layer::Layer(Color c[3])
{
	layer[0] = c[0];
	layer[1] = c[1];
	layer[2] = c[2];
}

Color& Layer::operator[] (int i)
{
	return layer[i];
}

bool Layer::operator ==(Layer l)
{
	for (int i = 0; i < 3; i++)
		if (layer[i] != l[i])
			return false;
	return true;
}

bool Layer::operator !=(Layer l)
{
	for (int i = 0; i < 3; i++)
		if (layer[i] != l[i])
			return true;
	return false;
}