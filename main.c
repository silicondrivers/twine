#include "twine.h"

int main( void )
{
    WDTCTL = WDTPW + WDTHOLD;       // [stop] disable watchdog timer

    initGpios();
    startXt1Clk();
    startRtcClk();

    __enable_interrupt();

    taskManager();

    return 0;
}
