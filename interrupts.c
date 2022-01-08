#include "twine.h"

extern unsigned short task_1_status;
extern unsigned short task_2_status;
extern unsigned short task_3_status;
extern unsigned short task_4_status;

extern short task_1_timeout;
extern short task_2_timeout;
extern short task_3_timeout;
extern short task_4_timeout;

#pragma vector = RTC_VECTOR

__interrupt void RTCIntervalInterrupt(void)
{
    PM5CTL0 &= ~LOCKLPM5;

    __data16_read_addr(RTCIV);

    RTCMOD = 128; // counter

    if(task_1_status)
        task_1_timeout--;

    if(task_2_status)
        task_2_timeout--;

    if(task_3_status)
        task_3_timeout--;

    if(task_4_status)
        task_4_timeout--;

}
