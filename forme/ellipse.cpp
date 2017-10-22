#include "ellipse.hpp"
#include <cmath>

Ellipse::Ellipse( uint x_ , uint y_ , uint demilargeur_, uint demihauteur_ ): Forme( x_ ,y_), demilargeur(demilargeur_), demihauteur(demihauteur_)
{ cerr<< "Ellipse"<<endl ; }

Ellipse::Ellipse(const Ellipse & orig): Forme(orig.getAncre().getX(),orig.getAncre().getY()), demilargeur(orig.demilargeur), demihauteur(orig.demihauteur)
{
	
}

Ellipse::Ellipse(istream & is ): Forme(is),demilargeur(5), demihauteur(5)
{
	is >> demilargeur>> demihauteur;
}

Ellipse::~Ellipse()
{cerr<< "~Ellipse"<<endl ; }

double Ellipse::perimetre()const 
{
	double pi=acos(-1.0);
	double A_Ellipse=(1/2.0)*(pi*demihauteur*demilargeur);
	return A_Ellipse ; 
}

void Ellipse::ecrire(ostream & os)const
{
	os << "Ellipse ";
	Forme::ecrire (os); 
	os<<" "<<demilargeur<<" "<<demihauteur<<endl; 
}

void Ellipse::dessiner(EZWindow & w , bool isActive) const
{
	Forme :: dessiner (w,isActive);
	const Point & ancre = getAncre (); 
	if (getFill())
		w.fillCircle (ancre.getX(),ancre.getY(),ancre.getX()+demilargeur, ancre.getY()+demihauteur);
	else
		w.drawCircle (ancre.getX(),ancre.getY(),ancre.getX()+demilargeur, ancre.getY()+demihauteur);
}