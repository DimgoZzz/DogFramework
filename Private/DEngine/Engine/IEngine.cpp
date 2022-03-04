#include "DEngine/Engine/IEngine.h"

namespace DogFW::engine
{    
////////////////////////////////////////
#pragma region Class_bases
////////////////////////////////////////
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
        initSettings();
        initSystems();
    }
////////////////////////////////////////
#pragma endregion Class_bases
////////////////////////////////////////

////////////////////////////////////////
#pragma region Settings
////////////////////////////////////////

    ProjectSettings* IEngine::getProjectSettings()
    {
        return projSettings_.get();
    }
    void IEngine::initSettings()
    {
        projSettings_ = new ProjectSettings;
    }

////////////////////////////////////////
#pragma endregion Settings
////////////////////////////////////////


////////////////////////////////////////
#pragma region Systems
////////////////////////////////////////

    void IEngine::initSystems()
    {
        initSystemFile();
        initSystemLog();
        initSystemApp();
        initSystemWindow();
    }

    FileSystem * IEngine::getSystemFile() { return fileSys_.get(); }
    LogSystem* IEngine::getSystemLog() { return logSys_.get(); }
    AppSystem* IEngine::getSystemApp() { return appSys_.get(); }
    WindowSystem* IEngine::getSystemWindow() { return windowSys_.get(); };
////////////////////////////////////////
#pragma endregion Systems
////////////////////////////////////////

////////////////////////////////////////
#pragma region Public Api
////////////////////////////////////////

    HINSTANCE IEngine::getHInst()
    {
        return hInst_;
    };

////////////////////////////////////////
#pragma endregion Public Api
////////////////////////////////////////

}

