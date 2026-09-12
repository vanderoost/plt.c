#include "plt/plt.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_COUNT 1000000
#define ROWS 12
#define COLS 72

int main(void) {
  float data[SAMPLE_COUNT];
  for (size_t i = 0; i < SAMPLE_COUNT; ++i) {
    float roll_a = (float)random() / RAND_MAX;
    float roll_b = (float)random() / RAND_MAX;

    data[i] = roll_a;
  }
  printf("\n");

  plt_hist(data, SAMPLE_COUNT, ROWS, COLS);

  return 0;
}
