///////////////////////////////////////////////////////////
//  GSceneItem
//  ����� �������� ����������� �����
//  Created on:      17-���-2014 17:32:15
//  Original author: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "GPrimitive.h"
#include "GText.h"

namespace Gepard
{
    namespace Visualization
    {   
        class GCamera;

        /**
         *  ����������� ������, ��������� �� ����������
         */
        typedef std::list<GPrimitive> GObject;

        /**
         *  ���-�������, ����������� ��� ��������� � �����: ������ ������� � ��� ������ �������
         */
        typedef boost::unordered_map<GPRIMITIVE_TYPE, PIndexes> IndexesPointsHash;               

        /**
         *  ����� ������������ ����� ����������� ����� ��� ������
         */
        class GSceneItem 
        {
        public:
            GSceneItem();
            ~GSceneItem();
                    
            /**
             *  ������ ��������� ������ ��� ���������� (��������� ����-������)
             */
            float *VertexArray;

            /**
             *  ������ ��������� �������� ������
             */
            float *NormalArray;

            /** 
             *  ������ ����� ������
             */
            float *ColorArray;           

            /**
             *	����� ����� ������
             */
            unsigned int VertexCount;

            /**
             *	��������� �������� �������� ��� VBO
             */
            ObjVBOBufferIndexes _vbo;

            /**
             *  ������ �������������� ��������, ��������� �� ����������
             */
            std::list<GObject> GObjectsList;

            /**
             *  ��������� ������ ������ ��� ��������, ��������������� �� ����� ����������
             */
            std::list< IndexesPointsHash >  ObjectVertexIndexes;

            /**
             *  ������ �������� �������� ��� ����������� � ������ ������� ����. �����
             */
            std::list<GText> TextObjects;

            /**
             *  �������, �� ������� ���������� ���� (� �� ��������)
             */
            boost::unordered_set< GObject* > ObjColored;

            /**
             *  ������������ ������
             */
            GCamera* parentCamera;
                       
            /**
             *  ������� �������������� ��������� ��� �����������
             */
            void PrepareRenderData();
                       
            /**
             *  ������� ������� ��� ����������� ������ ������
             */
            void ClearSceneItemData();

            /**
             *  �������� ��������� �������� ������� �����
             */
            unsigned long GetSettings();

            /**
             *  ���������� ����� ���������
             */
            void SetSettings(unsigned long _flags);          

            /**
             *  ���� �� ����� ���������
             */
            bool Is(GSCENE_ITEM_SETTINGS setting);

            /**
             *  ���������� ��������� �������
             */
            void SetVisible(bool _visible);

            /**
             *  ������� �� �������
             */
            bool isVisible();

            /**
             *  �������� ��������� �� ����������� ������ �� �������
             */
            GObject* getGObjectByIndex(int index);

            /**
             *  �������� ��������� ������
             */
            GText* AddGText(GText _text = GText());

            /**
             *  ������� ��������� ������ �� �������
             */
            void DeleteGText(GText* _text);

            /**
             *  ������� ��� ��������� �������
             */
            void DeleteGTexts();
            
            /**
             *  �������� ������ ������ ��� ������� �� ������
             */
            IndexesPointsHash* FindIndexesPointsHash(int obj_index);

            /**
             * �������� ���������� ������������ ������� (�� ������� ������� � �������)
             * ������ �������� - ������ �� ������-�������.
             * �������� ������-������� - ��������� �� ��������� ������ 
             * (�� ����� ������ ��������� ���������� ����� �������).
             */
            void ModifyObject(int obj_index, std::function<void(float *)> &funcRef);

             /**
              * ���������� ������������� ������������ (n_index) 
              * ���������� �������� ������� (t_index) ������ �����.
              * ������� ������ ���� ����������.
              * ����������� ������ ���������� � n_item
              */
             void SetEquivalent(int t_index, GSceneItem* n_item, int n_index);

            /**
             *  ������� ������������� ���� ������������ ������� �� �������
             */
            void SetObjectColor( int obj_index, float R, float G, float B, float Alpha, bool isDropColor = false );

            /**
             *  ���������� ���� ������� �� �������
             */
            void DropObjectColor(int obj_index);

            /**
             *  ������� ������� ������ VBO ��� ������� ������� �����
             */
            void BuildVBO( unsigned int filteredV );

            /**
             *	������� ������� VBO
             */
            void ClearVBOData();

        private:

            /**
             *  ������� �� �������
             */
            bool visible;

            /**
             *  ��������� ������� �����
             */
            unsigned long _settings;
          
            /**
             *  ������� ������� ��������� �������, ������������ ��� ����������
             */
            void ClearTempRenderData(bool isDeleteVBOData = true);

             /**
             *  ������� �������� ����������� ���������� ������ ��� �������� �������
             *  � ������ �������� -1 - ������ ��������� ������!
             *  0 - ��� ����.
             */
            int CreateArrays();
        };

    }
}
