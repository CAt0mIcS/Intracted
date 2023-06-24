set(SRC
	HTML/HTMLLexer.h
	HTML/HTMLLexer.cpp
	HTML/HTMLParser.h
	HTML/HTMLParser.cpp
	HTML/HTMLTokens.h

	CSS/CSSLexer.h
	CSS/CSSLexer.cpp
	CSS/CSSParser.h
	CSS/CSSParser.cpp
	CSS/CSSTokens.h

	pch.h
)

set(PRIVATE_INC
	"${CMAKE_CURRENT_SOURCE_DIR}/../"
)

set(PRIVATE_LIB
	""
)

# ------------------------------------------------------------------
# Setup
add_library("WebsiteParser" SHARED "${SRC}")
target_include_directories("WebsiteParser" PRIVATE "${PRIVATE_INC}")
target_link_libraries("WebsiteParser" PRIVATE "${PRIVATE_LIB}")
target_precompile_headers("WebsiteParser" PRIVATE "pch.h")

AddRecursiveFilters("${SRC}")
SetOutputDirectory("WebsiteParser" "")