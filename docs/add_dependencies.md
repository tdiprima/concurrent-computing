## Managing Dependencies 

Establish a **[dependency](https://cmake.org/cmake/help/v3.3/command/add_dependencies.html)** connection between top-tier targets using the `add_dependencies()` function. 

The syntax to follow:

`add_dependencies(<target> [<target-dependency>]...)`

Here, `<target>` denotes a top-tier target that **relies on** other top-tier targets.

This guarantees that other targets will be built before `<target>`.

A **top-tier target** refers to one that has been created by any of the following commands:

* **[add_executable()](https://cmake.org/cmake/help/v3.3/command/add_executable.html#command:add_executable)**
* **[add_library()](https://cmake.org/cmake/help/v3.3/command/add_library.html#command:add_library)** 
* **[add\_custom_target()](add_custom_target())**

However, this doesn't include targets that were automatically generated **by CMake** such as `install`.  

<br>