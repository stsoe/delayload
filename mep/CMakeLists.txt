add_executable(mep mep.cpp)
target_include_directories(mep PRIVATE ${MEP_SOURCE_DIR}/vart)
target_link_libraries(mep PRIVATE vart)
install(TARGETS mep)
