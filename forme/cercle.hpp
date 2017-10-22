#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Cercle : public Forme
{
private: 
	uint rayon;  
protected:
	void ecrire (ostream & os )const override ; 
public: 
	Cercle ( uint x , uint y, uint rayon);// Construceur 
	Cercle(const Cercle & orig); // Constructeur par copie
	Cercle(istream & is); // Construceut par istream 
	~Cercle()override ;  // Destructeur
	void dessiner(EZWindow & f, bool isActive= false) const override ; // Methode qui permet de dessiner
	inline uint getrayon()const {return rayon;} // Methode qui permmet d'obtenir rayon 
	inline void setrayon(uint rayon_){rayon=rayon_;} // Methode qui permet de modifier rayon
	double perimetre()const override;
};



#endif 