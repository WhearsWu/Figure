#ifndef _FIGURE_MATH_H
#define _FIGURE_MATH_H
#include "Figure_Define.h"
#include "math.h"
unsigned short int Figure_Leng(LineType *line);//����һ���߶εĳ���
unsigned short int Figure_XLeng(LineType *line);//����һ���߶�X������ͶӰ����
unsigned short int Figure_YLeng(LineType *line);//����һ���߶�Y������ͶӰ����
void Figure_Middle(LineType *line);//����һ���ߵ��е�����
void Figure_VanishingPoint(LineType line1,LineType line2,PointType *VSP);//������ֱ�߽���
unsigned short int Figure_Roundf (float x);
float Figure_Sobel(unsigned short int x,unsigned short int y,unsigned short int *mag);
short int Figure_Convolution(unsigned short int x,unsigned short int y,short int kernel[3][3]);
#endif	
