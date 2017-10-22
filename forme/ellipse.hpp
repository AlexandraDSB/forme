#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Ellipse : public Forme 
{
private: 
	uint demilargeur; 
	uint demihauteur; 
protected:
	void ecrire (ostream & os )const override ; 
public: 
	Ellipse (uint x , uint y, uint demilongeur ,uint demihauteur);// Construceur 
	Ellipse(const Ellipse & orig); // Constructeur par copie
	Ellipse(istream & is); // Construceut par istream 
	~Ellipse()override ;  // Destructeur
	
	void dessiner(EZWindow & f, bool isActive= false) const override ; // Methode qui permet de dessiner
	
	inline uint getdemilargeur()const {return demilargeur;} // Methode qui permmet d'obtenir demilargeur
	inline void setdemilargeur(uint demilargeur_){demilargeur=demilargeur_;} // Methode qui permet de modifier  demilargeur
	
	inline uint getdemihauteur()const {return demihauteur;} // Methode qui permmet d'obtenir demihauteur
	inline void setdemihauteur(uint demihauteur_){demihauteur=demihauteur_;} // Methode qui permet de modifier demihauteur
	double perimetre()const override;



};



#endif 