// MyWindow.cpp
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

#include "formes.hpp"

#include "point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "ellipse.hpp" // avec quelques formes.
#include "cercle.hpp"
#include "rectangle.hpp"
#include "carre.hpp"
#include "triangle.hpp"
#include "image.hpp"
#include "etoile.hpp"

MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),formes(200),pforme(nullptr)
{
	setDoubleBuffer(true);
	
}
		
MyWindow::~MyWindow()
{}

void MyWindow::expose()
{
 setColor(EZWindow::getRGB(224,224,224));
 fillRectangle( 0, 0,getWidth()-1, getWidth()-20);
 formes.dessiner(*this);
 if(pforme!=nullptr) pforme->dessiner(*this,true);

 setColor(ez_black);
 drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
 if(button==1)
   pforme = formes.isOver(mouse_x,mouse_y);
}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
 if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
   pforme->setAncre(mouse_x,mouse_y);
    // on la bouge.
  sendExpose();
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
 if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
   pforme->setAncre(mouse_x,mouse_y); 

 sendExpose();
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{




  switch (keysym)
    {
     case EZKeySym::Escape:
     case EZKeySym::q :       EZDraw::quit (); break;
     case EZKeySym::E:
      cout << formes;
      break;
     case EZKeySym::S:
      {
       ofstream f("formes.txt");
        formes.sauver(f);
      } 
      break;
     case EZKeySym::C:
      {
       ifstream f("formes.txt");
       formes.charger(f);
      }
      break;
     case  EZKeySym::plus :
       if(pforme) pforme->setEpaisseur(pforme->getEpaisseur()+1); 
     break;
	 case EZKeySym::minus: if (pforme) pforme->setEpaisseur(pforme->getEpaisseur()-1); break;
	 case EZKeySym::F: pforme->setFill(true); break;
	 case EZKeySym::p: if (pforme) pforme->setTaille(pforme->getTaille()+0.02);   break;
     case EZKeySym::m: if (pforme) pforme->setTaille(pforme->getTaille()-0.02);   break;
     case EZKeySym::A: pforme->setTransparence(pforme -> getTransparence() -true); break;
     case EZKeySym::_0: if(pforme) pforme->setCouleur(ez_black);   break;
     case EZKeySym::_1: if(pforme) pforme->setCouleur(ez_grey);    break;
     case EZKeySym::_2: if(pforme) pforme->setCouleur(ez_red);     break;
     case EZKeySym::_3: if(pforme) pforme->setCouleur(ez_green);   break;
     case EZKeySym::_4: if(pforme) pforme->setCouleur(ez_blue);    break;
     case EZKeySym::_5: if(pforme) pforme->setCouleur(ez_yellow);  break;
     case EZKeySym::_6: if(pforme) pforme->setCouleur(ez_cyan);    break;
     case EZKeySym::_7: if(pforme) pforme->setCouleur(ez_magenta); break;
     case EZKeySym::h:
      cout << "q : quitter" << endl
           << "h : cette aide" << endl
           << "E : ecrire la liste des formes sur la console" << endl
           << "S : sauver la liste des formes sur disque" << endl
           << "C : charge la liste des formes depuis le disque" << endl
		   << "F : forme remplie"    << endl
           << "+ : augmente l'épaisseur"    << endl
           << "- : diminue l'épaisseur"     << endl
           << "0 : met en noir la forme"    << endl
           << "1 : met en gris la forme"    << endl
           << "2 : met en rouge la forme"   << endl
           << "3 : met en vert la forme"    << endl
           << "4 : met en bleu la forme"    << endl
           << "5 : met en jaune la forme"   << endl
           << "6 : met en cyan la forme"    << endl
           << "7 : met en magenta la forme" << endl
           << "r : cree un rectangle" << endl
           << "e : cree une ellipse" << endl
           << "s : cree un carré" << endl
           << "c : cree un cercle" << endl
           << "t : cree un triangle" << endl
		   << "i : cree une image" << endl
		    << "z : cree une etoile" << endl
		   << "p: augmente la taille de l'image"   << endl
			<< "m :diminuer la taille de l'image"    << endl
			<< "A : active la transparence de l'image"    << endl
           ;
      break;
	  // Création des formes selon le caractère choisie par l'utilisateur qui existe 
     case EZKeySym::r: formes.ajouter(new Rectangle(getWidth()/2,getHeight()/2-50,getWidth()/2-10,getHeight()/2-50)); break; 
     case EZKeySym::e: formes.ajouter(new Ellipse(getWidth()/2-25,getHeight()/2-15,50,30)); break;
     case EZKeySym::s: formes.ajouter(new Carre(getWidth()/2-25,getHeight()/2-25,50)); break;
     case EZKeySym::c: formes.ajouter(new Cercle(getWidth()/2-25,getHeight()/2-25,25)); break;
     case EZKeySym::t: formes.ajouter(new Triangle(getWidth()/2,getHeight()/2-50,getWidth()/2-25,getHeight()/2-20,getWidth()/2-20,getHeight()/2-50)); break;
	 case EZKeySym::i:formes.ajouter(new Image(getWidth()/2,getHeight()/2-50,getWidth()/2-10,getHeight()/2-50,getWidth()/2-25,getHeight()/2-20,"linux_pingouin.gif")); break;
	 case EZKeySym::z: formes.ajouter(new Etoile(getWidth()/2,getHeight()/2-50,getWidth()/2-10,getHeight()/2-50)); break;
     default:
      break;
    }
 sendExpose();
}
 