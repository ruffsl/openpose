
 openpose_pickup_openpose_sources(${PROJECT_SOURCE_DIR})
 
 openpose_cuda_compile(cuda_objs ${cuda})
 list(APPEND srcs ${cuda_objs} ${cuda})


add_library(openpose ${srcs})

openpose_default_properties(openpose)
target_link_libraries(openpose ${OpenPose_LINKER_LIBS})
target_include_directories(openpose ${OpenPose_INCLUDE_DIRS}
                                 PUBLIC
                                 $<BUILD_INTERFACE:${OpenPose_INCLUDE_DIR}>
                                 $<INSTALL_INTERFACE:include>)
target_compile_definitions(openpose ${OpenPose_DEFINITIONS})
if(OpenPose_COMPILE_OPTIONS)
  target_compile_options(openpose ${OpenPose_COMPILE_OPTIONS})
endif()
set_target_properties(openpose PROPERTIES
    VERSION   ${OPENPOSE_TARGET_VERSION}
    SOVERSION ${OPENPOSE_TARGET_SOVERSION}
    )