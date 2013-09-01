# --- Supremacy/3rdParty/glfw/CMakeLists.txt ---

set(GLFW_INCLUDE CACHE PATH "")

find_library(GLFW_LIBRARY
  NAMES "glfw"
)

if(NOT TARGET GLFW)
  add_library(GLFW SHARED IMPORTED GLOBAL)
  set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION "${GLFW_LIBRARY}")
  set_target_properties(GLFW PROPERTIES INCLUDE_DIRECTORIES "${GLFW_INCLUDE}")
endif()