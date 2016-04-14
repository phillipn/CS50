/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int resize = atoi(argv[1]);
    if (resize>100 ||resize<0) {
        printf("Need a number between 0 and 100\n");
        return 1;
    }
    char* infile = argv[2];
    char* outfile = argv[3];

    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    BITMAPFILEHEADER bfout;
    BITMAPINFOHEADER biout;
    biout=bi;
    bfout=bf;
    biout.biWidth = bi.biWidth * resize;
    biout.biHeight = bi.biHeight * resize;
    
    // determine padding for scanlines
    int paddingin =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingout =  (4 - (biout.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bfout.bfSize= 54 + biout.biWidth * abs(biout.biHeight) * 3 + abs(biout.biHeight) *  paddingout;
    biout.biSizeImage= ((((biout.biWidth * biout.biBitCount) + 31) & ~ 31) / 8) * abs(biout.biHeight);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfout, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biout, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        for(int n=0; n<resize; n++)
        {
        
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int m=0; m<resize;m++)
                {
        
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        
                // skip over padding, if any
                fseek(inptr, paddingin, SEEK_CUR);
        
                // then add it back (to demonstrate how)
                for (int k = 0; k < paddingout; k++)
                {
                    fputc(0x00, outptr);
                }
                    fseek(inptr, -(bi.biWidth * 3 + paddingin), SEEK_CUR);
        }
        fseek(inptr, bi.biWidth*3+ paddingin, SEEK_CUR);
    }
        
            // close infile
            fclose(inptr);
        
            // close outfile
            fclose(outptr);
        
            // that's all folks
            return 0;
    }
