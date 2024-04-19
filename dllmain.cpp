#include <Windows.h>

#include <chrono>
#include <thread>

#include "SDK/Minecraft.h"
#include <vector>

FILE* file = nullptr;
bool safeMode = false;
bool cd = false;
std::vector<std::vector<double>> positions;

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

void buildBlock10(double posX, double posY, double posZ, std::string facing, CWorld world, CBlocks Blocks) {
    std::vector<std::vector<double>> DefNorth10 = { {posX, posY, posZ + 2}, {posX + 1, posY, posZ + 2}, {posX - 1, posY, posZ + 2}, {posX + 2, posY, posZ + 2}, {posX - 2, posY, posZ + 2},
                {posX + 3, posY, posZ + 1}, {posX - 3, posY, posZ + 1}, {posX + 4, posY, posZ + 1}, {posX - 4, posY, posZ + 1},
                {posX + 5, posY, posZ}, {posX - 5, posY, posZ},
                {posX + 5, posY, posZ - 1}, {posX - 5, posY, posZ - 1},
                {posX + 6, posY, posZ - 2}, {posX - 6, posY, posZ - 2},
                {posX + 6, posY, posZ - 3}, {posX - 6, posY, posZ - 3},
                {posX + 6, posY, posZ - 4}, {posX - 6, posY, posZ - 4},
                {posX + 6, posY, posZ - 5}, {posX - 6, posY, posZ - 5},
                {posX + 6, posY, posZ - 6}, {posX - 6, posY, posZ - 6},
                {posX + 5, posY, posZ - 7}, {posX - 5, posY, posZ - 7},
                {posX + 5, posY, posZ - 8}, {posX - 5, posY, posZ - 8},
                {posX + 4, posY, posZ - 9}, {posX - 4, posY, posZ - 9},
                {posX + 3, posY, posZ - 9}, {posX - 3, posY, posZ - 9},
                {posX + 2, posY, posZ - 10}, {posX - 2, posY, posZ - 10}, {posX + 1, posY, posZ - 10}, {posX - 1, posY, posZ - 10}, {posX, posY, posZ - 10} };
    std::vector<std::vector<double>> DefSouth10 = { {posX, posY, posZ - 2}, {posX + 1, posY, posZ - 2}, {posX - 1, posY, posZ - 2}, {posX + 2, posY, posZ - 2}, {posX - 2, posY, posZ - 2},
            {posX + 3, posY, posZ - 1}, {posX - 3, posY, posZ - 1}, {posX + 4, posY, posZ - 1}, {posX - 4, posY, posZ - 1},
            {posX + 5, posY, posZ}, {posX - 5, posY, posZ},
            {posX + 5, posY, posZ + 1}, {posX - 5, posY, posZ + 1},
            {posX + 6, posY, posZ + 2}, {posX - 6, posY, posZ + 2},
            {posX + 6, posY, posZ + 3}, {posX - 6, posY, posZ + 3},
            {posX + 6, posY, posZ + 4}, {posX - 6, posY, posZ + 4},
            {posX + 6, posY, posZ + 5}, {posX - 6, posY, posZ + 5},
            {posX + 6, posY, posZ + 6}, {posX - 6, posY, posZ + 6},
            {posX + 5, posY, posZ + 7}, {posX - 5, posY, posZ + 7},
            {posX + 5, posY, posZ + 8}, {posX - 5, posY, posZ + 8},
            {posX + 4, posY, posZ + 9}, {posX - 4, posY, posZ + 9},
            {posX + 3, posY, posZ + 9}, {posX - 3, posY, posZ + 9},
            {posX + 2, posY, posZ + 10}, {posX - 2, posY, posZ + 10}, {posX + 1, posY, posZ + 10}, {posX - 1, posY, posZ + 10}, {posX, posY, posZ + 10} };
    std::vector<std::vector<double>> DefEast10 = { {posX - 2, posY, posZ}, {posX - 2, posY, posZ + 1}, {posX - 2, posY, posZ - 1},{posX - 2, posY, posZ + 2}, {posX - 2, posY, posZ - 2},
            {posX - 1, posY, posZ + 3}, {posX - 1, posY, posZ - 3}, {posX - 1, posY, posZ + 4}, {posX - 1, posY, posZ - 4},
            {posX, posY, posZ + 5}, {posX, posY, posZ - 5},
            {posX + 1, posY, posZ + 5}, {posX + 1, posY, posZ - 5},
            {posX + 2, posY, posZ + 6}, {posX + 2, posY, posZ - 6},
            {posX + 3, posY, posZ + 6}, {posX + 3, posY, posZ - 6},
            {posX + 4, posY, posZ + 6}, {posX + 4, posY, posZ - 6},
            {posX + 5, posY, posZ + 6}, {posX + 5, posY, posZ - 6},
            {posX + 6, posY, posZ + 6}, {posX + 6, posY, posZ - 6},
            {posX + 7, posY, posZ + 5}, {posX + 7, posY, posZ - 5},
            {posX + 8, posY, posZ + 5}, {posX + 8, posY, posZ - 5},
            {posX + 9, posY, posZ + 4}, {posX + 9, posY, posZ - 4},
            {posX + 9, posY, posZ + 3}, {posX + 9, posY, posZ - 3},
            {posX + 10, posY, posZ + 2}, {posX + 10, posY, posZ - 2}, {posX + 10, posY, posZ + 1}, {posX + 10, posY, posZ - 1}, {posX + 10, posY, posZ} };
    std::vector<std::vector<double>> DefWest10 = { {posX + 2, posY, posZ}, {posX + 2, posY, posZ + 1}, {posX + 2, posY, posZ - 1},{posX + 2, posY, posZ + 2}, {posX + 2, posY, posZ - 2},
            {posX + 1, posY, posZ + 3}, {posX + 1, posY, posZ - 3}, {posX + 1, posY, posZ + 4}, {posX + 1, posY, posZ - 4},
            {posX, posY, posZ + 5}, {posX, posY, posZ - 5},
            {posX - 1, posY, posZ + 5}, {posX - 1, posY, posZ - 5},
            {posX - 2, posY, posZ + 6}, {posX - 2, posY, posZ - 6},
            {posX - 3, posY, posZ + 6}, {posX - 3, posY, posZ - 6},
            {posX - 4, posY, posZ + 6}, {posX - 4, posY, posZ - 6},
            {posX - 5, posY, posZ + 6}, {posX - 5, posY, posZ - 6},
            {posX - 6, posY, posZ + 6}, {posX - 6, posY, posZ - 6},
            {posX - 7, posY, posZ + 5}, {posX - 7, posY, posZ - 5},
            {posX - 8, posY, posZ + 5}, {posX - 8, posY, posZ - 5},
            {posX - 9, posY, posZ + 4}, {posX - 9, posY, posZ - 4},
            {posX - 9, posY, posZ + 3}, {posX - 9, posY, posZ - 3},
            {posX - 10, posY, posZ + 2}, {posX - 10, posY, posZ - 2}, {posX - 10, posY, posZ + 1}, {posX - 10, posY, posZ - 1}, {posX - 10, posY, posZ} };

    if (facing == "SOUTH") {
        positions = DefSouth10;
    }
    else if (facing == "NORTH") {
        positions = DefNorth10;
    }
    else if (facing == "EAST") {
        positions = DefEast10;
    }
    else if (facing == "WEST") {
        positions = DefWest10;
    }

    for (std::vector<double> i : positions) {
        world.setBlockState(i[0], i[1], i[2], Blocks.glass);
    }
}

void buildBlock12(double posX, double posY, double posZ, std::string facing, CWorld world, CBlocks Blocks) {
    std::vector<std::vector<double>> DefWest12 = { {posX + 2, posY, posZ}, {posX + 2, posY, posZ + 1}, {posX + 2, posY, posZ - 1}, {posX + 2, posY, posZ + 2}, {posX + 2, posY, posZ - 2},
                {posX + 1, posY, posZ + 3}, {posX + 1, posY, posZ - 3},
                {posX + 1, posY, posZ + 4}, {posX + 1, posY, posZ - 4},
                {posX, posY, posZ + 5}, {posX, posY, posZ - 5},
                {posX - 1, posY, posZ + 6}, {posX - 1, posY, posZ - 6},
                {posX - 2, posY, posZ + 6}, {posX - 2, posY, posZ - 6},
                {posX - 3, posY, posZ + 7}, {posX - 3, posY, posZ - 7},
                {posX - 4, posY, posZ + 7}, {posX - 4, posY, posZ - 7},
                {posX - 5, posY, posZ + 7}, {posX - 5, posY, posZ - 7},
                {posX - 6, posY, posZ + 7}, {posX - 6, posY, posZ - 7},
                {posX - 7, posY, posZ + 7}, {posX - 7, posY, posZ - 7},
                {posX - 8, posY, posZ + 6}, {posX - 8, posY, posZ - 6},
                {posX - 9, posY, posZ + 6}, {posX - 9, posY, posZ - 6},
                {posX - 10, posY, posZ + 5}, {posX - 10, posY, posZ - 5},
                {posX - 11, posY, posZ + 4}, {posX - 11, posY, posZ - 4},
                {posX - 11, posY, posZ + 3}, {posX - 11, posY, posZ - 3},
                {posX - 12, posY, posZ + 2}, {posX - 12, posY, posZ - 2}, {posX - 12, posY, posZ + 1}, {posX - 12, posY, posZ - 1},{posX - 12, posY, posZ} };
    std::vector<std::vector<double>> DefEast12 = { {posX - 2, posY, posZ}, {posX - 2, posY, posZ + 1}, {posX - 2, posY, posZ - 1}, {posX - 2, posY, posZ + 2}, {posX - 2, posY, posZ - 2},
                {posX - 1, posY, posZ + 3}, {posX - 1, posY, posZ - 3},
                {posX - 1, posY, posZ + 4}, {posX - 1, posY, posZ - 4},
                {posX, posY, posZ + 5}, {posX, posY, posZ - 5},
                {posX + 1, posY, posZ + 6}, {posX + 1, posY, posZ - 6},
                {posX + 2, posY, posZ + 6}, {posX + 2, posY, posZ - 6},
                {posX + 3, posY, posZ + 7}, {posX + 3, posY, posZ - 7},
                {posX + 4, posY, posZ + 7}, {posX + 4, posY, posZ - 7},
                {posX + 5, posY, posZ + 7}, {posX + 5, posY, posZ - 7},
                {posX + 6, posY, posZ + 7}, {posX + 6, posY, posZ - 7},
                {posX + 7, posY, posZ + 7}, {posX + 7, posY, posZ - 7},
                {posX + 8, posY, posZ + 6}, {posX + 8, posY, posZ - 6},
                {posX + 9, posY, posZ + 6}, {posX + 9, posY, posZ - 6},
                {posX + 10, posY, posZ + 5}, {posX + 10, posY, posZ - 5},
                {posX + 11, posY, posZ + 4}, {posX + 11, posY, posZ - 4},
                {posX + 11, posY, posZ + 3}, {posX + 11, posY, posZ - 3},
                {posX + 12, posY, posZ + 2}, {posX + 12, posY, posZ - 2}, {posX + 12, posY, posZ + 1}, {posX + 12, posY, posZ - 1},{posX + 12, posY, posZ} };
    std::vector<std::vector<double>> DefNorth12 = { {posX, posY, posZ + 2}, {posX + 1, posY, posZ + 2}, {posX - 1, posY, posZ + 2}, {posX - 2, posY, posZ + 2}, {posX + 2, posY, posZ + 2},
                {posX + 3, posY, posZ + 1}, {posX - 3, posY, posZ + 1},{posX + 4, posY, posZ + 1}, {posX - 4, posY, posZ + 1},
                {posX + 5, posY, posZ}, {posX - 5, posY, posZ},
                {posX + 6, posY, posZ - 1}, {posX - 6, posY, posZ - 1},
                {posX + 6, posY, posZ - 2}, {posX - 6, posY, posZ - 2},
                {posX + 7, posY, posZ - 3}, {posX - 7, posY, posZ - 3},
                {posX + 7, posY, posZ - 4}, {posX - 7, posY, posZ - 4},
                {posX + 7, posY, posZ - 5}, {posX - 7, posY, posZ - 5},
                {posX + 7, posY, posZ - 6}, {posX - 7, posY, posZ - 6},
                {posX + 7, posY, posZ - 7}, {posX - 7, posY, posZ - 7},
                {posX + 6, posY, posZ - 8}, {posX - 6, posY, posZ - 8},
                {posX + 6, posY, posZ - 9}, {posX - 6, posY, posZ - 9},
                {posX + 5, posY, posZ - 10}, {posX - 5, posY, posZ - 10},
                {posX + 4, posY, posZ - 11}, {posX - 4, posY, posZ - 11},
                {posX + 3, posY, posZ - 11}, {posX - 3, posY, posZ - 11},
                {posX + 2, posY, posZ - 12}, {posX - 2, posY, posZ - 12},{posX + 1, posY, posZ - 12}, {posX - 1, posY, posZ - 12},{posX, posY, posZ - 12} };
    std::vector<std::vector<double>> DefSouth12 = { {posX, posY, posZ - 2}, {posX + 1, posY, posZ - 2}, {posX - 1, posY, posZ - 2}, {posX - 2, posY, posZ - 2}, {posX + 2, posY, posZ - 2},
                {posX + 3, posY, posZ - 1}, {posX - 3, posY, posZ - 1},{posX + 4, posY, posZ - 1}, {posX - 4, posY, posZ - 1},
                {posX + 5, posY, posZ}, {posX - 5, posY, posZ},
                {posX + 6, posY, posZ + 1}, {posX - 6, posY, posZ + 1},
                {posX + 6, posY, posZ + 2}, {posX - 6, posY, posZ + 2},
                {posX + 7, posY, posZ + 3}, {posX - 7, posY, posZ + 3},
                {posX + 7, posY, posZ + 4}, {posX - 7, posY, posZ + 4},
                {posX + 7, posY, posZ + 5}, {posX - 7, posY, posZ + 5},
                {posX + 7, posY, posZ + 6}, {posX - 7, posY, posZ + 6},
                {posX + 7, posY, posZ + 7}, {posX - 7, posY, posZ + 7},
                {posX + 6, posY, posZ + 8}, {posX - 6, posY, posZ + 8},
                {posX + 6, posY, posZ + 9}, {posX - 6, posY, posZ + 9},
                {posX + 5, posY, posZ + 10}, {posX - 5, posY, posZ + 10},
                {posX + 4, posY, posZ + 11}, {posX - 4, posY, posZ + 11},
                {posX + 3, posY, posZ - 11}, {posX - 3, posY, posZ - 11},
                {posX + 2, posY, posZ + 12}, {posX - 2, posY, posZ + 12},{posX + 1, posY, posZ + 12}, {posX - 1, posY, posZ + 12},{posX, posY, posZ + 12} };

    if (facing == "SOUTH") {
        positions = DefSouth12;
    }
    else if (facing == "NORTH") {
        positions = DefNorth12;
    }
    else if (facing == "EAST") {
        positions = DefEast12;
    }
    else if (facing == "WEST") {
        positions = DefWest12;
    }

    for (std::vector<double> i : positions) {
        world.setBlockState(i[0], i[1], i[2], Blocks.glass);
    }
}

void fences() {
    CMinecraft minecraft;
    CPlayer player = minecraft.GetLocalPlayer();
    CWorld world = minecraft.GetLocalWorld();
    CBlocks Blocks;
    CItems Items;
    if (GetAsyncKeyState('G') && cd == false) { // 10 blocks
        std::cout << "Started placing fences" << std::endl;

        double posX = player.GetX();
        double posY = player.GetY();
        double posZ = player.GetZ();

        std::string facing = player.GetFacing();
        
        for (int i = 0; i < 4; i++) {
            if (i != 1) {
                buildBlock10(posX, posY + i, posZ, facing, world, Blocks);
            }
        } 

        std::cout << "Finished placing fences" << std::endl;

        cd = true;
    } 
    if (GetAsyncKeyState('H') && cd == false) { // 12 blocks
        std::cout << "Started placing fences" << std::endl;

        double posX = player.GetX();
        double posY = player.GetY();
        double posZ = player.GetZ();

        std::string facing = player.GetFacing();

        for (int i = 0; i < 4; i++) {
            if (i != 1) {
                buildBlock12(posX, posY + i, posZ, facing, world, Blocks);
            }
        }

        std::cout << "Finished placing fences" << std::endl;

        cd = true;
    }
    if (GetAsyncKeyState('R') && cd == true) {
        cd = false;
        std::cout << "Fences Reset !" << std::endl;
    }
    if (GetAsyncKeyState(VK_RBUTTON) && lc->env->IsSameObject(player.GetHeldItem(), Items.paper)) {
        cd = false;
        std::cout << "Fences Reset !" << std::endl;
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
        //std::unique_ptr<CEnumFacing> EnumFacing = std::make_unique<CEnumFacing>();
        std::unique_ptr<CEnumChatFormatting> EnumChatFormatting = std::make_unique<CEnumChatFormatting>();
        bool hasWorked = false;
        printf("Loaded minecraft\n");
        while (true) {
            std::unique_ptr<CWorld> world = std::make_unique<CWorld>(minecraft->GetLocalWorld());
            CWorld worldSimple = minecraft->GetLocalWorld();
            if (world->GetInstance() != NULL) {
                std::unique_ptr<CPlayer> player = std::make_unique<CPlayer>(minecraft->GetLocalPlayer());
                std::unique_ptr<CPlayerController> playerController = std::make_unique<CPlayerController>(minecraft->GetLocalPlayerController());
                CPlayer playerSimple = minecraft->GetLocalPlayer(); // works
                //autoPot();
                fences();
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

