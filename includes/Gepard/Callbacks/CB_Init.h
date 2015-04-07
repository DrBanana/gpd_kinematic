///////////////////////////////////////////////////////////
//  CB_Init.h
//  ���������� 	CB_Init.h
//  �������:   	17-���-2013 14:46:51
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "CB_Progress.h"
#include "CB_OutputMessages.h"

namespace Gepard 
{
    namespace Callbacks
    {
        class CB_Init
        {        
        private:
            CB_Init()
            {
                CB_OutputMessageEventClassPtr = nullptr;
                CB_ProgressEventPtr = nullptr;
            };

            ~CB_Init(){};
            CB_Init(const CB_Init& grm);
            CB_Init& operator=(const CB_Init& grm);

            static CB_Init cbBasicInstance;
        };
    }
}
