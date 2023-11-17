tools\debugger\win32\gdb-multiarch-9.2\bin\gdb-multiarch.exe ^
-iex "set architecture mips:4300" ^
-iex "set height 0" ^
-iex "set logging on" ^
-iex "file build/dukenukemzerohour.elf" ^
-iex "target remote :4600"