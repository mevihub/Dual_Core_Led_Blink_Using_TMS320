

#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"


// Take empty project

void main(void)
{
    Device_init();
    Interrupt_initModule();
    Interrupt_initVectorTable();

    while(1)
    {

        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0);
        DEVICE_DELAY_US(500000);
        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1);
        DEVICE_DELAY_US(500000);
    }
}
