# 🧮 ccwc – Custom Word Count Tool in C++

A C++ implementation of the classic Unix `wc` command, built as part of the [CodingChallenges.fyi](https://codingchallenges.fyi/challenges/challenge-wc/) project series.

This tool mimics the behavior of `wc`:

- Reads from a file or standard input
- Supports common flags (`-c`, `-l`, `-w`, `-m`)
- Provides default behavior when no flag is given

---

## ✨ Features

| Flag | Description                      |
|------|----------------------------------|
| `-c` | Count bytes                      |
| `-l` | Count lines                      |
| `-w` | Count words                      |
| `-m` | Count characters (ASCII only)    |
| none | Show lines, words, bytes (default) |

- ✅ Handles file input: `./ccwc -w file.txt`
- ✅ Handles `stdin`: `echo "hello" \| ./ccwc -w`
- ✅ Includes a `Makefile` for easy building

---

## 💻 How to Run on Your Device

### 1. 🔧 Requirements

- C++ compiler (e.g., `g++`)
- Terminal (Command Prompt, PowerShell, Git Bash, or WSL)
- Optional: `make` utility for using the Makefile

### 2. 📦 Compile the Code

Option A — Manual compile:

```bash
g++ main.cpp -o ccwc
```

Option B — Using the Makefile:

```bash
make        # Builds ccwc
make clean  # Cleans up the compiled binary
```

## 🚀 Usage Examples

```bash
# File input
./ccwc -c test.txt     # Byte count
./ccwc -l test.txt     # Line count
./ccwc -w test.txt     # Word count
./ccwc -m test.txt     # Character count
./ccwc test.txt        # Show all: lines, words, bytes

#Standard Input (stdin)
echo "hello world" | ./ccwc -w     # Output: 2
echo "line1\nline2" | ./ccwc -l    # Output: 2
echo "abc" | ./ccwc -c             # Output: 4
echo "one two three" | ./ccwc      # Output: 1 3 14
```
