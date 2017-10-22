#ifndef FORME_HPP
#define FORME_HPP

#include <iostream> 

#include "point.hpp"

#include "ez-draw++.hpp"

#include <string>


using namespace std ; 

typedef unsigned long int ulong ; 

typedef unsigned int uint ; 

class Forme
{

	private: 
	ulong couleur; 
	Point ancre;
	bool select;
	uint epaisseur; // variable pour regler l'épasaur des trais 
	bool fill; //  variable pour dire si on veut des formes pleine ou vide 
	double varTaille; // variable pour regeler la taille de l'image 
	bool transparence ; // variable pour rege la transparence de l'image 
	
	protected:
	virtual  void     ecrire (ostream & os )const ;

	public:
                      Forme ( uint x_ , uint y_) ;
                      Forme (const Forme & orig );
                      Forme (istream & is);
  	virtual           ~Forme () ; 
	
  	inline   ulong    getcouleur()const {return couleur; }
  	inline   void     setCouleur (ulong couleur_){ couleur = couleur_;}
	
    inline	 Point 	  getAncre()const{return ancre;}
    inline	 void  	  setAncre(uint x_ , uint y_){ancre.setXY(x_,y_);}
	
    inline   uint     getEpaisseur()const {return epaisseur;}
    inline     void    setEpaisseur(uint ep_){ epaisseur=ep_;}
	
	inline  bool getFill () const {return fill;}
	inline  void setFill (bool b ){fill=b;}
	
	 inline	 int 	  getTransparence()const{return transparence;}
    inline	 void  	  setTransparence(int transparence_){transparence=transparence_;}

	inline  double    getTaille()const{return varTaille ; }
    inline	 void  	  setTaille(double taille_){varTaille= taille_ ;}
	
  	inline   bool     isOver (uint x_ , uint y_ ){ return ancre.isOver(x_, y_ );}
  	virtual  void     dessiner(EZWindow & p , bool active=false ) const ;
    virtual  double   perimetre() const = 0;
  	friend   ostream & operator << (ostream & , const Forme& );
    
    static   Forme *   charger(istream & is );
	
    
};

#endif 