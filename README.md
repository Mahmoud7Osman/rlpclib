## Overview

The RLPC (Remote/Local Procedure Calls) library facilitates communication between different processes with varying memory management approaches. It enables seamless interaction between processes written in different programming languages, allowing functions to be called remotely and returning values back to the caller. RLPC follows a caller and callee approach, providing flexibility and compatibility across diverse environments.

## Repository Structure

- **src/:** Contains the source code of the RLPC library.
- **releases/:** Holds release binaries for Windows and Linux platforms.
- **integrations/:** Provides pre-made integration code snippets for various programming languages.

## Library Usage

### Loading the Library

Before using RLPC in a program, the library must be loaded into each process

### Compatibility

RLPC is written in C to ensure compatibility with a wide range of programming languages and systems. Its design allows integration into applications developed in different languages, promoting interoperability.

## Functionality

### `struct bridge_t* init_bridge(char* ip, int port, char* eip, int eport);`

- **Arguments:**
  - `ip`: IP address to be used as an Entry Point For The Current Running Process.
  - `port`: Port number of the RLPC Bridge Of the current process.
  - `eip`: IP address of the endpoint process.
  - `eport`: Port number of the RLPC Bridge endpoint.

- **Description:**
  Initializes the RLPC bridge, creating a UDP Stream between the callee and caller.

- **Returns:**
  A pointer to the initialized `struct bridge_t` if successful, or NULL on failure.

### `char *function_call(struct bridge_t*, char*, char*);`

- **Arguments:**
  - `bridge`: Pointer to the RLPC bridge.
  - `fname`: Name of the function to call.
  - `args`: Arguments to pass to the function.

- **Description:**
  Initiates a function call from the RLPC caller to the callee, passing function name and arguments.

- **Returns:**
  Pointer to the buffer containing the function call result.

### `char *fcall_receiver(struct bridge_t*);`

- **Arguments:**
  - `bridge`: Pointer to the RLPC bridge.

- **Description:**
  Receives a function call on the RLPC callee side, retrieving function name and arguments.

- **Returns:**
  Pointer to the buffer containing the received function call.

### `void fcall_return(struct bridge_t*, void*, int32_t);`

- **Arguments:**
  - `bridge`: Pointer to the RLPC bridge.
  - `buffer`: Pointer to the buffer containing the function call result.
  - `size`: Size of the buffer.

- **Description:**
  Sends the function call result back to the RLPC caller.

### `void close_bridge(struct bridge_t*);`

- **Arguments:**
  - `bridge`: Pointer to the RLPC bridge to close.

- **Description:**
  Closes the RLPC bridge, freeing allocated resources.

## Integrations

Developers can leverage the integrations provided in the `integrations/` folder to seamlessly integrate RLPC into their projects. These pre-made codes simplify the process of integrating RLPC into applications developed in various programming languages, reducing development effort and time.

## Conclusion

The RLPC library facilitates communication between processes with different memory management approaches, enabling interoperability across diverse environments. With its caller and callee approach, RLPC promotes flexibility and compatibility, allowing functions to be called remotely and returning values back to the caller seamlessly. Developers can rely on RLPC to build robust and interoperable systems across different programming languages and platforms.
