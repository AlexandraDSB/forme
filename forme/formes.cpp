#include "formes.hpp" 
#include <stdexcept>


using namespace std ; 


Formes::Formes (uint taille ):maxformes(taille), nbformes(0),formes(nullptr) 
{
	cerr<<"Formes::Formes (uint taille )"<<endl; 
	formes = new Forme *[maxformes];
}

Formes::~Formes()
{
	for (uint i = 0 ; i< nbformes ; i++)
		delete formes[i];
	delete [] formes ; 
}




void Formes::ajouter(Forme * f )
{
	if (nbformes <maxformes ) 
		formes [nbformes++]= f ; 
	else 
		throw runtime_error ("Impossible d'ajouter nouvelle forme ! ");
	
}

Forme * Formes::isOver(uint x , uint y ) 
{
	for (uint i = 0 ; i <nbformes ; i++ ) 
		if (formes[i]-> isOver(x,y))
			return formes[i];
		
	return nullptr; 
}

void Formes::dessiner (EZWindow& w)
{
	for (uint i=0 ; i< nbformes ; i++ )
		formes[i]-> dessiner(w);
}


ostream& operator<<( ostream & os , const Formes & fs ) 
{
	for (uint i=0 ; i <fs.nbformes ; ++i ) 
		os<< *fs.formes[i]<<endl; 
	
	
	return os ;
}


void Formes::charger(istream & is ) 
{
	
	for (uint i =0 ; i<nbformes ; ++i)
	{
		delete formes[i];
	}
		
		
	
	nbformes = 0 ;
	uint nb;
	is >> nb ; 
	cerr<<"nbapresis "<<nb <<endl;

	for (uint i =0; i< nb; ++i ) 
	{
		ajouter(formes[i]->Forme::charger(is));
		
	}
		cerr<<"  tiurt"<<nb <<endl;

}


void Formes::sauver(ostream & fichier)const
{

    if(fichier)
    {
            fichier << nbformes<< endl;
            for (uint i =0 ; i<nbformes ; i++)
            	fichier << *formes[i] ;
    }
    else
            cerr << "Impossible d'ouvrir le fichier !" << endl;

}