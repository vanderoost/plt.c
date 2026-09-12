#include "plt.h"
#include <stdio.h>
#include <stdlib.h>

void plt_hist(float *data, size_t len, size_t rows, size_t cols) {
  // Get the x range
  float x_min = data[0], x_max = data[0];
  for (size_t i = 1; i < len; ++i) {
    float val = data[i];

    if (val < x_min) {
      x_min = val;
    }

    if (val > x_max) {
      x_max = val;
    }
  }
  float x_range = x_max - x_min;
  float x_scale = x_range > 0.0f ? cols / x_range : 0.0f;

  // Keep track of bucket counts
  size_t buckets[cols] = {};
  for (size_t i = 0; i < len; ++i) {
    size_t bucket_ix = (data[i] - x_min) * x_scale;
    bucket_ix = bucket_ix > cols - 1 ? cols - 1 : bucket_ix;

    buckets[bucket_ix]++;
  }

  // Find the max count
  size_t bucket_max = 0;
  for (size_t i = 0; i < cols; ++i) {
    if (buckets[i] > bucket_max) {
      bucket_max = buckets[i];
    }
  }

  // clang-format off
  char *blocks[] = {
    " ",
    "\u2581",
    "\u2582",
    "\u2583",
    "\u2584",
    "\u2585",
    "\u2586",
    "\u2587",
    "\u2588",
  };
  // clang-format on
  size_t block_count = sizeof(blocks) / sizeof(*blocks) - 1;

  // Scale heights
  for (size_t i = 0; i < cols; ++i) {
    buckets[i] = (buckets[i] * rows * block_count) / bucket_max;
  }

  // Plotting
  for (size_t i = 0; i < rows; ++i) {
    size_t height = (rows - 1 - i) * block_count;

    for (size_t j = 0; j < cols; ++j) {
      int block_ix = buckets[j] - height;
      block_ix = block_ix < 0 ? 0 : block_ix;
      block_ix = block_ix > (int)block_count ? block_count : block_ix;

      printf("%s", blocks[block_ix]);
    }
    printf("\n");
  }
}
