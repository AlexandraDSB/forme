#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream> 

#include "point.hpp"

#include "ez-draw++.hpp"

#include "forme.hpp"


class Image :public Forme 
{
private:
	
	uint x;
	uint y;
	uint dx;
	uint dy;
	EZImage  image; 
public:
 
 Image(uint ancrex_ , uint ancrey_,uint x_, uint y_,uint dx_, uint dy_,const char* filename);
 ~Image();
  
			


	inline uint getx()const {return x;}
	inline void setx(uint x_){x=x_;}

	inline uint gety()const {return y;}
	inline void sety(uint y_){y=y_;}

	inline uint getdx()const {return dx;}
	inline void setdx(uint dx_){dx=dx_;}

	inline uint getdy()const {return dy;}
	inline void setdy(uint dy_){dy=dy_;}

	inline EZImage  getImg()const {return image;}
	inline void     setImg(EZImage image_){image=image_;}

	void dessiner(EZWindow & w , bool isActive) const;
	double perimetre() const; 




	  
			 

};

#endif
