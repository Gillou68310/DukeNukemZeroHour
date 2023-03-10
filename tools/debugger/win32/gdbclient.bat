tools\debugger\win32\gdb-multiarch-9.2\bin\gdb-multiarch.exe ^
-iex "set architecture mips:4300" ^
-iex "file build/dukenukemzerohour.elf" ^
-iex "target remote :4600"