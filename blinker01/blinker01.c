#include "psoc.h"

void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void PUT8 ( unsigned int, unsigned int );
unsigned int GET8 ( unsigned int );
void dummy ( unsigned int );

int notmain ( void )
{
    // LED: OUT: Port 2.1 Strong, initially OFF
    // DM 2,1,0: Strong: 1 1 0 (DATA = 1 ON, 0 OFF)
    unsigned int pc1 = GET8(REG_PRT2_PC1);
    pc1 &= ~PRT_PC__DRIVE_MODE_MASK;
    pc1 |=  PRT_PC__DRIVE_MODE_MASK & PRT_PC__DRIVE_MODE__STRONG;
    PUT8(REG_PRT2_PC1, pc1);

    while(1)
    {
        pc1 = GET8(REG_PRT2_PC1);
        PUT8(REG_PRT2_PC1, pc1 & ~PRT_PC__DATA_OUT);
        for(unsigned int ra=0;ra<200000;ra++) dummy(ra);

        pc1 = GET8(REG_PRT2_PC1);
        PUT8(REG_PRT2_PC1, pc1 |  PRT_PC__DATA_OUT);
        for(unsigned int ra=0;ra<200000;ra++) dummy(ra);
    };

    return(0);
}
