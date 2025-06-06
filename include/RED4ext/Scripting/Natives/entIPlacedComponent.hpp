#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <cstdint>

namespace RED4ext
{
namespace ent
{
struct ITransformBinding;
}

namespace ent
{
struct __declspec(align(0x10)) IPlacedComponent : ent::IComponent
{
    static constexpr const char* NAME = "entIPlacedComponent";
    static constexpr const char* ALIAS = "IPlacedComponent";

    /// @hash 2545682969:idata
    static constexpr const uintptr_t VFT = entIPlacedComponent_VFT_Addr;

    // creates ent::HardAttachment with this as source, 0x238
    virtual Handle<ent::ITransformAttachment>* CreateTransformAttachment(Handle<ent::ITransformAttachment>* aAttachment, 
                                                                         CName name,
                                                                         Handle<void>* aDestination);
    // unkB2 = 1
    virtual void OnAttach(void*) override;
    // unkB2 = 1
    // unkA0 clear
    virtual bool OnDetach(void*) override;
    // debug related? formats name to [%hs]
    virtual void sub_238(); // RenderDebugName(rend::IDebugDrawer &)
    // get bounding box maybe?
    virtual void sub_240(Box* boundingBox) = 0;
    virtual void GetFlags(); // GetDebugRenderColor

    struct UnkA0 {
        uint64_t unk00[4];
    };

    Handle<ITransformBinding> parentTransform; // 90
    // reated to Transform Attachements - double Handle struct
    DynArray<UnkA0> unkA0;
    uint8_t unkB0;
    // set based on arg passed to UpdateBindings
    uint8_t unkB1;
    // related to unkA0 updates?
    // hasUpdate?
    uint8_t unkB2;
    uint8_t unkB3[5];
    uint64_t unkB8;
    WorldTransform localTransform; // C0
    WorldTransform worldTransform; // E0
    Box bounds; // 100
};
RED4EXT_ASSERT_SIZE(IPlacedComponent, 0x120);
} // namespace ent
using entIPlacedComponent = ent::IPlacedComponent;
using IPlacedComponent = ent::IPlacedComponent;
} // namespace RED4ext
