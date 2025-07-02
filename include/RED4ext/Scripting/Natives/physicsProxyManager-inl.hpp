#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/Scripting/Natives/physicsProxyManager.hpp>
#endif

#include <RED4ext/Relocation.hpp>

using namespace RED4ext::physics;

// ProxyManager * proxyManager = *reinterpret_cast<ProxyManager **>(reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)) + physics_proxyManager_Addr);
// ProxyManager * RED4ext::physics::proxyManager = RED4ext::UniversalRelocPtr<ProxyManager *>(37956006);

// ProxyManager * RED4ext::physics::ProxyManager::Get() {
//   return proxyManager;
// }