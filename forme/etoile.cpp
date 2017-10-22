 #include "etoile.hpp"


Etoile::Etoile ( uint x_ , uint y_ , uint cX_, uint cY_ ): Forme( x_ ,y_), x(cX_), y(cY_) /*uint ep_*/
{ cerr<< "Etoile"<<endl ; }


Etoile::Etoile(const Etoile & orig): Forme(orig.getAncre().getX(),orig.getAncre().getY()), x(orig.x), y(orig.y)
{

}

Etoile::Etoile (istream & is ): Forme (is),x(5), y(5)
{
	is >> x >> y;
}


Etoile::~Etoile()
{cerr<< "~Etoile"<<endl ; }

double Etoile::perimetre()const 
{
	return (x+y)*2 ; 
}

void Etoile::ecrire(ostream & os)const
{
	os << "Etoile ";
	Forme::ecrire (os); 
	os<<" "<<x<<" "<<y<<endl; 
}

void Etoile::dessiner(EZWindow & w , bool isActive) const
{
	Forme :: dessiner (w,isActive);
	const Point & ancre = getAncre ();
	double pi=acos(-1.0);
	 uint rayonC1 =50;
	 uint rayonC2=25 ;
	 if (getFill())
	 {
		
	 	w.fillTriangle(ancre.getX()+0, ancre.getY()+rayonC1,ancre.getX()+(rayonC2*cos(11*pi/10)),ancre.getY()+(rayonC2*sin(11*pi/10)),ancre.getX()+(rayonC2*cos(19*pi/10)),ancre.getY()+(rayonC2*sin(19*pi/10)));
		w.fillTriangle(ancre.getX()+(rayonC1*cos(21*pi/10)),ancre.getY()+(rayonC1*sin(21*pi/10)),ancre.getX()+(rayonC2*cos(7*pi/10)),ancre.getY()+(rayonC2*sin(7*pi/10)),ancre.getX(),ancre.getY()-rayonC2);
		w.fillTriangle(ancre.getX()+(rayonC1*cos(17*pi/10)),ancre.getY()+(rayonC1*sin(17*pi/10)),ancre.getX()+(rayonC2*cos(23*pi/10)),ancre.getY()+(rayonC2*sin(23*pi/10)),ancre.getX()+(rayonC2*cos(11*pi/10)),ancre.getY()+(rayonC2*sin(11*pi/10)));
		w.fillTriangle(ancre.getX()+(rayonC1*cos(13*pi/10)),ancre.getY()+(rayonC1*sin(13*pi/10)),ancre.getX()+(rayonC2*cos(19*pi/10)),ancre.getY()+(rayonC2*sin(19*pi/10)),ancre.getX()+(rayonC2*cos(7*pi/10)),ancre.getY()+(rayonC2*sin(7*pi/10)));
		w.fillTriangle(ancre.getX()+(rayonC1*cos(9*pi/10)),ancre.getY()+(rayonC1*sin(9*pi/10)),ancre.getX()+(rayonC2*cos(23*pi/10)),ancre.getY()+(rayonC2*sin(23*pi/10)),ancre.getX(),ancre.getY()-rayonC2);
	 }
	 else 
{
	 
	 
		w.drawLine (ancre.getX()+0, ancre.getY()+rayonC1,ancre.getX()+(rayonC2*cos(23*pi/10)),ancre.getY()+(rayonC2*sin(23*pi/10)));
		w.drawLine (ancre.getX()+(rayonC2*cos(23*pi/10)),ancre.getY()+(rayonC2*sin(23*pi/10)),ancre.getX()+(rayonC1*cos(21*pi/10)),ancre.getY()+(rayonC1*sin(21*pi/10)));
		w.drawLine (ancre.getX()+(rayonC1*cos(21*pi/10)),ancre.getY()+(rayonC1*sin(21*pi/10)),ancre.getX()+(rayonC2*cos(19*pi/10)),ancre.getY()+(rayonC2*sin(19*pi/10)));
		w.drawLine (ancre.getX()+(rayonC2*cos(19*pi/10)),ancre.getY()+(rayonC2*sin(19*pi/10)),ancre.getX()+(rayonC1*cos(17*pi/10)),ancre.getY()+(rayonC1*sin(17*pi/10)));
		w.drawLine (ancre.getX()+(rayonC1*cos(17*pi/10)),ancre.getY()+(rayonC1*sin(17*pi/10)),ancre.getX(),ancre.getY()-rayonC2);
		w.drawLine (ancre.getX(),ancre.getY()-rayonC2,ancre.getX()+(rayonC1*cos(13*pi/10)),ancre.getY()+(rayonC1*sin(13*pi/10)));
		w.drawLine (ancre.getX()+(rayonC1*cos(13*pi/10)),ancre.getY()+(rayonC1*sin(13*pi/10)),ancre.getX()+(rayonC2*cos(11*pi/10)),ancre.getY()+(rayonC2*sin(11*pi/10)));
		w.drawLine (ancre.getX()+(rayonC2*cos(11*pi/10)),ancre.getY()+(rayonC2*sin(11*pi/10)),ancre.getX()+(rayonC1*cos(9*pi/10)),ancre.getY()+(rayonC1*sin(9*pi/10)));
		w.drawLine (ancre.getX()+(rayonC1*cos(9*pi/10)),ancre.getY()+(rayonC1*sin(9*pi/10)),ancre.getX()+(rayonC2*cos(7*pi/10)),ancre.getY()+(rayonC2*sin(7*pi/10)));
		w.drawLine (ancre.getX()+(rayonC2*cos(7*pi/10)),ancre.getY()+(rayonC2*sin(7*pi/10)),ancre.getX()+0, ancre.getY()+rayonC1);
}		
		
}


  // void Etoile::bouger(int x1, int y1, int x2, int y2)
   // {
    // ba_x += ba_dx; ba_y += ba_dy;
    // if (ba_x <= x1) { ba_x = x1; ba_dx = -ba_dx; }
    // else if (ba_x >= x2) { ba_x = x2; ba_dx = -ba_dx; } 
    // if (ba_y <= y1) { ba_y = y1; ba_dy = -ba_dy; }
    // else if (ba_y >= y2) { ba_y = y2; ba_dy = -ba_dy; } 
   // }
