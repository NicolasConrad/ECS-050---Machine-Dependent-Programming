#include <stdint.h>

#define INT_ENABLE ((uint32_t*) 0x40000000)
#define INT_PENDING ((uint32_t*) 0x40000004)

#define CONTROLLER ((uint32_t*) 0x40000018)
#define LEFT 0x1
#define UP 0x2
#define DOWN 0x4
#define RIGHT 0x8

#define VIDEO_MEMORY ((char*) 0x500FE800)
#define VIDEO_NUM_ROWS 36
#define VIDEO_NUM_COLS 64

int enterPressed = 0;
int cursor = 0;
int cmdPressed = 0;
int arrElement=0;

void c_interrupt_handler(void)
{
    cmdPressed = 1;

    *INT_PENDING = 0x4;
}

void getInput(char* arr)
{
    *INT_ENABLE = 0x4;
    // TODO: Insert your code here.
    VIDEO_MEMORY[cursor] = '.';
    VIDEO_MEMORY[cursor+1] = '.';
    VIDEO_MEMORY[cursor+2] = '.';
    VIDEO_MEMORY[cursor+64] = '.';
    VIDEO_MEMORY[cursor+66] = '.';
    VIDEO_MEMORY[cursor+128] = '.';
    VIDEO_MEMORY[cursor+129] = '.';
    VIDEO_MEMORY[cursor+130] = '.';

    VIDEO_MEMORY[65] = 'q';
    VIDEO_MEMORY[67] = 'w';
    VIDEO_MEMORY[69] = 'e';
    VIDEO_MEMORY[71] = 'r';
    VIDEO_MEMORY[73] = 't';
    VIDEO_MEMORY[75] = 'y';
    VIDEO_MEMORY[77] = 'u';
    VIDEO_MEMORY[79] = 'i';
    VIDEO_MEMORY[81] = 'o';
    VIDEO_MEMORY[83] = 'p';

    VIDEO_MEMORY[257] = 'a';
    VIDEO_MEMORY[259] = 's';
    VIDEO_MEMORY[261] = 'd';
    VIDEO_MEMORY[263] = 'f';
    VIDEO_MEMORY[265] = 'g';
    VIDEO_MEMORY[267] = 'h';
    VIDEO_MEMORY[269] = 'j';
    VIDEO_MEMORY[271] = 'k';
    VIDEO_MEMORY[273] = 'l';
    VIDEO_MEMORY[275] = 'E';

    VIDEO_MEMORY[449] = 'z';
    VIDEO_MEMORY[451] = 'x';
    VIDEO_MEMORY[453] = 'c';
    VIDEO_MEMORY[455] = 'v';
    VIDEO_MEMORY[457] = 'b';
    VIDEO_MEMORY[459] = 'n';
    VIDEO_MEMORY[461] = 'm';
    VIDEO_MEMORY[463] = '?';
    VIDEO_MEMORY[465] = '?';
    VIDEO_MEMORY[467] = '?';

    VIDEO_MEMORY[640] = 'E';
    VIDEO_MEMORY[641] = 'N';
    VIDEO_MEMORY[642] = 'T';
    VIDEO_MEMORY[643] = 'E';
    VIDEO_MEMORY[644] = 'R';
    VIDEO_MEMORY[645] = 'E';
    VIDEO_MEMORY[646] = 'D';
    VIDEO_MEMORY[647] = ':';

    uint32_t controller = 0;

    while(1)
    {
        controller = *CONTROLLER;
        if(controller & LEFT||controller & RIGHT||controller & UP||controller & DOWN)
        {
            VIDEO_MEMORY[cursor] = ' ';
            VIDEO_MEMORY[cursor+1] = ' ';
            VIDEO_MEMORY[cursor+2] = ' ';
            VIDEO_MEMORY[cursor+64] = ' ';
            VIDEO_MEMORY[cursor+66] = ' ';
            VIDEO_MEMORY[cursor+128] = ' ';
            VIDEO_MEMORY[cursor+129] = ' ';
            VIDEO_MEMORY[cursor+130] = ' ';
        }

        if(controller & LEFT)
        {
            if(cursor >= 0 && cursor <= 18 && cursor-2 >=0 || cursor >= 192 && cursor <= 210 && cursor-2 >= 192 ||cursor >= 384 && cursor <= 402 && cursor-2 >= 384)
            {
                cursor-=2;
            }
        }else if(controller & RIGHT)
        {
            if(cursor >= 0 && cursor <= 18 && cursor+2 <= 18 || cursor >= 192 && cursor <= 210 && cursor+2 <= 210 ||cursor >= 384 && cursor <= 402 && cursor+2 <= 402)
            {
                cursor += 2;
            }
        }else if(controller & UP)
        {
            if(cursor-192 >= 0)
            {
                cursor-=192;
            }
        }else if(controller & DOWN)
        {
            if(cursor+192 <= 402)
            {
                cursor+=192;
            }
        }

        if(controller & LEFT||controller & RIGHT||controller & UP||controller & DOWN)
        {
            VIDEO_MEMORY[cursor] = '.';
            VIDEO_MEMORY[cursor+1] = '.';
            VIDEO_MEMORY[cursor+2] = '.';
            VIDEO_MEMORY[cursor+64] = '.';
            VIDEO_MEMORY[cursor+66] = '.';
            VIDEO_MEMORY[cursor+128] = '.';
            VIDEO_MEMORY[cursor+129] = '.';
            VIDEO_MEMORY[cursor+130] = '.';
            *CONTROLLER = 0x0;
        }

        if(cmdPressed)
        {
            if(cursor==0)
            {
                arr[arrElement] = 'q';
            }else if(cursor==2)
            {
                arr[arrElement] = 'w';
            }else if(cursor==4)
            {
                arr[arrElement] = 'e';
            }else if(cursor==6)
            {
                arr[arrElement] = 'r';
            }else if(cursor==8)
            {
                arr[arrElement] = 't';
            }else if(cursor==10)
            {
                arr[arrElement] = 'y';
            }else if(cursor==12)
            {
                arr[arrElement] = 'u';
            }else if(cursor==14)
            {
                arr[arrElement] = 'i';
            }else if(cursor==16)
            {
                arr[arrElement] = 'o';
            }else if(cursor==18)
            {
                arr[arrElement] = 'p';
            }else if(cursor==192)
            {
                arr[arrElement] = 'a';
            }else if(cursor==194)
            {
                arr[arrElement] = 's';
            }else if(cursor==196)
            {
                arr[arrElement] = 'd';
            }else if(cursor==198)
            {
                arr[arrElement] = 'f';
            }else if(cursor==200)
            {
                arr[arrElement] = 'g';
            }else if(cursor==202)
            {
                arr[arrElement] = 'h';
            }else if(cursor==204)
            {
                arr[arrElement] = 'j';
            }else if(cursor==206)
            {
                arr[arrElement] = 'k';
            }else if(cursor==208)
            {
                arr[arrElement] = 'l';
            }else if(cursor==210)
            {
                break;
            }else if(cursor==384)
            {
                arr[arrElement] = 'z';
            }else if(cursor==386)
            {
                arr[arrElement] = 'x';
            }else if(cursor==388)
            {
                arr[arrElement] = 'c';
            }else if(cursor==390)
            {
                arr[arrElement] = 'v';
            }else if(cursor==392)
            {
                arr[arrElement] = 'b';
            }else if(cursor==394)
            {
                arr[arrElement] = 'n';
            }else if(cursor==396)
            {
                arr[arrElement] = 'm';
            }else if(cursor==398)
            {
                arr[arrElement] = '?';
            }else if(cursor==400)
            {
                arr[arrElement] = '?';
            }else if(cursor==402)
            {
                arr[arrElement] = '?';
            }
            VIDEO_MEMORY[arrElement+649] = arr[arrElement];
            cmdPressed=0;
            arrElement++;
        }
    }

    *INT_ENABLE = 0x0;
}


