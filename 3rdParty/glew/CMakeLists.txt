# --- Supremacy/3rdParty/glew/CMakeLists.txt ---

set(GLEW_INCLUDE CACHE PATH "")

find_library(GLEW_LIBRARY
  NAMES "glew" "GLEW32" "GLEW"
)

if (NOT TARGET GLEW)
  add_library(GLEW STATIC IMPORTED GLOBAL)
  set_target_properties(GLEW PROPERTIES IMPORTED_LOCATION "${GLEW_LIBRARY}")
  set_target_properties(GLEW PROPERTIES INCLUDE_DIRECTORIES "${GLEW_INCLUDE}")
endif()