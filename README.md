# OpenMP Parallel Convolution Mask

* Patricio López Juri

## Run

```sh
# on the real environment
./run.sh

# if fails:
chmod +x ./run.sh
```

## Analysis


```sh
--- Running secuential ---

real	0m12.540s
user	0m12.156s
sys	0m0.380s
--- Done secuential ---

--- Running parallel ---

real	0m5.839s
user	0m23.524s
sys	0m0.420s
--- Done parallel ---

--- Running parallel (over-CPU) ---

real	0m6.043s
user	0m22.224s
sys	0m0.424s
--- Done parallel over ---
```

### Sequential

First we try a sequential operation with 1 CPU. The `real` and `user` times are the same because of this.

### Parallel

Using all the available CPU we get a `user` increase because its the sum of all the CPU but the real (perceived) time is lower.

#### Bad parallel

When we set to use more than the 8 cores (10 in this case), the `user` time seems to be equal or lower, but the `real` time is **higher**.

This should be the consequence of context switching between virtual threads, loosing time and decreasing the overall performance.

> Sorry, not visualization available :()
