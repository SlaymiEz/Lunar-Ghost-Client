#include <Windows.h>

#include <chrono>
#include <thread>

#include "SDK/Minecraft.h"


FILE* file = nullptr;

void init(void* instance) {
    jsize count;

    if (JNI_GetCreatedJavaVMs(&lc->vm, 1, &count) != JNI_OK || count == 0) return;
    jint res = lc->vm->GetEnv((void**)&lc->env, JNI_VERSION_1_8);

    if (res == JNI_EDETACHED) res = lc->vm->AttachCurrentThread((void**)&lc->env, nullptr);

    if (lc->env != nullptr){
        lc->GetLoadedClasses();
        std::unique_ptr<CMinecraft> minecraft = std::make_unique<CMinecraft>();
        std::unique_ptr<CPlayerSP> playerSP = std::make_unique<CPlayerSP>(minecraft->GetLocalPlayerSP());
        //std::unique_ptr<CPlayer> player = std::make_unique<CPlayer>(minecraft->GetLocalPlayer());
       
        //std::unique_ptr<CPlayer> player = std::make_unique<CPlayer>(minecraft->GetLocalPlayer());
        while (true) {
            if (GetAsyncKeyState(VK_END)) break;

            //Minecraft->GetLocalPlayerSP().sendChatMessage((const char*)"message"); // doesn't work
            
            //std::cout << Minecraft->GetLocalPlayerSP().getExperience() << std::endl; // doesn't work

            //std::cout << std::to_string(playerSP->GetX()) + " " + 
             //   std::to_string(playerSP->GetY()) + " " + 
               // std::to_string(playerSP->GetZ()) << std::endl;
            if (GetAsyncKeyState('V')) {
                //playerSP->clear(); // working
                std::cout << std::to_string(minecraft->GetLocalPlayerSP().GetExperienceLvL()) << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(5));  
        }
    }
    fclose(file);
    FreeConsole();

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        freopen_s(&file, "CONOUT$", "w", stdout);

        CloseHandle(CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(init), hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

