# --- LeeEngine3/3rdParty/glm/CMakeLists.txt ---

add_custom_target(GLM ALL)
set_target_properties(GLM PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include")