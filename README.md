# Pipex Project Checklist

## 📝 General Guidelines
- [✅] Ensure the project is written in C and adheres to the 42 Norm.
- [ ] Avoid unexpected quits (e.g., segmentation fault, bus error, double free).
- [ ] Handle memory management properly to avoid leaks.
- [✅] Create and test a Makefile:
  - [✅] Includes `NAME`, `all`, `clean`, `fclean`, and `re` rules.
  - [✅] Uses `cc` with `-Wall`, `-Wextra`, and `-Werror` flags.
  - [✅] Does not relink unnecessarily.
- [ ] Submit all required files: `Makefile`, `.c` files, `.h` files.
- [✅] Test thoroughly to ensure compliance with requirements.

## 🔨 Mandatory Part Implementation

### 1️⃣ Understand Requirements
- [ ] Program must be executable as: `./pipex file1 cmd1 cmd2 file2`.
- [ ] Simulate the shell command: `< file1 cmd1 | cmd2 > file2`.
- [ ] Use only the allowed functions:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.

### 2️⃣ Program Structure
- [ ] Parse command-line arguments:
  - [ ] Validate the number of arguments.
  - [ ] Extract `file1`, `file2`, `cmd1`, and `cmd2`.
- [ ] Handle file operations:
  - [ ] Open `file1` for reading.
  - [ ] Open or create `file2` for writing with proper permissions.
  - [ ] Handle errors during file operations (e.g., file not found, permission denied).
- [ ] Create a pipeline:
  - [ ] Use `pipe()` to set up communication between commands.
  - [ ] Fork processes for `cmd1` and `cmd2`.
  - [ ] Redirect:
    - `cmd1`'s `stdin` from `file1` and `stdout` to the pipe.
    - `cmd2`'s `stdin` from the pipe and `stdout` to `file2`.
- [ ] Execute commands using `execve()`:
  - [ ] Parse commands and their arguments.
  - [ ] Handle command not found or execution errors.
- [ ] Manage file descriptors:
  - [ ] Close unused descriptors in child processes.
  - [ ] Ensure descriptors are closed after use in the parent process.

### 3️⃣ Error Handling
- [ ] Check return values of all system calls.
- [ ] Print meaningful error messages using `perror()` or custom messages.
- [ ] Ensure the program exits gracefully on errors.

### 4️⃣ Memory Management
- [ ] Allocate memory carefully for dynamic operations.
- [ ] Free all allocated memory in error cases and upon program termination.

### 5️⃣ Testing
- [ ] Test various valid cases:
  - Example: `./pipex infile "ls -l" "wc -l" outfile`.
  - Example: `./pipex infile "grep a1" "wc -w" outfile`.
- [ ] Test edge cases:
  - Invalid files (`infile` not found, `outfile` permission denied).
  - Invalid commands (`cmd1` or `cmd2` not found).

## 🌟 Bonus Part (Optional)
- [ ] Implement multiple commands (e.g., `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`).
  - Simulate shell behavior: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`.
- [ ] Add support for `here_doc` syntax:
  - Example: `./pipex here_doc LIMITER cmd cmd1 file`.
  - Simulate: `cmd << LIMITER | cmd1 >> file`.

## 📚 Submission
- [ ] Verify all required files are in the repository.
- [ ] Double-check filenames and structure for correctness.
- [ ] Ensure the mandatory part is perfect before submitting bonuses.
- [ ] Use tests to defend your project during evaluations.

## ✅ Final Checklist
- [✅] Compile with `make` and ensure no errors or warnings.
- [ ] Pass all tests for the mandatory part.
- [ ] Bonus features work without breaking mandatory functionality.
- [ ] Submit to the git repository before the deadline.
