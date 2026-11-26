# Simple Shell — Holberton School

A C-based command-line shell exercise developed as part of the Holberton School curriculum.

## Implementation overview

The current source includes an interactive input loop, tokenization, command dispatch, PATH lookup, environment display, process creation with `fork()`, program execution with `execve()`, and child-process waiting. The implementation also contains helper functions for string handling and memory cleanup.

## Source layout

The repository separates the shell entry point (`start.c`), input handling, tokenization, PATH resolution, command dispatch, built-ins, string helpers and memory-management helpers. See `shell.h` for the shared function declarations.

## Limitations and verification

This is historical coursework, not a production shell. Review the implementation and task requirements before relying on behavior such as environment propagation, signal handling, quoting, redirection, pipes or job control. No production-readiness claim is made.

## Contributors

See [`AUTHORS`](AUTHORS) for the repository's contributor record.