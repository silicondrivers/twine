#include "twine.h"

void startXt1Clk(void)
{
    // select XIN and XOUT functions on P4.1 and P4.2
    P4SEL0 |= (BIT1 | BIT2);

    while(CSCTL7 & XT1OFFG)
    {
        CSCTL7 &= (unsigned char) ~XT1OFFG;
        SFRIFG1 &= (unsigned char) ~OFIFG;
    }
}

// divide=256, count=128 = 1 second
void startRtcClk()
{
    RTCCTL &= ~RTCSS_3;
    RTCCTL &= ~RTCPS_7;
    RTCCTL |= RTCPS__256;
    RTCMOD = 128; // counter
    __data16_read_addr(RTCIV);
    RTCCTL |= RTCSS__XT1CLK; // start clock
    RTCCTL |= RTCSR; // reset RTC
    RTCCTL |= RTCIE; // enable RTC interrupts
}
