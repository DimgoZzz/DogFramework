#include "DEngine/EngineClasses/IEngine.h"

namespace DogFW::engine
{    

#pragma region Class_bases
    IEngine* IEngine::engptr_ {nullptr};

    IEngine::IEngine()
    {
        hInst_ = GetModuleHandle(NULL);
        engptr_ = this;
    };

    IEngine::~IEngine()
    {
        engptr_ = nullptr;
    };

    IEngine * IEngine::get()
    {
        return engptr_;
    }
    void IEngine::init()
    {
        initSystems();
    }
#pragma endregion Class_bases

#pragma region Systems

    void IEngine::initSystems()
    {
        initSystemFile();
        initSystemLog();
        initSystemApp();
        initSystemWindow();
    }

    SystemFile* IEngine::getSystemFile() { return sysFile_.get(); }
    SystemLog* IEngine::getSystemLog() { return sysLog_.get(); }
    SystemApp* IEngine::getSystemApp() { return sysApp_.get(); }
    SystemWindow* IEngine::getSystemWindow() { return sysWindow_.get(); };
#pragma endregion Systems

#pragma region Public Api

    HINSTANCE IEngine::getHInst()
    {
        return hInst_;
    };

#pragma endregion Public Api

}

