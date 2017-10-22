#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>


#include "ez-draw++.hpp"

using namespace std; 

typedef unsigned int uint ; 

/* Cette classe permet de cree un point */

class Point 
{
	private:
	static const uint  taille =3 ; 
	uint x;
	uint y; 
	friend class Forme ; 
	public: 
					Point (uint x_ , uint y_ ); // Construceur de point 
					Point (const Point & orig); // Constructeur par copie
					Point(istream & is ); // Construceut par istream 
					~Point() ; // Destructeur 
	inline 	uint 	getX() const {return x;} // Methode pour obtenir la coordonnée x du point
	inline 	uint 	getY() const {return y;} //Methode pour obtenir la coordonnée y du point
	inline 	void 	setXY(uint x_, uint y_){x=x_ ; y=y_;} // methode pour chager les coordonnées du point
			bool 	isOver (uint x_, uint y_);  // Methode pour sevoir si on est sur les points c'est une methode override 
	void dessiner( EZWindow & f , bool isActive = false) const ; // Methode qui permet de dessiner le point 
	friend ostream & operator << (ostream & os , const Point & p );  // Methode qui deffini l'ecriture du point en sortie 
	friend istream & operator >> (istream & is , Point & p ); // Methode qui deffini l'ecriture du point en entrer 



};


#endif




