##最低版本号要求##
cmake_minimum_required (VERSION 2.8)

##project info##
set(EXE_NAME test_json)

#------------------------------------------[0]----------------------------------------------------#
####库文件的默认输出路径，这里设置为工程目录下的lib目录
set(EXECUTABLE_OUTPUT_PATH
        ${PROJECT_SOURCE_DIR}/android/${ANDROID_ABI}/bin)
#-------------------------------------------------------------------------------------------------#

##add inlude include_directories and link_libraries ##
include_directories(. ${PROJECT_SOURCE_DIR}/thirdparty/include)

######################################################################################
##添加非标准的共享库搜索路径
####link_directories(${BASE_LIB_DIR}/log4cplus ${PUB_LIB_DIR})
######################################################################################
#------------------------------------------[1]----------------------------------------------------#
####添加第三方库 log4cplus ysoslog boost_system boost_chrono boost_thread boost_filesystem dl sys_platform_sdk)
#add_library(json SHARED IMPORTED)

#3.添加库的路径
#set_target_properties(json
#        PROPERTIES IMPORTED_LOCATION
#        ${PROJECT_SOURCE_DIR}/thirdparty/lib/json/${ANDROID_ABI}/libjson.so)
#-------------------------------------------------------------------------------------------------#
include_directories(${PROJECT_SOURCE_DIR}/json/include)


add_library( # Sets the name of the library.
        json

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        json/src/json_reader.cpp
        json/src/json_value.cpp
        json/src/json_writer.cpp)


##查找当前目录下的所有源文件####并将名称保存到DIR_SRCS变量##
#aux_source_directory(./src SRC_LIST)

#------------------------------------------[2]----------------------------------------------------#

add_executable(${EXE_NAME} main.cpp)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

target_link_libraries( # Specifies the target library.
        ${EXE_NAME}
        json

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )
#-------------------------------------------------------------------------------------------------#