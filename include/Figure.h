#ifndef _Figure_H
#define _Figure_H
#include "Figure_Define.h"
#include "Figure_Transform.h"
#include "Figure_Math.h"
extern unsigned char Blackline_bian[PictreHeight][2];

void Figure_edge(void);
void Figure_RectangularToDescartes(PointListType blackp,DEPointListType *deblackp);//��ֱ������任���ѿ�������ϵ
void Figure_HoughTransform(PointListType EdgePoint,DELineType *outputLinet,unsigned short int threshold,float Accuracy);//����任��ֱ��
unsigned short int Figure_TowPoint(LineType *EdgeLeft,LineType *EdgeRight);//����ȷ���߽�
void Figure_LeastSquares(unsigned char blackline[PictreHeight][3],float *k,float *Distence);//��С���˷���ֱ��б��
void Figure_DescartesToRectangular(DELineType *DEline,RTLineType *line);//�ѻ���任���ֱ��ת����ֱ������ϵֱ��
void Figure_Corrosion(unsigned short int effects);//�����港ʴ��effects:ǿ��
void Figure_FindCircles(PointListType *output);//Ѱ�Ҷ��Բ
void Figure_FindSingleCircle(PointType *output);//Ѱ�ҵ���Բ
#endif
