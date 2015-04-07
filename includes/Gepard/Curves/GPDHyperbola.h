///////////////////////////////////////////////////////////
//  GPDHyperbola.cpp
//  Реализация 	Class GPDHyperbola
//  Создана:   	04-мар-2010 17:57:32
//  Автор: 		Dr_Freeman
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
			* вершина
			*/
			Gepard::BasicMath::GPDPoint Location;
			/**
			* направление
			*/
			Gepard::BasicMath::GPDVector Direction;
			/**
			* радиус1
			*/
			double radius1;
			/**
			* радиус2
			*/
			double radius2;

			/**
			* создать гиперболу
			*/
			void createHyperbola(int numPoints);

			std::vector<Gepard::BasicMath::GPDPoint> local_points;

		};

	}

}

