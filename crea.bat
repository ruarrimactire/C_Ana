rem : da usare con run -> "$(NPP_DIRECTORY)\..\crea.bat" "$(FULL_CURRENT_PATH)"

cd %~p1
gcc %1 -o %1.exe
cmd /K %1.exe
rem %1.exe
