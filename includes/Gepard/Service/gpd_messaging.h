///////////////////////////////////////////////////////////
//  gpd_messaging
//  ���������� 	������� ������� �������������� � 
//				������ ���������
//  �������:   	1-���-2012 13:33:14
//  �����: 		Anton
///////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>
#include <list>

#include "..\gepardDefines.h"
#include "..\Surfaces\SURFACE_TYPES.h"

typedef std::vector<std::string> std_stringsVector; //������ �����
typedef std::list<std::string> std_stringsList;     //������ �����

namespace Gepard 
{
    namespace Service 
    {

        /**
        *	������� ��� �������� ������������ ������
        */
        std::string formatMessage(char *fmt, ...);

        /**
         *  �������� ������ � ����� �����������
         *  ��� ����������� �������� ����� Gepard::Surfaces::SURFACE_TYPES
         */
        std::string getSurfaceTypeStr(Gepard::Surfaces::SURFACE_TYPES surfType);

//��������� ������������� ��. � "..\gepardDefines.h"
#ifdef GPD_WIN
        /**
        *	������� ������ ��������� � ���� AfxMessageExt
        *	�������� ������ ��� Windows
        */
        void gpd_ShowMessageWIN(char *fmt, ...);

        /**
        *	������� ������ ��������� � ���� AfxMessageExt
        *	�������� ������ ��� Windows
        */
        void gpd_ShowMessageWIN(std::string _message);
#endif

    }; //namespace Service
}; //namespace Gepard