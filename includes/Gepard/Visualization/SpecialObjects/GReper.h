///////////////////////////////////////////////////////////
// GReper.h
// ����������� ������ - �����
// Created on:      31-���-2014 13:38:14
// Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GREPER_H
#define GREPER_H
#pragma once

#include "SpecialObject.h"
#include "GAxis.h"

namespace Gepard 
{
    namespace Visualization
    {

        namespace SpecialObjects 
        {

            /**
             *  ����������� ����������� ������ - �����
             */
            class GReper : public SpecialGObject
            {
            public:

                enum GR_TYPE
                {
                     GR_LINES       //�����
                    ,GR_CONE_ARROW  //� ����������� ��������� �� ������
                    ,GR_CONE_CYL    //������ � ��������
                };

                GReper(GFontManager *fManager=nullptr);

                /**
                 *  ���������� ���������� ������
                 */
                void SetCoords(GVector r, GVector e1, GVector e2, GVector e3);

                /**
                 *  ���������� ��� ������
                 */
                void SetType(GR_TYPE _type);

                /**
                 *  ���������� �� �����
                 */
                void ShowText(bool show = true);

                /**
                 *  ���������� ����� ��� �����
                 */
                void SetLabelText(std::string Rs, std::string E1s, std::string E2s, std::string E3s);

                /**
                 *  ���������� ���������������� �������
                 */
                void SetScale(bool flag=true) override;

                /**
                 *  ���������� �������� ������������ ���-��������������� 
                 * (� ������, ���� scale_on = false)
                 */
                void SetUnScaleFactor(float unscale) override;

                /**
                 *  ������� ����������� �������
                 */          
                void Render() override;

            private:
                /**
                 *  ��� ������������ �������
                 */
                GR_TYPE reper_type;          
                /**
                 *  ��� ���
                 */
                GAxis E1,E2,E3;            
         
                /**
                 *  ���������� �� ��������� �����
                 */
                bool isShowText;          

            };
        } // SpecialObjects
    }//Visualization
}// Gepard 

#endif