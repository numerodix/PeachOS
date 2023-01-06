#/bin/bash
export PREFIX="$HOME/tmp/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
make all
