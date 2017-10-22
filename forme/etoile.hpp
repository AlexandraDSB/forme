#ifndef ETOILE_HPP
#define ETOILE_HPP



#include <iostream> 

#include "ez-draw++.hpp"

#include <cmath>

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Etoile : public Forme 
{
private: 
	uint x; 
	uint y; 
protected:
	void ecrire (ostream & os )const override ; 
public: 
	Etoile( uint x , uint y, uint longeur ,uint hauteur); // Construceur 
	Etoile(const Etoile & orig);// Constructeur par copie
	Etoile(istream & is); // Construceut par istream 
	~Etoile()override ;  // Destructeur
	void dessiner(EZWindow & f, bool isActive= false) const override ; // Methode qui permet de dessiner
	inline uint getcoorX()const {return x;} // Methode qui permmet d'obtenir la coordonnée x
	inline void setcoorX(uint x_){x=x_;} // Methode qui permet de modifier la coordonnée x
	inline uint getcoorY()const {return y;} // Methode qui permmet d'obtenir la coordonnée y
	inline void setcoorY(uint y_){y=y_;} // Methode qui permet de modifier la coordonnée y
	 double perimetre()const override; 
	 



};



#endif 