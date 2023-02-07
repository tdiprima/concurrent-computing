## OpenMP Mac

```sh
which gcc
# /usr/bin/gcc
```

```sh
gcc --version

# Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
# Apple LLVM version 8.0.0 (clang-800.0.42.1)
# Target: x86_64-apple-darwin16.1.0
# Thread model: posix
# InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

Instead, point those variables to something in `/usr/local/bin`, e.g.:

```sh
export CC=/usr/local/bin/gcc
```

and similarly for the other two variables.


On a mac, the command `gcc` is a symlink to `Clang`.

So by calling

```sh
gcc -fopenmp -o Parallel.b Parallel.c
```

you are in fact using Clang, which until now has not had built-in support for OpenMP.

The newer versions of Clang do have support for OpenMP according to [this post](http://blog.llvm.org/2015/05/openmp-support_22.html) (where you can also find instructions on how to set it up).

On the other hand, if you still want to use `gcc`, I can guide you through the steps that worked for me.

1) Install gcc with brew. The command you used should work (it did for me one hour ago):

```sh
brew install gcc --without-multilib
```
Alternatively, if brew says that you already have gcc installed, you can try

```sh
brew reinstall gcc --without-multilib
```
As you may have noted, if you don't specify `--without-multilib`, brew warns you that OpenMP may not work.

2) Find the location of the newly installed gcc. Note that brew appends the version number to gcc so that it does not conflict with the one installed by Command Line Tools. You will find the symlink in `/usr/local/bin`. In my case, it's `/usr/local/bin/gcc-5`. If you right-click and chose "Show original" it should show the gcc-5 executable in `/usr/local/Cellar/gcc/5.3.0/bin/gcc-5` (version numbers may differ).
3) Now you need to tell your system about it. Note that when calling a compiler, your bash will look into `/usr/bin` by default and not in `/usr/local/bin`. You need to add this directory to your `$PATH`. This can be easily done with the command: `PATH=/usr/local/bin:$PATH`.

4) Now you should be able to compile with OpenMP enabled using:

```sh
gcc-5 -fopenmp -o Parallel Parallel.c
```
Remark: gcc-5 is the version I have installed, yours might differ.

```sh
brew install cmake
brew install gcc --without-multilib
cmake -DCMAKE_CXX_COMPILER=g++-6 ..
make -j
```

It works for me!

http://blog.llvm.org/2015/05/openmp-support_22.html
