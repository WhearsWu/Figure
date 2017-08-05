#ifndef _Figure_H
#define _Figure_H
#include "Figure_Define.h"
#include "Figure_Transform.h"
#include "Figure_Math.h"
extern unsigned char Blackline_bian[PictreHeight][2];

void Figure_edge(void);
void Figure_RectangularToDescartes(PointListType blackp,DEPointListType *deblackp);//将直角坐标变换到笛卡尔坐标系
void Figure_HoughTransform(PointListType EdgePoint,DELineType *outputLinet,unsigned short int threshold,float Accuracy);//霍夫变换求直线
unsigned short int Figure_TowPoint(LineType *EdgeLeft,LineType *EdgeRight);//两点确定边界
void Figure_LeastSquares(unsigned char blackline[PictreHeight][3],float *k,float *Distence);//最小二乘法求直线斜率
void Figure_DescartesToRectangular(DELineType *DEline,RTLineType *line);//把霍夫变换后的直线转换成直角坐标系直线
void Figure_Corrosion(unsigned short int effects);//将画面腐蚀，effects:强度
void Figure_FindCircles(PointListType *output);//寻找多个圆
void Figure_FindSingleCircle(PointType *output);//寻找单个圆
#endif
