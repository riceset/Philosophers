<h1 align="center">
	philosophers
</h1>

<p align="center">
  <img src="https://github.com/riceset/riceset/blob/main/42_badges/philosopherse.png" alt="Philosophers 42 project badge"/>
</p>

## Summary
> <i>Philosophers is a 42 school project designed around Edsger Dijkstra's famous dining philosophers problem. For this project, we must learn about concurrent</i>
> <i>programming. For the project's mandatory part, we must find a solution to the problem using only threads and mutexes. For the bonus part, we must create a second</i>
> <i>program that uses processes and semaphores.</i>

## The Diner Structure

```mermaid
flowchart TB
    A[("Dinner")]
    B{"Forks"}
    C("Supervisor")
    D{"Stop"}
    E("Exit Status")

    A --- B
    A --- C
    A --- D
    A --- E

    subgraph Rules
		R0("Start Time")
        R1("Philosopher Count")
        R2("Philosopher Lifespan")
        R3("Dining Duration")
        R4("Rest Duration")
        R5("Minimal Meals Count")
    end

    A --- Rules

    subgraph Philosopher
        D0("ID")
        D1("Thread")
        D2("Left Fork")
        D3("Right Fork")
        D4{"Times Eaten"}
        D5{"Last Meal Time"}
    end

    A --- Philosopher

    %% Clarifying relationships
    Philosopher -->|accesses| B
```
