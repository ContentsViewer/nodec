#include "Window.hpp"
#include "Utils.hpp"

#include <nodec/nodec_exception.hpp>

#include <nodec_modules/game_engine/game_engine_module.hpp>

#include <Windows.h>
#include <exception>


void on_boot();



int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    try
    {
        nodec_modules::game_engine::GameEngineModule game_engine_module;
        
        Window window(1280, 720, L"TEST", &game_engine_module);

        //game_engine_module.keyboard().test = 10;
        //MessageBox(nullptr, std::to_wstring(game_engine_module.keyboard().test).c_str(), L"", MB_OK | MB_ICONEXCLAMATION);
        //game_engine_module.keyboard_module().test = 100;
        //MessageBox(nullptr, std::to_wstring(game_engine_module.keyboard().test).c_str(), L"", MB_OK | MB_ICONEXCLAMATION);
        
        window.SetTitle("ほげってる");

        while (true)
        {
            int exit_code;
            // process all messages pending, but to not block for new messages
            if (!Window::ProcessMessages(exit_code))
            {
                return exit_code;
            }

        }

    }
    catch (const nodec::NodecException& e)
    {
        try
        {
            auto wideWhat = TryMultiByteToWideChar(e.what());
            auto wideType = TryMultiByteToWideChar(e.type());

            MessageBox(nullptr, wideWhat.c_str(), wideType.c_str(), MB_OK | MB_ICONEXCLAMATION);
        }
        catch (const WideCharacterConvertException& e)
        {
            MessageBox(nullptr, e.what(), e.type(), MB_OK | MB_ICONEXCLAMATION);
        }

    }
    catch (const std::exception& e)
    {
        try
        {
            auto wideWhat = TryMultiByteToWideChar(e.what());

            MessageBox(nullptr, wideWhat.c_str(), L"StandardException", MB_OK | MB_ICONEXCLAMATION);
        }
        catch (const WideCharacterConvertException& e)
        {
            MessageBox(nullptr, e.what(), e.type(), MB_OK | MB_ICONEXCLAMATION);
        }
    }
    catch (...)
    {
        MessageBox(nullptr, L"Unknow Error Occurs. No details available.", L"UnkownErrorException", MB_OK | MB_ICONEXCLAMATION);
    }
    
    return -1;
}
