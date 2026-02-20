# Pipex

A C program that replicates how the shell pipes one command into another, reading from a file and writing the final output to another file.

## Features

- Connects two shell commands through a pipe, just like `cmd1 | cmd2` in a shell
- Reads input from a file and writes the final result to an output file
- Resolves command paths automatically from the environment's `PATH`
- Handles errors for missing files, bad commands, and failed system calls

## Getting Started

```bash
git clone https://github.com/tohmeh/Pipex
cd Pipex
make
./pipex input.txt "command1" "command2" output.txt
```

Example:

```bash
./pipex input.txt "cat" "wc -l" output.txt
```

## Project Structure

```
Pipex/
├── pipex.c             # Entry point and path resolution
├── handle_commands.c   # Fork and exec logic for both commands
├── pipex.h             # Structs and function prototypes
├── makefile            # Build rules
└── LIBFT/              # Supporting C library
```

## License

This project has no license file.
