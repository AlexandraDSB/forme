#include <iostream>

#include "point.hpp"

using namespace std ;


Point::Point( uint x_, uint y_): x(x_),y(y_)
{
	
}

Point::Point(const Point & orig): x(orig.x), y(orig.y)
{
	
}

Point::Point(istream & is ): x(0), y(0)
{is >> x>> y ; }

Point::~Point()
{

}

bool Point::isOver(uint x_, uint y_)
{
	uint x1 = ( x_ <= x ? x : x_ );
	uint x2 = ( x_ <= x ? x_ : x );

	uint y1 = ( y_ <= y ? y : y_ );
	uint y2 = ( y_ <= y ? y_: y );

	uint dx= x1 - x2; 
	uint dy =  y1 - y2; 

	return (dx <= taille && dy <= taille);
}

void Point::dessiner( EZWindow & f , bool isActive) const
{
   if (isActive)
   	f.fillRectangle((x-taille),(y-taille),(x+taille),(y+taille));
   else 
   	f.drawRectangle((x-taille),(y-taille),(x+taille),(y+taille)); 
	
}

ostream& operator<< (ostream & os , const Point & p )
{

	os<<p.x<<" "<<p.y;
	return os ; 
}


istream& operator>> (istream & is , Point & P )
{
	is>> P.x;
	is >> P.y; 
	return (is);

}
