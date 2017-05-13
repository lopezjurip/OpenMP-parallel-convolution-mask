#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/imagelib/imagelib.h"

float **read_kernel(char *kernel_path, size_t *H, size_t *W) {
        FILE *file = fopen(kernel_path, "r");
        char *line = NULL;
        size_t length = 0;
        ssize_t read;

        // Get width
        read = getline(&line, &length, file);
        size_t width = atoi(line);

        // Get height
        read = getline(&line, &length, file);
        size_t height = atoi(line);

        // Create kernel matrix
        float **K = calloc(height, sizeof(float *));

        // Populate kernel matrix
        size_t row = 0;
        while ((read = getline(&line, &length, file)) != -1) {
                K[row] = calloc(width, sizeof(float));

                size_t col = 0;
                char *pch = strtok(line, " ");
                while (pch != NULL) {
                        K[row][col] = atof(pch);
                        col += 1;
                        pch = strtok(NULL, " ");
                }
                row += 1;
        }

        // Free stuff
        fclose(file);
        free(line);

        // Return values
        (*H) = height;
        (*W) = width;
        return K;
}

int main(int argc, char *argv[]) {
        char *img_in_path = argv[1];
        char *kernel_path = argv[2];
        char *img_out_path = argv[3];

        size_t k_height = 0;
        size_t k_width = 0;
        float **K = read_kernel(kernel_path, &k_height, &k_width);

        Image *img = img_png_read_from_file(img_in_path);
        for (int row = 0; row < img->height; row++) {
                for (int col = 0; col < img->width; col++) {
                        img->pixels[row][col].R = 0;
                        img->pixels[row][col].G = 0;
                        img->pixels[row][col].B = 0;
                }
        }
        img_png_write_to_file(img, img_out_path);
        img_destroy(img);

        return 0;
}
