#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // juste round the average of all the colors. simple
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtBlue = x;
        }
    }

    return;
}

int gap(int value)
{
    if (value > 255)
    {
        return 255;
    }
    return value;

    //return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    This took e so much time and i still dont understand why. for the if condition whe  the value
    exceed 255. i just made an if statement and if its exceed 255 the rgbtValue would just come back
    to 255 but it didn't work. i had to check online to look for a solution. they did like me but some use a gap function
    like i did for that if statement, other used a weird condition like value "> 255 ? 255 : value" and it worked
    i still don't know why it didn't work for me
    */

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int  originalRed = pixel.rgbtRed, originalGreen = pixel.rgbtGreen, originalBlue = pixel.rgbtBlue;

            image[i][j].rgbtRed = gap(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image[i][j].rgbtGreen = gap(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image[i][j].rgbtBlue = gap(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));

        }
    }

    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //swap postion of the 2 oposites pixels. just make sure to touch only the value and it's opposite side
    // i made it with the k which is width - 1 since the startigng value is always 0
    for (int i = 0; i < height; i++)
    {
        int k = width - 1;
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][k]);
            k--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    for each row
    for each col
        set count to 0
        for every neighboring pixel within the radius m in the x direction
            for every neighboring pixel within the radius m in the y direction
                 add the color to the total
                 count++
        final_color = total/count
        setpixel(current x, current y, final_color)
        */
    RGBTRIPLE new_im[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int neigh_x[] = {i - 1, i, i + 1};
            int neigh_y[] = {j - 1, j, j + 1};
            float sumR = 0, sumG = 0, sumB = 0;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int cur_x = neigh_x[x], cur_y = neigh_y[y];
                    if (cur_x >= 0 && cur_x < height && cur_y >= 0 && cur_y < width)
                    {
                        RGBTRIPLE temp = image[cur_x][cur_y];
                        sumR += temp.rgbtRed;
                        sumG += temp.rgbtGreen;
                        sumB += temp.rgbtBlue;
                        count++;
                    }
                }
            }
            new_im[i][j].rgbtRed = round(sumR / count);
            new_im[i][j].rgbtGreen = round(sumG / count);
            new_im[i][j].rgbtBlue = round(sumB / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_im[i][j];
        }
    }

    return;
}
