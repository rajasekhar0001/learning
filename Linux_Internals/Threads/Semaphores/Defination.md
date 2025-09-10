A semaphore is a synchronization object that controls access to shared resources by using a counter.
    -> it is a kind of signaling mechanism.

There are two main types:
    1) Binary semaphore (similar to a mutex, only 0 or 1 allowed).
    2) Counting semaphore (counter can be >1, controls access to multiple resource instances).

🔹 Why Semaphores over other primitives?
    Compared to other synchronization primitives:

    => Versus Mutex:
        -> A mutex only provides exclusive locking (1 thread at a time).
        -> A semaphore (counting) can allow multiple threads (up to the count) to access a resource simultaneously.
        -> Mutexes are usually “ownership-based” (the thread that locks must unlock). Semaphores are not strictly ownership-bound.

    => Versus Condition Variables:
        -> Condition variables require an associated mutex and are mainly for signaling state changes.
        -> Semaphores can directly handle signaling and counting in one primitive.