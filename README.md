# Pipex

## Description
The Pipex project is a simplified re-implementation of the shell pipeline functionality in C. It allows you to execute two commands in a sequence, where the output of the first command is passed as input to the second command, mimicking the behavior of `command1 | command2`. The project uses system calls such as `pipe`, `fork`, `dup2`, and `execve` to create this pipeline.

## Features
- **Pipeline Execution**: Executes two commands in sequence using pipes.
- **Error Handling**: Manages errors related to file access and command execution.
- **Custom Path Resolution**: Dynamically finds the full path of a command based on the `PATH` environment variable.

## File Structure
- **`pipex.c`**: The main file that initializes the pipeline and handles the program's flow.
- **`handle_commands.c`**: Contains the functions that execute the first and second commands, handling the pipeline logic.
- **`pipex.h`**: Header file that defines the structures and function prototypes used throughout the project.
- **`makefile`**: Automates the compilation process, including building the project and cleaning up generated files.
- **`input.txt`**: Example input file for testing.
- **`output.txt`**: Example output file where the results of the pipeline are written.
- **`LIBFT/`**: Directory containing the `libft` library, which provides additional helper functions.

## Getting Started
To compile and run the project, follow the instructions below.

### Prerequisites
- GCC compiler
- Make utility

### Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/pipex
    cd pipex
    ```
2. Ensure that the `LIBFT` directory is present. If not, clone the `libft` repository:
    ```bash
    git clone https://github.com/your-username/libft LIBFT
    ```
3. Compile the project using the provided Makefile:
    ```bash
    make
    ```

### Usage
Once compiled, you can run the Pipex program using the following syntax:

```bash
./pipex input.txt "command1" "command2" output.txt
