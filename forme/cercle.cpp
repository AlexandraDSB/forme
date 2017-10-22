#include "Cercle.hpp"
#include <cmath>


Cercle::Cercle (uint x_ , uint y_, uint rayon_) : Forme(x_,y_),rayon(rayon_)
{

}

Cercle::Cercle (istream & is): Forme(is ),rayon(5)
{
	is >> rayon; 
}


Cercle::Cercle(const Cercle & orig): Forme( orig.getAncre().getX() , orig.getAncre().getY()),rayon(orig.getrayon())
{

}

Cercle::~Cercle()
{

}

double Cercle::perimetre()const
{
	double pi=acos(-1.0);
	return 2*pi*rayon;
}

void Cercle::ecrire(ostream & os )const 
{
	os << "Cercle ";
	Forme::ecrire(os); 
	os<<" "<<rayon<<endl ; 
}


void Cercle::dessiner(EZWindow & f, bool isActive)const 
{
	Forme:: dessiner (f,isActive);
	const Point & ancre = getAncre(); 
	if (getFill())
		f.fillCircle(ancre.getX(),ancre.getY(),ancre.getX()+rayon,ancre.getY()+rayon);
	else
		f.drawCircle(ancre.getX(),ancre.getY(),ancre.getX()+rayon,ancre.getY()+rayon);
}
