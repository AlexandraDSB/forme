#include "carre.hpp"


Carre::Carre ( uint x_ , uint y_, uint cote_) : Forme(x_,y_),cote(cote_)
{

}

Carre::Carre (istream & is): Forme(is ),cote(5)
{
	is >> cote; 
}


Carre::Carre(const Carre & orig): Forme( orig.getAncre().getX(),orig.getAncre().getY()),cote(orig.getcote())
{

}

Carre::~Carre()
{

}

double Carre::perimetre()const
{
	return cote*4;
}

void Carre::ecrire(ostream & os )const 
{
	os << "Carre ";
	Forme::ecrire(os); 
	os<<" "<<cote<<endl ; 
}


void Carre::dessiner(EZWindow & f, bool isActive)const 
{
	Forme:: dessiner (f,isActive);
	const Point & ancre = getAncre(); 
	if (getFill())
		f.fillRectangle (ancre.getX(),ancre.getY(),ancre.getX()+cote,ancre.getY()+cote);
	else 	
		f.drawRectangle (ancre.getX(),ancre.getY(),ancre.getX()+cote,ancre.getY()+cote);
}
