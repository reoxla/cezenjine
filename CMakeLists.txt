# CMakeList.txt: Üst düzey CMake proje dosyası, genel yapılandırma gerçekleştirin
# ve alt projeleri buraya ekleyin.
#
cmake_minimum_required (VERSION 3.10)

# Destekleniyorsa MSVC derleyicileri için Çalışırken Yeniden Yükleme aracını etkinleştirin.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("cezenjine")

file(GLOB_RECURSE cez_resources
"cezenjine/*.cpp"
"cezenjine/*.h"
)

include(FetchContent)

# 2. Declare raylib dependency
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip
)

# Optional: Disable raylib examples/tests to speed up compilation
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

# 3. Create your C++ executable
add_executable(cezenjineExe ${cez_resources})

# 4. Link raylib to your target
target_link_libraries(cezenjineExe PRIVATE raylib)
