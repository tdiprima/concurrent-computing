## CMake Logging: "message"

[**CMake Docs:** message](https://cmake.org/cmake/help/v3.0/command/message.html)

[**Logging Useful Variables**](https://cmake.org/Wiki/CMake_Useful_Variables/Logging_Useful_Variables)

### CMAKE\_SOURCE_DIR

```cmake
# this is the directory, from which cmake was started, i.e. the top level source directory 
MESSAGE( STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR} )
```

### CMAKE\_BINARY_DIR

```
# if you are building in-source, this is the same as CMAKE_SOURCE_DIR, otherwise 
# this is the top level directory of your build tree 
MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )
```
