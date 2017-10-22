#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#define Rectangle Rect

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Rectangle : public Forme 
{
private: 
	uint largeur; 
	uint hauteur; 
protected:
	void ecrire (ostream & os )const override ; 
public: 
	Rectangle ( uint x , uint y, uint longeur ,uint hauteur); 
	 Rectangle(const Rectangle & orig);
	Rectangle(istream & is); 
	~Rectangle()override ; 
	void dessiner(EZWindow & f, bool isActive= false) const override ; 
	inline uint getlargeur()const {return largeur;}
	inline void setlargeur(uint _largeur){largeur=_largeur;}
	inline uint gethauteur()const {return hauteur;}
	inline void sethauteur(uint _hauteur){hauteur=_hauteur;}
	 double perimetre()const override;



};



#endif 