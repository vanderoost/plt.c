# plt.c

C library for plotting in the terminal with [Unicode block elements](https://en.wikipedia.org/wiki/Unicode_block).

*Currently only supports histograms.*

Example usage:

```c
float data[COUNT];

...

plt_hist(data, COUNT, ROWS, COLS);
```

Output:
![plt_hist example](doc/plt_hist-example.png)

## Programming screencast

Walkthrough coding this up from scratch up to the initial commit of this repo.

[![Histogram Plotting in C](https://img.youtube.com/vi/aLNlyBNU0tw/mqdefault.jpg)](https://www.youtube.com/watch?v=aLNlyBNU0tw)
