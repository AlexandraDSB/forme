#include "Triangle.hpp"
#include <cmath>


Triangle::Triangle (uint x_ , uint y_ , uint coor1x_, uint coor1y_, uint coor2x_, uint coor2y_): Forme(x_,y_), coor1x(coor1x_), coor1y(coor1y_), coor2x(coor2x_), coor2y(coor2y_)
{

}

Triangle::Triangle (istream & is): Forme(is ),coor1x(9),coor1y(3),coor2x(3),coor2y(9)
{
	is >>coor1x>>coor1y>>coor2x>>coor2y; 
}


Triangle::Triangle(const Triangle & orig): Forme(orig.getAncre().getX(),orig.getAncre().getY()),coor1x(orig.getcoor1x()),coor1y(orig.getcoor1y()), coor2x(orig.getcoor2x()), coor2y(orig.getcoor2y())
{

}

Triangle::~Triangle()
{

}

double Triangle::perimetre()const
{
	
	return 0;
}

void Triangle::ecrire(ostream & os )const 
{
	os << "Triangle ";
	Forme::ecrire(os); 
	os<<" "<<getcoor1x()<<" "<<getcoor1y()<<" "<<getcoor2x()<<" "<<getcoor2y()<<endl ; 
}


void Triangle::dessiner(EZWindow & f, bool isActive)const 
{
	Forme::dessiner (f,isActive);
	const Point & ancre = getAncre(); 
	f.drawTriangle(ancre.getX(),ancre.getY(),ancre.getX()+coor1x,ancre.getY()+coor1y,ancre.getX()+coor2x,ancre.getY()+coor2y);
}


