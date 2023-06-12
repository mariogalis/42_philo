# Dining Philosophers 42_philo
This repository contains a C program that solves the Dining Philosophers Problem using mutexes. The program simulates a scenario where a number of philosophers sit around a table and try to eat using forks. The goal is to prevent deadlocks and ensure that each philosopher can eat without causing conflicts with others.
<p align="center">
<img src="https://cdn.battlefy.com/blog/5f5978933ed49802100b173d26a8eee0c0c60d68cacac0e26598f47b108ad9da.jpeg" width="400" height="250">
</p>

## Introduction
### Data Races and Concurrent Programming
In *concurrent programming*, data races occur when two or more threads access shared data concurrently, and at least one of them performs a write operation. These races can lead to unexpected and non-deterministic behavior, such as incorrect results or program crashes.

To address data races and ensure correct synchronization, various synchronization mechanisms can be used. One such mechanism is the mutex, short for "mutual exclusion." A mutex allows multiple threads to access a shared resource safely by enforcing mutual exclusion. When a thread acquires a mutex, it gains exclusive access to the protected resource. Other threads trying to acquire the mutex will be blocked until it is released.

The Dining Philosophers Problem is a classic synchronization problem that illustrates the challenges of concurrent programming. It involves a group of philosophers sitting at a table with a bowl of rice and chopsticks (forks) placed between each pair of philosophers. The philosophers alternate between thinking and eating. However, to eat, a philosopher needs to acquire both the left and right chopsticks. The problem arises when all philosophers simultaneously pick up their left chopstick, leaving them unable to acquire the right one, resulting in a deadlock.

To solve this problem, we can introduce a mutex for each fork and impose some rules to prevent deadlocks. One common solution is to use a semaphore or mutex to represent each chopstick and allow philosophers to acquire both chopsticks only if they are available. By ensuring that each philosopher picks up the chopsticks in a consistent order, we can avoid deadlocks.

## Program Usage
To compile and execute the program, follow these steps:

- Ensure that you have a C compiler installed on your system (e.g., GCC).

- Clone this repository to your local machine:

```shell

$ git clone https://github.com/your-username/dining-philosophers.git
```
-Change to the project directory:

```shell
$ cd dining-philosophers
```
-Compile the program using the provided Makefile:

```shell
$ make
````

- Run the program with the desired parameters:

```shell
$ ./philo <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <times_to_eat>
```
- Replace <num_philosophers> with the number of philosophers at the table.

- Replace <time_to_die>, <time_to_eat>, and <time_to_sleep> with the respective time intervals in milliseconds.

- Replace <times_to_eat> with the number of times each philosopher must eat before the program ends.

For example, to simulate 5 philosophers with the following time intervals:

Time to die: 400 ms
Time to eat: 400 ms
Time to sleep: 600 ms
Times to eat: 3
Execute the following command:
```shell
$ ./philo 5 400 400 600 3
```
Observe the output to see the philosophers' actions and the program's behavior.

Press Ctrl+C to stop the program.

<img width="449" alt="Screenshot 2023-06-11 at 13 55 20" src="https://github.com/mariogalis/42_philo/assets/44349256/634a31c8-f17b-4281-b67a-ecca9d839d3d">



## License
This project is written by me so feel free to use it as a guide of your own proyect!!
