aux_source_directory(. srcs)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(MomentPlus SHARED ${srcs})
add_library(MomentPlus_static STATIC ${srcs})

set_target_properties(MomentPlus_static PROPERTIES OUTPUT_NAME "MomentPlus")

set_target_properties(MomentPlus PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(MomentPlus_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

set_target_properties(MomentPlus PROPERTIES VERSION 0.1 SOVERSION 1)


