# Duke Nukem Zero Hour N64 [![Build Status]][actions] ![Code Progress] ![Bytes Progress]

[Build Status]: <https://github.com/Gillou68310/DukeNukemZeroHour/actions/workflows/ci.yml/badge.svg>
[actions]: <https://github.com/Gillou68310/DukeNukemZeroHour/actions/workflows/ci.yml>
[Code Progress]: https://img.shields.io/endpoint?label=Code%20US&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fdukezh%2Fus%2Fdefault%2F%3Fmode%3Dshield%26measure%3Dfuncs
[Bytes Progress]: https://img.shields.io/endpoint?label=Bytes%20US&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fdukezh%2Fus%2Fdefault%2F%3Fmode%3Dshield%26measure%3Dbytes

A WIP decompilation of Duke Nukem Zero Hour (US) for N64.

Note: To use this repository, you must already own a copy of the game.

## Dependencies

The build instructions assume that you will be using Ubuntu 20.04; either natively or via WSL2.

Package requirements can be install via:

```sh
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu cpp-mips-linux-gnu python3 python3-pip
```

Tools requires Python 3.8+. Package requirements can be installed via:

```sh
pip3 install --upgrade pip
pip3 install -r requirements.txt
```

## Building

Clone the repository; note the --recursive flag to fetch submodules at the same time:

```sh
git clone https://github.com/Gillou68310/DukeNukemZeroHour.git --recursive
```

Navigate into the freshly cloned repo

```sh
cd DukeNukemZeroHour
```

Place the Duke Nukem Zero Hour US ROM in the root of this repository, name it baserom.us.z64, and then run the first make command to extract the ROM:

```sh
make setup
```

Now build the ROM:

```sh
make --jobs
```

If you did everything correctly, you'll be greeted with the following:

```sh
Creating z64: build/dukenukemzerohour.z64
OK
```

### Building NON_MATCHING Version

Functions can be decompiled to a state where they are functionally equivalent, but are not a byte-perfect match.
In order to build/test the non-matching, add NON_MATCHING=1 argument to the make commands.

## Docker

A Docker image containing all dependencies can be built and ran as follows:
```sh
docker build --no-cache . -t dukenukemzerohour
docker run --rm -ti --mount src=$(pwd),target=/dukenukemzerohour,type=bind dukenukemzerohour
```

Then continue with [the building instructions](#Building)

When binding windows or mac folder I strongly recommand installing [Mutagen Extension for Docker Desktop](https://mutagen.io/documentation/docker-desktop-extension).
```sh
docker --context=desktop-linux-mutagen run --rm -ti --mount src=$(pwd),target=/dukenukemzerohour,type=bind dukenukemzerohour
```

## Debugging

Game can be debugged with gdb through mupen64plus (Windows only for now).
In order to have source code information the game should be compiled with modern gcc by adding MODERN=1 to the make command.

Run the gdb server in cmd:

```sh
tools\debugger\win32\gdbserver.bat
```

Then run the gdb client in cmd:

```sh
tools\debugger\win32\gdbclient.bat
```

It's also possible to debug within vscode with the [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug) extension.

Run the gdb server in cmd:

```sh
tools\debugger\win32\gdbserver.bat
```

Then run the "GDB Client(Win32)" configuration in vscode.

## Tools

 - [asm-differ](https://github.com/simonlindholm/asm-differ); rapidly diff between source/target assembly
 - [decomp-permuter](https://github.com/simonlindholm/decomp-permuter); tweaks code, rebuilds, scores; helpful for weird regalloc issues
 - [mips2c](https://github.com/matt-kempster/mips_to_c); assembly to C code translator
 - [splat](https://github.com/ethteck/splat); successor to n64split