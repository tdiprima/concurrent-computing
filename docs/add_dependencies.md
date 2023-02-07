## add_dependencies
Add a **[dependency](https://cmake.org/cmake/help/v3.3/command/add_dependencies.html)** between top-level targets.

`add_dependencies(<target> [<target-dependency>]...)`

<br>
Make a top-level `<target>` **depend on** other top-level targets 

to ensure that they build before `<target>` does.

A **top-level target** is one created by one of the

* **[add_executable()](https://cmake.org/cmake/help/v3.3/command/add_executable.html#command:add_executable)**
* **[add_library()](https://cmake.org/cmake/help/v3.3/command/add_library.html#command:add_library)**, or
* **[add\_custom_target()](add_custom_target())**

commands.

(But ***not*** targets generated ***by CMake*** like `install`)