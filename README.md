# ccwc-cpp

<p>
  <img src="https://img.shields.io/github/actions/workflow/status/SSRINIBASS/ccwc-cpp/ci.yml?branch=main&style=for-the-badge&label=Build%20%26%20Smoke%20Tests"/>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Standard-C%2B%2B17-00599C?style=for-the-badge"/>
</p>

<p>
  <a href="https://skillicons.dev"><img src="https://skillicons.dev/icons?i=cpp,cmake,linux,vscode&perline=4" alt="ccwc-cpp toolchain icons"/></a>
</p>

A small C++ command-line implementation inspired by the Unix `wc` utility. It reads from a file or standard input and reports byte, line, word, and ASCII character counts.

## 🎛️ Supported options

| Option | Behaviour |
|---|---|
| `-c` | Count bytes |
| `-l` | Count lines |
| `-w` | Count whitespace-delimited words |
| `-m` | Count characters for ASCII input |
| no option | Print line, word, and byte counts |

The current `-m` implementation is ASCII-oriented; for non-ASCII UTF-8 input it counts bytes rather than Unicode code points.

## 🔧 Build

Requires a C++ compiler with C++17 support.

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o ccwc
```

Or use the included Makefile:

```bash
make
```

## ▶️ Usage

```bash
# Read a file
./ccwc -w sample.txt
./ccwc -l sample.txt
./ccwc -c sample.txt

# Read standard input
printf "one two\\nthree\\n" | ./ccwc -w
printf "one two\\nthree\\n" | ./ccwc -l
printf "one two\\nthree\\n" | ./ccwc
```

## 🎯 Scope

This project focuses on command-line argument handling, file streams, standard input, and basic text processing in C++.
