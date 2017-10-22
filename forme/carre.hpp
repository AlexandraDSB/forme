#ifndef CARRE_HPP
#define CARRE_HPP

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Carre : public Forme
{
private: 
	uint cote;  
protected:
	void ecrire (ostream & os )const override ; 
public: 
	Carre ( uint x , uint y, uint cote);// Construceur de carré
	Carre(const Carre & orig);// Constructeur par copie
	Carre(istream & is); // Construceut par istream 
	~Carre()override ;  // Destructeur
	void dessiner(EZWindow & f, bool isActive= false) const override ; // Methode qui permet de dessiner carré
	inline uint getcote()const {return cote;} // Methode qui permet d'obtenir la valeur du coté 
	inline void setcote(uint cote_){cote=cote_;} // Methode qui permet de modifier la valeur du coté
	double perimetre()const override; 
};



#endif 