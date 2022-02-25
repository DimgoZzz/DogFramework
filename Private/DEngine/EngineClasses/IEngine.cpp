#include "DEngine/EngineClasses/IEngine.h"

namespace DogFW:: inline engine
{    
    IEngine* IEngine::engptr_ {nullptr};

#pragma region Constructors
    IEngine::IEngine()
    {
        hInst_ = GetModuleHandle(NULL);
        engptr_ = this;
    };

    IEngine::~IEngine()
    {
        engptr_ = nullptr;
    };
#pragma endregion Constructors

#pragma region Public Api
    void IEngine::init()
    {
        initSystems();
    }
    IEngine * IEngine::get()
    {
        return engptr_;
    }

    HINSTANCE IEngine::getHInst()
    {
        return hInst_;
    };

    SystemFile* IEngine::getSystemFile() { return sysFile_; }
    SystemLog* IEngine::getSystemLog() { return sysLog_; }
    SystemApp* IEngine::getSystemApp() { return sysApp_; }
    SystemWindow* IEngine::getSystemWindow() { return sysWindow_; };

#pragma endregion Publi Api


#pragma region Protected Functions

    void IEngine::initSystems()
    {
        initSystemFile();
        initSystemLog();
        initSystemApp();
        initSystemWindow();
    }

#pragma endregion Protected Functions


}

