#pragma once
#include <string>
#include <sstream>


class Dot
{
private:
	double x;
	double y;
public:
	Dot();
	Dot(double x, double y);
	double DistanceTo(Dot point);
};