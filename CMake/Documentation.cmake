# --- LeeEngine3/CMake/Documentation.cmake ---

add_custom_target(doc
  COMMAND doxygen ${PROJECT_SOURCE_DIR}/Doxyfile
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  VERBATIM
)