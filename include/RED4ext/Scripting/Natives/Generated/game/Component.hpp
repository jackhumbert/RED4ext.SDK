#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/gamePSInterface.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PersistentState.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/Object.hpp>
#include <RED4ext/RTTITypes.hpp>

namespace RED4ext
{
struct IGameInstance;
namespace game { 
struct Component : ent::IComponent, PSInterface
{
    static constexpr const char* NAME = "gameComponent";
    static constexpr const char* ALIAS = "GameComponent";
    static constexpr const uint32_t VFT = 331746781;

// overridden virtuals

    inline virtual Memory::IAllocator* GetAllocator() override {
        static UniRelocFunc<decltype(&Component::GetAllocator)> call(VFT, 0x10);
        return call(this);
    }

    inline virtual Handle<game::PersistentState>* sub_150(Handle<game::PersistentState>* a1) override {
        static UniRelocFunc<decltype(&Component::sub_150)> call(VFT, 0x150);
        return call(this, a1);
    }

    inline virtual void OnAttach(void* a1) override {
        static UniRelocFunc<decltype(&Component::OnAttach)> call(VFT, 0x180);
        return call(this, a1);
    }

    inline virtual bool OnDetach(void* a1) override {
        static UniRelocFunc<decltype(&Component::OnDetach)> call(VFT, 0x190);
        return call(this, a1);
    }

    // checks to make sure entity is gameObject
    inline virtual void sub_218(void* a1) override {
        static UniRelocFunc<decltype(&Component::sub_218)> call(VFT, 0x218);
        return call(this, a1);
    }

    // new virtuals

    // sets the persisent state
    inline virtual void sub_230(Handle<game::PersistentState>* a1) {
        static UniRelocFunc<decltype(&Component::sub_230)> call(VFT, 0x230);
        return call(this, a1);
    }

    // is Scripted Class / has scripted callbacks?
    inline virtual bool sub_238(Handle<Object>*) {
        return this->GetType()->flags.isScriptedClass;
    }

    inline virtual void OnGameAttach(IGameInstance* a1) { } // 240
    inline virtual void OnGameDetach(IGameInstance* a1) { } // 248
    inline virtual void OnEditorAttach() { }                // 250
    inline virtual void OnEditorDetach() { }                // 258

    // uint8_t unk90[0x98 - 0x90]; // 90
    // Handle<game::PersistentState> persistentState; // 98
};
RED4EXT_ASSERT_SIZE(Component, 0xA8);
} // namespace game
using gameComponent = game::Component;
using GameComponent = game::Component;
} // namespace RED4ext

// clang-format on
