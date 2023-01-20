

#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"


// Take empty project

void main(void)
{
    Device_init();

    // Send boot command to allow the CPU2 application to begin execution
    //
    Device_bootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH);

    EALLOW;

    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED1);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED1, GPIO_CORE_CPU1);

    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED2);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED2, GPIO_CORE_CPU2);
    EDIS;

    Interrupt_initModule();
    Interrupt_initVectorTable();

    EINT;
    ERTM;


    while(1)
    {

        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 0);
        DEVICE_DELAY_US(50000);
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1);
        DEVICE_DELAY_US(50000);
    }
}
