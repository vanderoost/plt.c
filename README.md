# plt.c

![plt_hist example](doc/plt_hist-example.png)

C library for plotting in the terminal with [unicode block elements](https://en.wikipedia.org/wiki/Unicode_block).

*Currently only supports histograms.*

Example usage:

```c
float data[COUNT];

...

plt_hist(data, COUNT, ROWS, COLS);
```

## Blog article

Read about how I created this library from scratch: [Plotting histograms in the terminal](https://vanderoost.com/articles/2026/09/11/histogram-plotting-in-the-terminal/)

## Screencast

Walkthrough where I'm cooking this up from scratch:

[![Histogram Plotting in C](https://img.youtube.com/vi/aLNlyBNU0tw/mqdefault.jpg)](https://youtu.be/aLNlyBNU0tw)
