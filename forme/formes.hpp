#ifndef FORMES_HPP
#define FORMES_HPP

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"


using namespace std ;

typedef unsigned int uint ;

class Formes
{
	private : 
	
	const uint maxformes ; 
	uint nbformes ; 
	Forme ** formes ; 
	friend class MyWindow;
	
	public : 
	
	Formes (uint taille= 200);
	~Formes() ; 
	void ajouter(Forme *f );
	Forme * isOver (uint x , uint y );
	void dessiner (EZWindow & w );
	friend		 ostream& operator<< (ostream & os , const Formes & fs);
	void sauver(ostream & os) const;
	void charger ( istream & is );
	
	
};





#endif 