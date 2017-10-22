// Class MyWindow.hpp

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "Formes.hpp"

#define MyWindow MW

class MyWindow : public EZWindow {
  Formes formes; 
  Forme  *pforme;
 public:
  MyWindow(int w, int h,const char *name); // Construteur 
  ~MyWindow();// Destructeur 
  void expose(); //Permet d'afficher sur la fenêtre courante 
  void keyPress(EZKeySym keysym); // methode qui permet des savoir quelle touche du claveir est presser
  void buttonPress(int mouse_x,int mouse_y,int button); // Cette methode permet de savoir si le clic de la souris est sur un forme ou non 
  void motionNotify(int mouse_x,int mouse_y,int button); // Cette methode permet de bouger la forme tans que elle est selectionnée .
  void buttonRelease(int mouse_x,int mouse_y,int button); // Cette methode permet de enregistre les coordonnée de la souris et de pose les forme lorsque le cliv droit est relaché.
};

#endif
