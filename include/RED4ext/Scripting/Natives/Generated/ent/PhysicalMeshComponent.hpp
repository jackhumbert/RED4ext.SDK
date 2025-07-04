#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SimulationType.hpp>
#include <RED4ext/Scripting/Natives/entITransformAttachable.hpp>
#include <RED4ext/Scripting/Natives/physicsProxyCache.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace ent { 
struct __declspec(align(0x10)) PhysicalMeshComponent : ent::MeshComponent, ent::ITransformAttachable
{
    static constexpr const char* NAME = "entPhysicalMeshComponent";
    static constexpr const char* ALIAS = "PhysicalMeshComponent";

//    struct Sub_188 {
//        uint64_t unk00;
//        game::PersistencySystem * persistency;
//    };

    virtual void sub_140();

    // PhysicalMeshComponent_OnMeshLoaded
    virtual bool Initialize();

    // disable/cleanup something?
    virtual void Uninitialize();

    // sets proxyCacheID, runs sub_2A0
    virtual void OnAttach(void * a2);

    // proxyID & Stuff
    virtual void OnDetach(void *);

    // verify mesh collider stuff
    virtual void sub_218(void *);

    // calls sub_2B0 after sub_258
    virtual bool sub_270(bool a2, bool a3);

    // should enable collision
    virtual bool sub_298();
    virtual bool sub_2A0();

    // creates physicalResource & populates proxyID & proxyCacheID
    virtual bool sub_2A8();

    // 1.6  RVA: 0x10C7C30 / 17595440
    /// @pattern 40 55 41 56 48 8D AC 24 88 FD FF FF 48 81 EC 78 03 00 00 48 8B 12 4C 8B F1 48 85 D2 0F 84 7F 08
    void __fastcall ProcessSystemResource(Handle<CMesh> *cmeshHandle);

    uint64_t unk1E8;
    Transform bodyTransform;
    Handle<physics::FilterData> filterData; // 210
    // NativeArray<physics::InitialState, 16> * initialStats; // 220
    CName visibilityAnimationParam; // 220
    physics::ProxyID proxyID; // 228
    physics::ProxyCacheID proxyCacheID; // 22C
    physics::FilterDataSource filterDataSource; // 230
    physics::SimulationType simulationType; // 231
    bool startInactive; // 232
    bool useResourceSimulationType; // 233
    uint8_t unk234[0x240 - 0x234]; // 234
};
RED4EXT_ASSERT_SIZE(PhysicalMeshComponent, 0x240);
} // namespace ent
using entPhysicalMeshComponent = ent::PhysicalMeshComponent;
using PhysicalMeshComponent = ent::PhysicalMeshComponent;
} // namespace RED4ext

// clang-format on
