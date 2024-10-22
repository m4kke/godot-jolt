call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cd C:\GitProjects\godot-jolt

cmake --preset windows-msvc-x64

cmake --build --preset windows-msvc-x64-editor-distribution

cmake --install build/windows-msvc-x64 --config EditorDistribution --prefix "C:\Work\flood"
