project(userver-samples-testsuite-support CXX)

add_executable(${PROJECT_NAME}
  logcapture.cpp
  main.cpp
  now.cpp
  tasks.cpp
  testpoint.cpp
)
target_link_libraries(${PROJECT_NAME} userver-core)

# /// [testsuite - cmake]
userver_testsuite_add(
  NAME testsuite-${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests
  PYTHON_BINARY ${TESTSUITE_PYTHON_BINARY}
  PYTEST_ARGS
  --service-config=${CMAKE_CURRENT_SOURCE_DIR}/static_config.yaml
  --service-binary=${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
  --config-fallback=${CMAKE_CURRENT_SOURCE_DIR}/dynamic_config_fallback.json
  --service-config-vars=${CMAKE_CURRENT_SOURCE_DIR}/config_vars.yaml
)
# /// [testsuite - cmake]
