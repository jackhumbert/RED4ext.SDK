#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace game { 
struct BaseGameSession
{
    static constexpr const char* NAME = "gameBaseGameSession";
    static constexpr const char* ALIAS = NAME;
    static constexpr const uintptr_t VFT_RVA = 0x3306710;

    virtual ~BaseGameSession();
    // registers SetupRuntimeScene, LoadGame, OnGamePrepared callbacks
    virtual void Initialize(void*, char*, void*, void*, void*, void*, void*);
    // calls gameSystems->sub_120, runtimeSystems->sub_188, gameSystems->sub_128, 
    // runtimeSystems->sub_190, gameSystems->sub_130, gameEngine->sub_80
    virtual void * sub_10();
    // registers Update/Systems callbacks
    virtual bool sub_18(void*, float, void*);
    // empty
    virtual void sub_20();
    // gameInstance->RegisterUpdates
    virtual void sub_28();
    // sets runtimeScene info, calls systems->RegisterUpdates
    virtual void sub_30();
    // something with game rules system & community system
    virtual void sub_38(void * a2);
    // register InitializeWorldStreaming, InitializeGame callbacks
    virtual void sub_40(void * a2, void* a3);

    uint8_t unk00[0x30 - 0x0]; // 0
};
RED4EXT_ASSERT_SIZE(BaseGameSession, 0x30);
} // namespace game
} // namespace RED4ext
