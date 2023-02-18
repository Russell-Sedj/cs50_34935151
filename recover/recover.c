#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define the byte type which is a 8bits data
typedef uint8_t BYTE;
//define the block size, it is not supposed to change so its declared const
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // check arguements
    if (argc != 2)
    {
        printf("Usage: ./recover [raw file]\n");
        return 1;
    }

    // open da file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fclose(card);
        printf("Couldn't open file %s\n", argv[1]);
        return 2;
    }

    //variables
    int k = 0, first = 1, inside_file = 0;
    BYTE buffer[BLOCK_SIZE];
    char *outname = malloc(8 * sizeof(char)); //outname is the name of the output which use 7 chareacter plus the \0
    FILE *recover = NULL; // recover is set to null by default. later it'll change

    while (fread(buffer, sizeof(char), BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] && 0xe0 == 0xe0))
        {
            if (first)
            {
                sprintf(outname, "%03i.jpg", k);
                recover = fopen(outname, "w");
                if (recover == NULL)
                {
                    fclose(recover);
                    printf("Couldn't open file %s\n", outname);
                    return 3;
                }
                fwrite(buffer, 1, BLOCK_SIZE, recover);
                first = 0;
                inside_file = 1;
                k++;
            }
            else
            {
                fclose(recover);
                sprintf(outname, "%03i.jpg", k);
                recover = fopen(outname, "w");
                if (recover == NULL)
                {
                    fclose(recover);
                    printf("Couldn't open file %s\n", outname);
                    return 4;
                }
                fwrite(buffer, 1, BLOCK_SIZE, recover);
                k++;
                inside_file = 1;
            }
        }
        else
        {
            if (inside_file == 1)
            {
                fwrite(buffer, 1, BLOCK_SIZE, recover);
            }
        }

        /* if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] && 0xe0 == 0xe0))
        {
            sprintf(outname, "%03i.jpg", k);
            recover = fopen(outname, "w");
            if (recover == NULL)
            {
                fclose(recover);
                printf("Couldn't open file %s\n", outname);
                return 3;
            }
            k++;
        }
        if (recover != NULL)
        {
            fwrite(buffer, sizeof(char), BLOCK_SIZE, recover);
        } */
    }

    fclose(card);
    free(outname);
    fclose(recover);

    return 0;
}