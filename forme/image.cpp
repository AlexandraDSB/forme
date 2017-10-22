#include "image.hpp"




Image::Image( uint ancrex_ , uint ancrey_ , uint x_, uint y_,uint dx_, uint dy_,const char* filename): Forme(ancrex_,ancrey_) ,x(x_),y(y_),dx(dx_),dy(dy_),image(filename)
{
}
  
 Image::~Image()
{}
 
  

void Image::dessiner(EZWindow & w , bool isActive) const
{
	Forme::dessiner (w,isActive);

	const Point & ancre = getAncre ();
	// image.paintSubimage(w,ancre.getX(),ancre.getY(),getx(),gety(),getdx(),getdy());

	EZImage *image2 = new EZImage(image);

	double trans = getTransparence();
	double t = getTaille();
	
	image2= image.scale(t);


	
	image2->setAlpha(trans);
	
	// image2->setAlpha(trans);


	image2->paint(w,ancre.getX(),ancre.getY());
	w.setColor(ez_black);
}


double Image::perimetre()const 
{
	return 0 ; 
}