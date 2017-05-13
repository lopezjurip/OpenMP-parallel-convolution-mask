# ¿Cómo usar?

```c
#include "./imagelib.h"

int main(int argc, char *argv[]) {
  // Cargamos una imagen
  Image *img = img_png_read_from_file("./image.png");
  // Iteramos sobre la matriz de pixeles
  for (int img_row = 0; img_row < img->height; img_row++) {
    for (int img_col = 0; img_col < img->width; img_col++) {
      // En este caso hacemos que la imagen sea negra
      img->pixels[img_row][img_col].R = 0;
      img->pixels[img_row][img_col].G = 0;
      img->pixels[img_row][img_col].B = 0;
    }
  }
  // Escribimos la imagen a un archivo
  img_png_write_to_file(img, "./image2.png");
  // Liberamos memoria
  img_destroy(img);
}
```
