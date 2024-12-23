## OpenMP Practical Guide

The following collection includes diverse practical exercises and their corresponding solutions relevant to an OpenMP course. In-depth details about these projects are presented within the comments and the course's slide deck.

To utilize these application programs, simply copy the appropriate `def` file into `make.def` as follows:

```sh
cp def_files/apple.def ./make.def
```

Subsequently, construct and verify the programs like so:

```sh
make test
```

### Implementing Solutions

To build the solution files, duplicate the process above using the `make.def` file. The additional exercises hosted in the 'extras' directory cater to individuals seeking more advanced content. Please note that these have undergone less rigorous testing and could encounter issues during construction or operation on certain environments.

### Compatibility

These application programs have been successfully tested in environments such as Linux with GNU and Intel compilers, as well as Windows 7 with the Intel compiler. Additionally, tests have been performed on OS-X with an Apple XCode-loaded GNU environment. However, it should be noted that since Apple's OpenMP environment currently lacks threadprivate variable support, `pi_mc` solutions cannot be built and thus, must be exempted from the makefile.

Although these programs function with the PGI compiler (pgi.def), they haven't been tested recently, which might call for some refinements.

### Guide for Windows Users

For users operating within a Windows 7 environment, execute the following procedure:

1. Initiate by navigating to Start Menu. Select:

```   
Intel Parallel Studio 2011/command prompt/ ia64 Visual Studio 2010 mode
```

2. `cd` to the destination folder.
3. Copy `win_intel.def` to `make.def`.
4. Utilize `nmake` to compose.

<br>