#ifndef _EVENTDATA_H_
#define _EVENTDATA_H_
#include <ESP8266WiFi.h>

#define ED_INVALID_DATA     -32768

#define ED_SIZE_MPU         3
#define ED_SIZE_TOUCH       1
#define ED_SIZE_PSXBUTTON   1
#define ED_SIZE_BATTERY_R   1
#define ED_SIZE_BATTERY_L   1
#define ED_SIZE_GPIO        20

#define ED_OFFSET_MPU       0
#define ED_OFFSET_TOUCH     3
#define ED_OFFSET_PSXBUTTON 4
#define ED_OFFSET_BATTERY_R 5
#define ED_OFFSET_BATTERY_L 6
#define ED_OFFSET_GPIO      7


#define ED_MAX_DEVICE       6
#define ED_DATA_SIZE        64


class EventData {

    public:

        enum class DEVICE : uint8_t {
            mpu = 1, touch = 2, psx_button = 3, battery_reading = 4, battery_level = 5, gpio = 6
        };

        enum class MPU_TARGET : uint8_t {
            x = 1, y = 2, z = 3
        };

        EventData();
        ~EventData();

        bool IsValid(uint8_t device, uint8_t devId, uint8_t target);

        bool SetData(uint8_t device, uint8_t devId, uint8_t target, int16_t value);
        int16_t GetData(uint8_t device, uint8_t devId, uint8_t target);

        bool SetData(DEVICE device, uint8_t devId, uint8_t target, int16_t value) {
            return SetData((uint8_t) device, devId, target, value);
        }
        int16_t GetData(DEVICE device, uint8_t devId, uint8_t target) {
            return GetData((uint8_t) device, devId, target);
        }

        // In the first version, devId is not used, so let's allow to skip this parameter in common interface first
        bool SetData(DEVICE device, uint8_t target, int16_t value) { 
            return SetData((uint8_t) device, 0, target, value); 
        }
        int16_t GetData(DEVICE device, uint8_t target) { 
            return GetData((uint8_t) device, 0, target); 
        }

        uint8_t DeviceDataSize(uint8_t device);

    private:
        const uint8_t _offset[ED_MAX_DEVICE + 1] = {0, ED_OFFSET_MPU, ED_OFFSET_TOUCH, ED_OFFSET_PSXBUTTON, ED_OFFSET_BATTERY_R, ED_OFFSET_BATTERY_L, ED_OFFSET_GPIO };
        const uint8_t _size[ED_MAX_DEVICE + 1] = {0, ED_SIZE_MPU, ED_SIZE_TOUCH, ED_SIZE_PSXBUTTON, ED_SIZE_BATTERY_R, ED_SIZE_BATTERY_L, ED_SIZE_GPIO};

        int16_t _data[ED_DATA_SIZE];

        uint8_t Offset(uint8_t device, uint8_t devId, uint8_t target);

};


#endif
