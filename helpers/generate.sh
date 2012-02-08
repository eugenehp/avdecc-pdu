#! /bin/bash -e

python ./generate.py
astyle --style=allman -s4 -S -E -U -P -f *.h *.c
rm -f *.orig

