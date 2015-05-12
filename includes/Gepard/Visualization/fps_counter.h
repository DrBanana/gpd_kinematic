///////////////////////////////////////////////////////////
//  fps_counter.h
//  —четчик FPS
//  Created on:      18-но€-2014 8:40
//  Original author: Anton
///////////////////////////////////////////////////////////

#pragma once

#include <windows.h>

namespace Gepard 
{
    namespace Visualization 
    {
        /**
         *	—четчик FPS
         */
        struct fps_counter 
        {
            unsigned long _base_time;
            unsigned long _current_time;
            unsigned int fCounter;
            unsigned int curFPS;

            fps_counter()
            {
                _base_time = 0;
                _current_time = 0;
                fCounter = 0;
                curFPS = 0;
            }

            unsigned int getFPS()
            {
            #ifdef WIN64
                _current_time = GetTickCount64();
            #elif defined(WIN32)
                _current_time = GetTickCount();
            #endif
                unsigned long _timeInterval = _current_time - _base_time;
                if (_timeInterval > 1000)
                {
                    _base_time = _current_time;
                    curFPS = fCounter;// / _timeInterval / 1000;
                    fCounter = 0;            
                }
                fCounter++;
                return curFPS; 
            }
        };
    }
}
