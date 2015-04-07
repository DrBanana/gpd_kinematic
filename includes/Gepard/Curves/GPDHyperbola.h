///////////////////////////////////////////////////////////
//  GPDHyperbola.cpp
//  ���������� 	Class GPDHyperbola
//  �������:   	04-���-2010 17:57:32
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "TemplateCurve.h"
#include <vector>

namespace Gepard
{
	namespace Curves
	{
		class GPDHyperbola : public Gepard::Curves::GPDCurve
		{

		public:
			GPDHyperbola();
			~GPDHyperbola();
			GPDHyperbola(double r1, double r2, Gepard::BasicMath::GPDPoint location, Gepard::BasicMath::GPDVector direction)
			{
				radius1=r1;radius2=r2;Location=location;Direction=direction;
			}

			/**
			* �������
			*/
			Gepard::BasicMath::GPDPoint Location;
			/**
			* �����������
			*/
			Gepard::BasicMath::GPDVector Direction;
			/**
			* ������1
			*/
			double radius1;
			/**
			* ������2
			*/
			double radius2;

			/**
			* ������� ���������
			*/
			void createHyperbola(int numPoints);

			std::vector<Gepard::BasicMath::GPDPoint> local_points;

		};

	}

}

