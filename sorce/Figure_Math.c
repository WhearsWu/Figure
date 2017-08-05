#include "Figure_Math.h"
unsigned short int Figure_Leng(LineType *line)
{
	line->leng = (unsigned short int)sqrt(pow(line->end.x-line->start.x,2)+pow(line->end.y-line->start.y,2));
	return line->leng;
}
unsigned short int Figure_XLeng(LineType *line)
{
	//unsigned short int leng = 0;
	line->leng = fabs(line->start.x-line->end.x);
	return line->leng;
}
unsigned short int Figure_YLeng(LineType *line)
{
	//unsigned short int leng = 0;
	line->leng = fabs(line->end.y-line->start.y);
	return line->leng;
}
void Figure_Middle(LineType *line)
{
	line->Middle.x = (line->end.x+line->start.x)/2;
	line->Middle.y = (line->end.y+line->start.y)/2;	
	//return line->Middle;
}


void Figure_VanishingPoint(LineType line1,LineType line2,PointType *VSP)
{
	float k1,k2;
	k1 = (line1.end.y-line1.start.y)/(line1.end.x-line1.start.x);
	k2 = (line2.end.y-line2.start.y)/(line2.end.x-line2.start.x);
	VSP->x = (line2.start.y-line1.start.y - k1*line1.start.x + k2*line2.start.x)/(k2-k1);
	VSP->y = k1*((int)VSP->x - (int)line1.start.x) - line1.start.y;
}
unsigned short int Figure_Roundf (float x)
{
	unsigned short int a = (unsigned short int)x;
	if(x-a>0.5f)
		return a+1;
	else
		return a;
}
float Figure_Sobel(unsigned short int x,unsigned short int y,unsigned short int *mag)
{	
	short int sobel_x = 0,sobel_y = 0;
		
	//	|-1	0 	+1|
	//	|-2	0 	+2|
	//	|-1	0 	+1|  x
	//	
	sobel_x += image[y+1][x+1]*1;
	//sobel_x += image[y+1][x]*0;
	sobel_x += image[y+1][x-1]*-1;
	
	sobel_x += image[y][x+1]*2;
	//sobel_x += image[y][x]*0;
	sobel_x += image[y][x-1]*-2;
	
	sobel_x += image[y-1][x+1]*1;
	//sobel_x += image[y-1][x]*0;
	sobel_x += image[y-1][x-1]*-1;
	
	
	//	|+1	+2	+1|
	//	|0	0	0 |
	//	|-1	-2	-1|  y
	sobel_y += image[y+1][x+1]*1;
	sobel_y += image[y+1][x]*2;
	sobel_y += image[y+1][x-1]*1;
	
	//sobel_y += image[y][x+1]*0;
	//sobel_y += image[y][x]	*0;
	//sobel_y += image[y][x-1]*0;
	
	sobel_y += image[y-1][x+1]*-1;
	sobel_y += image[y-1][x]*-2;
	sobel_y += image[y-1][x-1]*-1;
	
	*mag = Figure_Roundf(sqrt((sobel_x*sobel_x)+(sobel_y*sobel_y)));
	return atan2f(sobel_y,sobel_x);
}
short int Figure_Convolution(unsigned short int x,unsigned short int y,short int kernel[3][3])
{
	short int add = 0;
	add += image[y+1][x+1]*kernel[2][2];
	add += image[y+1][x]*kernel[2][1];
	add += image[y+1][x-1]*kernel[2][0];
	
	add += image[y][x+1]*kernel[1][2];
	add += image[y][x]*kernel[1][1];
	add += image[y][x-1]*kernel[1][0];
	
	add += image[y-1][x+1]*kernel[1][2];
	add += image[y-1][x]*kernel[1][1];
	add += image[y-1][x-1]*kernel[1][0];
	return add;
}
