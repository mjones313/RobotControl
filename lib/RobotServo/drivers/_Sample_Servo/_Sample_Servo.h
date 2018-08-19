// This is a hasic sample header file for new servo

#ifndef _SAMPLE_SERVO_H_
#define _SAMPLE_SERVO_H_

#include "baseServo.h"


class SAMPLE_Servo : public baseServo
{
    public:

        SAMPLE_Servo();
        ~SAMPLE_Servo();

        // Methos MUST be implemented
        //
        bool reset() override;
        uint32_t getVersion(byte id) override;


        bool resetServo() override;
        bool resetServo(byte id) override; 

        bool move(byte id, int16_t pos, uint16_t time) override;
        bool setLED(byte id, bool mode) override;
        bool setLED(bool mode) override;

        int16_t getPos(byte id) override;
        int16_t getPos(byte id, bool lockAfterGet) override;

        bool lock(byte id) override;
        bool unlock(byte id) override;

        // Methods can be overrided (optional)
        //
        // void initBus() override;
        // void showInfo() override;

        // bool validId(byte id) override;
        // bool validPos(int16_t) override;

        // bool isLocked(byte id) override;
        // bool lockAll() override;
        // bool unlockAll() override;
        
        // bool moveX(byte cnt, byte *data) override;
        // bool goAngle(byte id, int16_t angle, uint16_t time) override;

        // uint16_t lastPos(byte id)  override;
        // uint16_t lastAngle(byte id) override;

    private:
        
};

#endif