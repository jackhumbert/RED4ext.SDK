#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/HDRColor.hpp>
#include <RED4ext/Scripting/Natives/Generated/RectF.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/UITransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLayout.hpp>

namespace RED4ext::ink
{
struct IEffect;
struct LayerProxy;
struct PropertyManager;
struct StyleResourceWrapper;
struct UserData;
struct WidgetLogicController;

/*

inkFlex is an inkCanvas with all children in inkEAnchor.Fill mode
    children of flex container can only be positioned and sized relative to the parent bounds
inkCanvas is the most versatile container, it's children can be freely positioned and sized, 
    it can even act the same as inkFlex with proper settings

inkHorizontatl/vertical
    you can't use absolute positioning inside them
    they can be considered as docking containers
    to make individual slots draggable you have to move slot widget to a regular container of inkCanvas type first

    * size: size of element
    * fitToContent: resize element based on children margins & sizes
    * layout.anchor: corner/point on parent to reference from, along with dimensional fill instructions
    * layout.anchorPoint: internal point along width/height to reference from
    * layout.HAlign: fill instructions/reference that may conflict with anchor or anchorPoint?
    * layout.VAlign: ^
    * layout.sizeRule: a general dimensionless fill instruction?
    * layout.margin: pixel djustments done after things above
    * renderTransform.*: adjustments done after everything above
    * renderTransformPivot: reference for renderTransform adjustments 

    * fitToContent: depends on the widget type
        - inkHorizontalPanel and inkVerticalPanel: what you wrote, switches between content size (children) and own widget size property
        - inkImage: resize to the original texture size
        - inkText: resize to the actual text size
        - inkCanvas and inkFlex: no effect on the widget
    * layout.anchorPoint: yeah, you can say that this is the point on the current widget that should be matched to the point on the parent calculated from layout.anchor mode
    * layout.HAlign and layout.VAlign: kind of, but it affects layout only when the widget is inside inkFlex, inkHorizontalPanel, inkVerticalPanel
    * renderTransform: yes, and it doesn't affect layout, all transformation effects are visual only (like you can scale or move widget with it, but widget will still effectively occupy the same rect area in the parent's layout as before any transformations) 
    */

struct Widget : IScriptable
{
    static constexpr const char* NAME = "inkWidget";
    static constexpr const char* ALIAS = NAME;

    Handle<PropertyManager> propertyManager;                      // 40
    uint8_t unk50[0x88 - 0x50];                                   // 50
    WidgetLayout layout;                                          // 88
    UITransform renderTransform;                                  // B8
    uint8_t unkE8[0xF8 - 0xE8];                                   // E8
    DynArray<Handle<UserData>> userData;                          // F8
    DynArray<Handle<WidgetLogicController>> secondaryControllers; // 108
    DynArray<Handle<IEffect>> effects;                            // 118
    Handle<WidgetLogicController> logicController;                // 128
    Handle<StyleResourceWrapper> style;                           // 138
    Handle<LayerProxy> layerProxy;                                // 148
    uint8_t unk158[0x168 - 0x158];                                // 158
    WeakHandle<Widget> parentWidget;                              // 168
    uint8_t unk178[0x188 - 0x178];                                // 178
    CName name;                                                   // 188
    CName state;                                                  // 190
    Vector2 size;                                                 // 198
    Vector2 desiredSize;                                          // 1A0
    Vector2 renderTransformPivot;                                 // 1A8
    uint8_t unk1B0[0x1E0 - 0x1B0];                                // 1B0
    HDRColor tintColor;                                           // 1E0
    float opacity;                                                // 1F0
    SharedSpinLock parentLock;                                    // 1F4
    SharedSpinLock unk1F5;                                        // 1F5
    SharedSpinLock unk1F6;                                        // 1F6
    SharedSpinLock userDataLock;                                  // 1F7
    bool visible;                                                 // 1F8
    bool canSupportFocus;                                         // 1F9
    bool fitToContent;                                            // 1FA
    bool isInteractive;                                           // 1FB
    bool affectsLayoutWhenHidden;                                 // 1FC
    uint8_t flags;                                                // 1FD
};
RED4EXT_ASSERT_SIZE(Widget, 0x200);
} // namespace RED4ext::ink
