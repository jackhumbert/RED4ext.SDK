#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/physicsProxyManager.hpp>
#endif

#include "Addresses.hpp"
#include <RED4ext/Relocation.hpp>

RED4ext::physics::ProxyManager * RED4ext::physics::proxyManager = *reinterpret_cast<RED4ext::physics::ProxyManager **>(reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)) + physics_proxyManager_Addr);

RED4ext::physics::ProxyManager * RED4ext::physics::ProxyManager::Get() {
  return proxyManager;
}