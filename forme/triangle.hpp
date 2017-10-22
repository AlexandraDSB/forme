#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream> 

#include "ez-draw++.hpp"

#include "forme.hpp"

using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 


class Triangle : public Forme
{
private: 
 
	uint coor1x;
	uint coor1y;
	uint coor2x;
	uint coor2y; 
protected:
	void ecrire (ostream & os )const override ; // Methode qui permet d'ecrire un sauvegarde des formes contruites dans un fichier texte 
public: 
				Triangle (uint x, uint y,uint x1_, uint y1_, uint x2_, uint y2_);// Construceur 
				Triangle(const Triangle & orig); // Constructeur par copie
				Triangle(istream & is); // Construceut par istream 
				~Triangle()override ;  // Destructeur
		   void dessiner(EZWindow & f, bool isActive= false) const override ; // Methode qui permet de dessiner

	inline uint getcoor1x()const {return coor1x;} // Methode qui permet d'obtenir la coordonnée x1
	inline void setcoor1x(uint coor_){coor1x=coor_;} // Methode qui permet de modifier la coordonnée x1
	
	
	inline uint getcoor1y()const {return coor1y;}// Methode qui permet d'obtenir la coordonnée y1
	inline void setcoor1y(uint coor_){coor1y=coor_;} // Methode qui permet de modifier  la coordonnée y1
	
	
	
	inline uint getcoor2x()const {return coor2x;} // Methode qui permet d'obtenir la coordonnée x1
	inline void setcoor2x(uint coor_){coor2x=coor_;} // Methode qui permet de modifier la coordonnée x1
	
	inline uint getcoor2y()const {return coor2y;} // Methode qui permet d'obtenir la coordonnée y1
	inline void setcoor2y(uint coor_){coor2y=coor_;} // Methode qui permet de modifier la coordonnée y1

		 double perimetre()const override;
};



#endif 