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
        bool hasWorked = false;
        printf("Loaded minecraft\n");
        while (true) {
            std::unique_ptr<CWorld> world = std::make_unique<CWorld>(minecraft->GetLocalWorld());
            if (world->GetInstance() != NULL) {
                std::unique_ptr<CPlayerSP> playerSP = std::make_unique<CPlayerSP>(minecraft->GetLocalPlayerSP());
                //inline auto inventory = std::make_unique<CInventory>(playerSP->GetLocalInventory());
                //std::unique_ptr<CInventory> inventory = std::make_unique<CInventory>(playerSP->GetLocalInventory()); Crashes 
                //playerSP->chatLog(std::to_string(playerSP->GetHurtResistantTime()));
                if (playerSP->GetHurtResistantTime() > 0 && hasWorked == false) { // prototype antikb
                    double motionX = playerSP->GetMotionX(), motionY = playerSP->GetMotionY(), motionZ = playerSP->GetMotionZ();
                    
                    motionX *= 0.4;
                    motionY *= 0.4;
                    motionZ *= 0.4;

                    playerSP->setMotion(motionX, motionY, motionZ);
                    hasWorked = true;
                    //printf("Reduced kb\n");
                    //playerSP->chatLog("Reduced kb");
                }
                if (playerSP->GetHurtResistantTime() == 1 || playerSP->GetHurtResistantTime() == 0) {
                    hasWorked = false;
                    //printf("Waiting for hit\n");
                }
                if (GetAsyncKeyState('V')) {
                    std::cout << playerSP->GetLocalInventory().GetTotalPots() << std::endl;
                }
            }
            else {
                printf("Outside a world\n");
            }
            if (GetAsyncKeyState(VK_END)) break;
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

