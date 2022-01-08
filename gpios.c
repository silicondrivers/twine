#include "twine.h"

void initGpios(void)
{
    PASEL0 = 0x0000;
    PADIR  = 0xFFFF;
    PAOUT  = 0x0000;
    PBSEL0 = 0x0000;
    PBDIR  = 0xFFFF;
    PBOUT  = 0x0000;
    PCSEL0 = 0x0000;
    PCDIR  = 0xFFFF;
    PCOUT  = 0x0000;
    PDSEL0 = 0x000;
    PDDIR  = 0xFFF;
    PDOUT  = 0x000;
}
