///////////////////////////////////////////////////////////
//  CB_GeometryRender.hpp
//  ���������� 	Class CB_GeometryRender
//  �������:   	15-���-2013 17:24:23
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

namespace Gepard 
{
    namespace Callbacks 
    {

     /**
      *  ��������� ������� �������� ������ - ����� ���������� ����������� ������
      */
     template <typename T>
     T* GeometryRenderManager::CreateCamera(bool isRegister/*=true*/)
     {
      T* curCameraPtr = new T();            
      assert(curCameraPtr);
  
      if (isRegister) {
        GeometryRenderManager::RegisterGCamera(dynamic_cast<Gepard::Visualization::GCamera*>(curCameraPtr));
      }

      return curCameraPtr;
     }

    }
}