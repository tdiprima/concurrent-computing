## Logging in CMake: Utilizing "message"

For more in-depth knowledge, refer to [CMake Documentation: message](https://cmake.org/cmake/help/v3.0/command/message.html)

Review the link for [Logging Useful Variables](https://cmake.org/Wiki/CMake_Useful_Variables/Logging_Useful_Variables)

### Understanding CMAKE\_SOURCE_DIR

```cmake
# This denotes the directory from which the cmake was initiated, essentially the top-level source directory
MESSAGE( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
```

### An Insight into CMAKE\_BINARY_DIR

```cmake
# If an in-source build is occurring, this is synonymous with CMAKE_SOURCE_DIR, otherwise 
# it represents the top-level directory of your build tree 
MESSAGE( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
```

<br>