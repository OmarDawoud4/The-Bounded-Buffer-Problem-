# The-Bounded-Buffer-Problem-


This project implements a solution to the classic **Bounded Buffer Problem** also known as Producer Consumer Problem using **POSIX threads**, **semaphores**, and **mutexes** in C. The producer and consumer threads share a fixed -size buffer, with synchronization achieved through semaphores and mutexes to prevent race conditions.the infinite loop to simulate a server -client scenario, the consumer consumes the items in Last in First out manner (simulating a stack ).
![Screenshot 2024-10-27 235349](https://github.com/user-attachments/assets/7ed227d8-dde4-47d3-9b58-a75c14c9db26)

## Features

- **Multi-threaded Synchronization:** Ensures thread-safe access to the buffer using mutex locks.
- **Semaphore Control:** Uses semaphores to manage full and empty slots in the buffer.
- **Checking Buffer Status :** to display the current buffer status.

## Project Structure

- **`producer.c`**: Contains the `producer` function, which generates and adds items to the shared buffer.)
- **`consumer.c`**: Contains the `consumer` function, which removes and processes items from the buffer.
- **`utils.c`**: Contains the `display_buffer_status` function to print the buffer's current status.
- **`main.c`**: Initializes semaphores, mutexes, and threads, and starts the producer and consumer operations.
- **`shared.h`**: Header file containing shared definitions, constants, and function prototypes.

## Compilation

To compile the project, use  in a terminal:

```bash
gcc main.c producer.c consumer.c display_buffer_status.c -o p_c -lpthread
