#ifndef _FIGURE_MATH_H
#define _FIGURE_MATH_H
#include "Figure_Define.h"
#include "math.h"
unsigned short int Figure_Leng(LineType *line);//计算一条线段的长度
unsigned short int Figure_XLeng(LineType *line);//计算一条线段X方向上投影长度
unsigned short int Figure_YLeng(LineType *line);//计算一条线段Y方向上投影长度
void Figure_Middle(LineType *line);//计算一条线的中点坐标
void Figure_VanishingPoint(LineType line1,LineType line2,PointType *VSP);//计算两直线交点
unsigned short int Figure_Roundf (float x);
float Figure_Sobel(unsigned short int x,unsigned short int y,unsigned short int *mag);
short int Figure_Convolution(unsigned short int x,unsigned short int y,short int kernel[3][3]);
#endif	
