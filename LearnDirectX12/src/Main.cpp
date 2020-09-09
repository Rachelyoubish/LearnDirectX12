#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Shlwapi.h>

#include "Application.h"
#include "Graphics.h"

 #include <dxgidebug.h>
 
 void ReportLiveObjects()
 {
     IDXGIDebug1* dxgiDebug;
     DXGIGetDebugInterface1( 0, IID_PPV_ARGS( &dxgiDebug ) );
 
     dxgiDebug->ReportLiveObjects( DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_IGNORE_INTERNAL );
     dxgiDebug->Release();
 }

int CALLBACK WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
    int retCode = 0;

    Application::Create( hInstance );
    {
        std::shared_ptr<Graphics> demo = std::make_shared<Graphics>( "Learning DirectX 12", 1280, 720 );
        retCode = Application::Get().Run( demo );
    }
    Application::Destroy();

   atexit( &ReportLiveObjects );

    return retCode;
}