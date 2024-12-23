## Working with OpenMP on Mac OS

There is a peculiarity in Mac OS where the `gcc` command is, in fact, a symlink to `Clang`. This detail becomes important when it comes to compatibility with OpenMP. Unfortunately, till recent versions, Clang did not support OpenMP.

To verify your `gcc` configuration, use:

```sh
which gcc
# /usr/bin/gcc

gcc --version
```

The output reveals that by default, `gcc` points to paths located in `/usr/bin/`.

However, you could point the variables to paths in `/usr/local/bin`. Use the `export` command to achieve this as shown below:

```sh
export CC=/usr/local/bin/gcc
```

Apply similar changes for other variables as well.

Happily, newer versions of `Clang` do support OpenMP as per an article on the [llvm blog](http://blog.llvm.org/2015/05/openmp-support_22.html). This post also provides instructions on setting it up.

But suppose you prefer using `gcc`, the following steps can guide you:

1. Install `gcc` with brew as follows:
  
   ```sh
   brew install gcc --without-multilib
   ```
   If brew informs you that `gcc` is already installed, try reinstalling it:

   ```sh
   brew reinstall gcc --without-multilib
   ```

   Without the flag `--without-multilib`, brew will warn you about potential incompatibilities with OpenMP.

2. Find the location of the newly installed `gcc`. For instance, if `gcc` is installed with version appended, you will find the symlink like `/usr/local/bin/gcc-5` to avoid conflict with the one installed by Command Line Tools.

3. Let your system know about the new `gcc` location. You can accomplish this by adding the directory to your `$PATH` variable:

   ```sh
   PATH=/usr/local/bin:$PATH
   ```

4. You should now be able to compile with OpenMP enabled, using a command similar to:

   ```sh
   gcc-5 -fopenmp -o Parallel Parallel.c
   ```

   Note that `gcc-5` is just an example; replace `5` with whichever version you have installed.

To compile using cmake, you can use the example commands:

   ```sh
   brew install cmake
   brew install gcc --without-multilib
   cmake -DCMAKE_CXX_COMPILER=g++-6 ..
   make -j
   ```

That's it! These instructions should get OpenMP on Mac OS functioning correctly.

Additional information can be found [here](http://blog.llvm.org/2015/05/openmp-support_22.html).

<br>
