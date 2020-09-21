#define MB 1024 * 1024

int main(int argc, char const *argv[])
{
    int bigstack[16* MB];


    for (int i = 0; i < 1 * MB; i++)
    {
        bigstack[i] = -1;
    }
    
    return 0;
}
