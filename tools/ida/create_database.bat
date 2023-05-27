REM wsl "tools/ida/ida_context.py"
docker --context=desktop-linux-mutagen run --rm --mount src=%cd%,target=/dukenukemzerohour,type=bind dukenukemzerohour "tools/ida/ida_context.py"
START /B ida.exe -c -T"DUKE NUKEM ZERO HOUR" -S"tools\ida\import_symbols.py" baserom.us.z64