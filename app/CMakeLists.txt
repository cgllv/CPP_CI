set(APP_NAME "${PROJECT_NAME}App")

set(APP_MODULE_PATH "${PROJECT_SOURCE_DIR}/app")
set(APP_SRC_PATH "${APP_MODULE_PATH}/src")

include_directories(${LIBRARY_INCLUDE_PATH} ${THIRD_PARTY_INCLUDE_PATH})

file(GLOB APP_SOURCE_FILES "${APP_SRC_PATH}/*.cpp")

add_executable(${APP_NAME} ${APP_SOURCE_FILES})
target_link_libraries(${APP_NAME} ${LIB_NAME} Threads::Threads)

# enable_testing()
# add_subdirectory(test)