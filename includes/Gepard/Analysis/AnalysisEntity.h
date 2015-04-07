///////////////////////////////////////////////////////////
//  AnalysisEntity.h
//  ����������� ��������, ������������ � �������
//  �������:  30-���-2014
//	������������ �����: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "../General/basicList.h"
#include "../General/basicArray.h"

namespace Gepard 
{
    namespace Analysis 
    {    
        /**
         *	��� ��������
         */
        enum ANALYSIS_ENT_TYPE 
        {            
            AET_CP_TOLERANCE,          //������
            AET_CP_FIT,                //�������
            AET_AR_MATING_RELATION,    //������� ����������
            AET_AR_OTHER			   //������ - ��� ����� ��������� ��� ����
        };
    
        /**
         *	����������� ��������
         */
        struct AnalysisEntity
        {
            /**
             *	��� ������� �������
             */
            ANALYSIS_ENT_TYPE _type;
            /**
             *	��������� �� ����� ��������
             *	(������ ��� �������������� ��-�������)
             */
            void* _data;
        };
        /**
         *  ������ ���������
         */
        class AnalysisEntityList : public Gepard::General::basicList<AnalysisEntity>
        {
        public:
            /**
             *  ����� �������� �� ���������
             */
            int findByData(void *p)
            {
                set_start();
                while (auto e = get_next())
                {
                    if (e->_data == p) return get_current_index();
                }
                return -1;
            }
        };
    }//Analysis
}//Gepard
