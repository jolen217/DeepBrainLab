#!/bin/sh
cmake -H. -Bbuild
cmake --build build -- -j3
