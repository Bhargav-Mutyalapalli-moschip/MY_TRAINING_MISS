#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
//Function to change the endianess
uint32_t ChangeEndianness(uint32_t u32Value)
{
    uint32_t u32Result = 0;
    u32Result |= (u32Value & 0x000000FF) << 24;
    u32Result |= (u32Value & 0x0000FF00) << 8;
    u32Result |= (u32Value & 0x00FF0000) >> 8;
    u32Result |= (u32Value & 0xFF000000) >> 24;
    return u32Result;
}
int main()
{
    uint32_t u32CheckData  = 0x11223344;
    uint32_t u32ResultData =0;
    u32ResultData = ChangeEndianness(u32CheckData);  //swap the data
    printf("0x%x\n",u32ResultData);
    u32CheckData = u32ResultData;
    u32ResultData = ChangeEndianness(u32CheckData);//again swap the data
    printf("0x%x\n",u32ResultData);
    return 0;
}
