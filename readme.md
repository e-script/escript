# Escript

## Introduction
Escript is a scripting language which will support oop but much simpler and has no keyword

## Current supported platform
* Linux 64-bit

## Installation
1. Download latest release at here: [Releases](https://github.com/chientranse/escript/releases)
2. Extract:

    `tar -xzvf escript-v0.0.11.tar.gz`

3. Copy escript to /usr/local/bin:
    
    `sudo cp dist/Release/GNU-Linux/escript /usr/local/bin/`

3. To run the script `samples/sample0.e`:

    `escript samples/sample0.e`

## Samples

* sample0.e

    ```
    a = 5
    b = 6
    c = 100
    d = 99
    result = a + b + c * d
    ```

* sample1.e
* sample2.e