#include "forme.hpp"




Forme::Forme ( uint x_ , uint y_ ) : couleur (ez_black), ancre(x_,y_), select (false),epaisseur(1),fill(false),varTaille(1),transparence(false)
{
	 
}


Forme::Forme (const Forme & orig ): couleur(orig.couleur), ancre (orig.ancre), select(false), epaisseur(orig.epaisseur), fill (orig.fill)
{
 
}

Forme::Forme (istream & is):couleur(0),ancre(0,0),select(false),epaisseur(1), fill(false)
{
	
	is >> couleur >> ancre ; 
}

  Forme::~Forme () 
{
	

} 



void Forme::ecrire (ostream & os ) const
{
	os<<couleur << " "<<ancre<<" "<<epaisseur ; 
}

void Forme::dessiner(EZWindow & f , bool isActive) const
{	
	
	
	f.setThick(1);
	
	if (getFill())
	{
	
		ancre.dessiner(f,isActive);
		f.setColor(ez_white);
	}
	else
	{
		f.setColor(ez_black);
		ancre.dessiner(f,isActive);
	}
	f.setColor(couleur);
	f.setThick(epaisseur);
	


	 
}




ostream & operator << (ostream &  os , const Forme & f )
{ 
	f.ecrire(os); return os ; 
}


#include "rectangle.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"
#include "carre.hpp"
Forme * Forme :: charger (istream & is )
{	
	string type ; 
	// getline(is,  type); /* ici je capture la ligne que je recoi en 
	// je la met dans la variable type */
	
	is >> type ; 
	cerr<<"type" <<type<<endl ;
	
	
	if (type =="Rectangle") 
		return new Rectangle(is) ;
	else if  (type=="Ellipse")
		return new Ellipse (is); 
	else if (type=="Cercle")
		return new Cercle(is);
	else if (type=="Carre")
		return new Carre(is);
	else 
		throw runtime_error("Impossible de lire ");
}
// Forme * Forme :: charger (istream & is )
// {	
// 	string type ; 
// 	getline(is,  type);
	
// 	is >> type ;
	
// 	switch( string(type))
// 	{
// 		case "Rectangle":
// 			return new Rectangle(is) ;
// 			break;
// 		case "Ellipse":
// 			return new Ellipse (is); 
// 			break;
// 		case "Cercle":
// 			return new Cercle(is);
// 			break ;
// 		case"Carre": 
// 			return new Carre(is);
// 			break;
// 		default : 
// 			cerr<< "fin tu chargement " ; 
// 			break; 

// 	}
	
// }