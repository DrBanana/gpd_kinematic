///////////////////////////////////////////////////////////
//  CB_GeometryRender.hpp
//  Реализация 	Class CB_GeometryRender
//  Создана:   	15-окт-2013 17:24:23
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

namespace Gepard 
{
    namespace Callbacks 
    {

     /**
      *  Шаблонная функция создания камеры - сразу происходит регистрация камеры
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