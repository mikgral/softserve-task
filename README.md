# Introduction

This is a repository that contains example of building Conda package with C++ and CMake.

# Build

Just run:

`
conda build .
`

You might need to add a channel that contains Boost library:

`
conda config --add channels conda-forge
`

# How to use it

Once built project is running, connect with it using:

`
telnet 0.0.0.0 1234
`

and type `ping` to receive a message back `pong`.
