#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>
#include <RED4ext/Scripting/Natives/vehicleTransmission.hpp>
#include <RED4ext/Scripting/Natives/vehicleEngine.hpp>

namespace RED4ext
{
namespace vehicle { 
struct WheeledBaseObject : vehicle::BaseObject
{
    static constexpr const char* NAME = "vehicleWheeledBaseObject";
    static constexpr const char* ALIAS = "WheeledObject";
    static constexpr const uint32_t VFT = 3377402363;

// overrides
    virtual void Attach(void *) override;                   // 

    virtual void sub_268() override;                        // 268 
    virtual void sub_270() override;                        // 270 
    virtual float sub_278() override;                       // 278 
    virtual int32_t sub_280(WorldTransform*) override;      // 280
    virtual uint64_t sub_288() override;                    // 288 max engine torque / total mass

    virtual float sub_2A0() override;                       // 2A0 get something with last gear

    virtual void sub_2B0(uint64_t, uint64_t) override;      // 2B0 vehicleCNameThing, engine, transmission
    virtual void sub_2B8() override;                        // 2B8
    virtual void sub_2C0(void *, void *) override;          // 2C0 
    virtual void sub_2C8() override;                        // 2C8 something Unk568

    virtual void * sub_2D8() override;                      // 2D8 
    virtual void sub_2E0() override;                        // 2E0 call physics->sub_118()
    virtual void sub_2E8() override;                        // 2E8 physics->UpdateWheelAnimations()
    virtual void sub_2F0() override;                        // 2F0 get this->engine
    virtual void * sub_2F8() override;                      // 2F8

    virtual uint64_t sub_308(bool) override;                // 308 calls sub_328, resets transmission, burnout

    virtual void sub_328(bool) override;                    // 328
    virtual uint8_t sub_330() override;                     // 330

    virtual uint64_t sub_348() override;                    // 348
    virtual void sub_350() override;                        // 350
    virtual void sub_358(Handle<ISerializable>*) override;  // 358

    virtual void sub_378() override;                        // 378
    virtual void sub_380() override;                        // 380

    void * interactionsMaybe;           // B90
    Transmission * transmissionData;    // B98
    Engine * engineData;                // BA0
    void * burnoutData;                 // BA8
    uint32_t unkBB0;
    uint8_t disableTireShooting;
    uint8_t disableChargePortDestruction;
    uint8_t canDriveOnVehicles;
    float wheelBumperLengthScalor;
    float wheelBumperWidthScalor;
    float wheelBumperVertOffsetScalor;
    float tireOnVehicleDamageImpulseScalor;
    uint64_t unkBC8[3];
};
RED4EXT_ASSERT_SIZE(WheeledBaseObject, 0xBE0);
} // namespace vehicle
using WheeledObject = vehicle::WheeledBaseObject;
} // namespace RED4ext
