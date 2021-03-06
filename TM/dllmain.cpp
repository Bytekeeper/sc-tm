#include "BWAPI.h"
#include "TM.hpp"

TournamentModuleManager tm;

#ifdef BWAPI3
namespace BWAPI { Game* Broodwar; }
#endif

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
#ifdef BWAPI3
  if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    BWAPI::BWAPI_init();
#endif
  return TRUE;
}

#ifdef BWAPI4
extern "C" __declspec(dllexport) void gameInit(BWAPI::Game *game) {
  BWAPI::BroodwarPtr = game;
}
#endif
extern "C" __declspec(dllexport) BWAPI::AIModule *newTournamentAI(BWAPI::Game *game) {
#ifdef BWAPI3
  BWAPI::Broodwar = game;
#endif
  return tm.bot = new TournamentModuleManager::TournamentBot;
}
extern "C" __declspec(dllexport) BWAPI::TournamentModule *newTournamentModule(BWAPI::Game *game) {
  return tm.mod = new TournamentModuleManager::TournamentModule;
}
