#include "rectangle.hpp"


Rectangle::Rectangle ( uint x_ , uint y_ , uint largeur_, uint hauteur_ ): Forme( x_ ,y_), largeur(largeur_), hauteur(hauteur_) /*uint ep_*/
{ cerr<< "Rectangle"<<endl ; }


Rectangle::Rectangle(const Rectangle & orig): Forme(orig.getAncre().getX(),orig.getAncre().getY()), largeur(orig.largeur), hauteur(orig.hauteur)
{

}

Rectangle::Rectangle (istream & is ): Forme (is),largeur(5), hauteur(5)
{
	is >> largeur >> hauteur;
}


Rectangle::~Rectangle()
{cerr<< "~Rectangle"<<endl ; }

double Rectangle::perimetre()const 
{
	return (largeur+hauteur)*2 ; 
}

void Rectangle::ecrire(ostream & os)const
{
	os << "Rectangle ";
	Forme::ecrire (os); 
	os<<" "<<largeur<<" "<<hauteur<<endl; 
}

void Rectangle::dessiner(EZWindow & w , bool isActive) const
{
	Forme :: dessiner (w,isActive);
	const Point & ancre = getAncre ();
	 if (getFill())
	 	w.fillRectangle (ancre.getX(),ancre.getY(),ancre.getX()+largeur, ancre.getY()+hauteur);
	 else 	 
		w.drawRectangle (ancre.getX(),ancre.getY(),ancre.getX()+largeur, ancre.getY()+hauteur);
}