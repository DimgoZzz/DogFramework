#include "DogFW/Engine/EngineClasses/IEngine.h"

namespace DogFW:: inline engine
{    
    IEngine* IEngine::engptr {NULL};

    IEngine::IEngine()
    {
        hInst = GetModuleHandle(NULL);
    };

    IEngine::~IEngine()
    {

    };

    IEngine * IEngine::get()
    {
        return engptr;
    }

    HINSTANCE IEngine::getHInst()
    {
        return hInst;
    };
}

