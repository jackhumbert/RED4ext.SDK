#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/IMoveSystem.hpp>

namespace RED4ext
{
namespace vehicle
{
struct MoveSystem : vehicle::IMoveSystem
{
    static constexpr const char* NAME = "vehicleMoveSystem";
    static constexpr const char* ALIAS = "MoveSystem";

// overrides

    virtual void OnRegisterUpdates(UpdateRegistrar* holder) override; 
    virtual void OnWorldAttached(world::RuntimeScene * runtimeScene) override;
    virtual void OnWorldDetached(world::RuntimeScene * runtimeScene) override;

// new virtuals

  virtual void sub_1A8();
  virtual void sub_1B0();
  virtual void sub_1B8();
  virtual void sub_1C0();
  virtual void sub_1C8();
  virtual void sub_1D0();
  virtual void sub_1D8();
  virtual void sub_1E0();
  virtual void sub_1E8();
  virtual void sub_1F0();
  // called via Update
  virtual void sub_1F8();
  virtual void sub_200();
  virtual void sub_208();
  virtual void sub_210();
  virtual void sub_218();
  virtual void sub_220();
  virtual void sub_228();
  virtual void sub_230();
  virtual void sub_238();
  virtual void sub_240();
  virtual void sub_248();
  virtual void sub_250();
  virtual void sub_258();
  virtual void sub_260();
  virtual void sub_268();
  virtual void sub_270();
  virtual void sub_278();
  virtual void sub_280();
  virtual void sub_288();
  virtual void sub_290();
  virtual void sub_298();
  virtual void sub_2A0();
  virtual void sub_2A8();
  virtual void sub_2B0();
  virtual void sub_2B8();

// variables

  RED4ext::DynArray<void*> unk48;
  RED4ext::DynArray<void*> unk58;
  RED4ext::DynArray<void*> unk68;
  uint64_t unk78[2];
  RED4ext::SharedSpinLock unk88;
};
RED4EXT_ASSERT_SIZE(MoveSystem, 0x90);
} // namespace vehicle
using vehicleMoveSystem = vehicle::MoveSystem;
using MoveSystem = vehicle::MoveSystem;
} // namespace RED4ext

// clang-format on
