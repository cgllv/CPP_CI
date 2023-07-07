set(TEST_APP_NAME "${LIB_NAME}Test")
set(TEST_MODULE_PATH "${LIBRARY_MODULE_PATH}/test")
set(TEST_SRC_PATH "${TEST_MODULE_PATH}/src")

include_directories(${LIBRARY_INCLUDE_PATH} ${TEST_THIRD_PARTY_INCLUDE_PATH})

file(GLOB TEST_SOURCE_FILES "${TEST_SRC_PATH}/*.cpp")

add_executable(${TEST_APP_NAME} ${TEST_SOURCE_FILES})
target_link_libraries(${TEST_APP_NAME} ${LIB_NAME} Threads::Threads)
enable_testing()
ParseAndAddCatchTests(${TEST_APP_NAME})
