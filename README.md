# ccwc-cpp

A small C++ command-line implementation inspired by the Unix `wc` utility. It reads from a file or standard input and reports byte, line, word, and ASCII character counts.

## Supported options

| Option | Behaviour |
|---|---|
| `-c` | Count bytes |
| `-l` | Count lines |
| `-w` | Count whitespace-delimited words |
| `-m` | Count characters for ASCII input |
| no option | Print line, word, and byte counts |

The current `-m` implementation is ASCII-oriented; for non-ASCII UTF-8 input it counts bytes rather than Unicode code points.

## Build

Requires a C++ compiler with C++17 support.

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o ccwc
```

Or use the included Makefile:

```bash
make
```

## Usage

```bash
# Read a file
./ccwc -w sample.txt
./ccwc -l sample.txt
./ccwc -c sample.txt

# Read standard input
printf "one two\nthree\n" | ./ccwc -w
printf "one two\nthree\n" | ./ccwc -l
printf "one two\nthree\n" | ./ccwc
```

## Scope

This project focuses on command-line argument handling, file streams, standard input, and basic text processing in C++.
