set(SRC
	Window/Window.h
	Window/Window.cpp

	pch.h
)

#set(MODULE_SRC
#	""
#)

set(PRIVATE_INC
	"${CMAKE_CURRENT_SOURCE_DIR}/../"
)

set(PRIVATE_LIB
	""
)

# ------------------------------------------------------------------
# Setup
add_executable("Intracted")
target_sources("Intracted" PUBLIC "${SRC}")
# target_sources("Intracted" PUBLIC FILE_SET all_my_modules TYPE CXX_MODULES FILES "${MODULE_SRC}")

target_include_directories("Intracted" PRIVATE "${PRIVATE_INC}")
target_link_libraries("Intracted" PRIVATE "${PRIVATE_LIB}")
target_precompile_headers("Intracted" PRIVATE "pch.h")

AddRecursiveFilters("${SRC}")
AddRecursiveFilters("${MODULE_SRC}")
SetOutputDirectory("Intracted" "")