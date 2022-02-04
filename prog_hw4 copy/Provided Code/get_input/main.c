extern void getInput(char* arr);

#define MAX_INPUT_LEN 10
static char inputArr[MAX_INPUT_LEN];

#define VIDEO_MEMORY ((char*) 0x500FE800)
#define VIDEO_NUM_ROWS 36
#define VIDEO_NUM_COLS 64

static void clearScreen(void)
{
    for (unsigned i = 0; i < VIDEO_NUM_ROWS * VIDEO_NUM_COLS; ++i)
        VIDEO_MEMORY[i] = ' ';
}

static void printInput(char* arr)
{
    for (unsigned i = 0; i < MAX_INPUT_LEN; ++i)
    {
        VIDEO_MEMORY[i] = '0' + i;
        VIDEO_MEMORY[i + VIDEO_NUM_COLS] = arr[i];
    }
}

int main()
{
    getInput(inputArr);
    clearScreen();
    printInput(inputArr);
    for (;;);
}
