#include <Windows.h>

#include <chrono>
#include <thread>

#include "SDK/Minecraft.h"


FILE* file = nullptr;

void autoPot() {
    CMinecraft minecraft;
    CPlayer player = minecraft.GetLocalPlayer();
    CWorld world = minecraft.GetLocalWorld();
    CPlayerController playerController = minecraft.GetLocalPlayerController();
    if (player.GetHealth() <= 5) {
        player.setPitch(90); // Look down
        playerController.sendUseItem(player, world, player.GetHeldItemStack());
    }
}

void init(void* instance) {
    jsize count;
    using std::cout;
    using std::endl;

    if (JNI_GetCreatedJavaVMs(&lc->vm, 1, &count) != JNI_OK || count == 0) return;
    jint res = lc->vm->GetEnv((void**)&lc->env, JNI_VERSION_1_8);

    if (res == JNI_EDETACHED) res = lc->vm->AttachCurrentThread((void**)&lc->env, nullptr);

    if (lc->env != nullptr){
        jobject nullObj = nullptr;
        lc->GetLoadedClasses();
        std::unique_ptr<CMinecraft> minecraft = std::make_unique<CMinecraft>();
        std::unique_ptr<CItems> Items = std::make_unique<CItems>();
        std::unique_ptr<CBlocks> Blocks = std::make_unique<CBlocks>();
        bool hasWorked = false;
        printf("Loaded minecraft\n");
        while (true) {
            std::unique_ptr<CWorld> world = std::make_unique<CWorld>(minecraft->GetLocalWorld());
            CWorld worldSimple = minecraft->GetLocalWorld();
            if (world->GetInstance() != NULL) {
                std::unique_ptr<CPlayer> player = std::make_unique<CPlayer>(minecraft->GetLocalPlayer());
                std::unique_ptr<CPlayerController> playerController = std::make_unique<CPlayerController>(minecraft->GetLocalPlayerController());
                CPlayer playerSimple = minecraft->GetLocalPlayer(); // works
                autoPot();
                if (GetAsyncKeyState('V')) {
                    //cout << Blocks->stone << endl;
                    //playerController->sendUseItem(playerSimple, worldSimple, player->GetHeldItemStack());
                    //world->setBlockState(10, 10, 10, nullObj);
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

