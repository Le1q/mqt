@echo off
set CLANG_FORMAT="C:\Program Files\LLVM\bin\clang-format.exe"
for /R %%f in (*.cpp *.h) do (
    %CLANG_FORMAT% -i "%%f"
)
echo All files formatted.