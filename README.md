# Duke Nukem Zero Hour N64
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


## Tools

 - [asm-differ](https://github.com/simonlindholm/asm-differ); rapidly diff between source/target assembly
 - [decomp-permuter](https://github.com/simonlindholm/decomp-permuter); tweaks code, rebuilds, scores; helpful for weird regalloc issues
 - [mips2c](https://github.com/matt-kempster/mips_to_c); assembly to C code translator
 - [splat](https://github.com/ethteck/splat); successor to n64split