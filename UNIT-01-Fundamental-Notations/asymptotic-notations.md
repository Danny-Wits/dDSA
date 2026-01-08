
# Time & Space Complexity and Asymptotic Notation

This file explains how algorithm efficiency is analyzed in terms of
**execution time**, **memory usage**, and **growth rate** as input size increases.

The focus is on **how fast time increases**  and **how much memory is used** relative to input size.

## Time Complexity

Time complexity describes how the running time of an algorithm grows
with respect to input size `n`.

It focuses on **how fast time increases**, not exact execution time.

### Examples

```cpp
// O(1) – Constant time
int x = arr[0];

// O(n) – Linear time
for (int i = 0; i < n; i++) {
    sum += arr[i];
}

// O(n^2) – Quadratic time
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        count++;
    }
}
```

## Space Complexity

Space complexity measures the **extra memory** used by an algorithm
relative to input size.

It includes:

* Temporary variables
* Dynamic allocations
* Recursion stack space

### Examples

```cpp
// O(1) – Constant space
int a, b;

// O(n) – Linear space
int* arr = new int[n];

// O(n) – Recursive stack
void func(int n) {
    if (n == 0) return;
    func(n - 1);
}
```

---

## Asymptotic Analysis

Asymptotic analysis studies algorithm behavior as `n → ∞`.

It ignores:

* Constant factors
* Lower-order terms
* Hardware and compiler differences

## Asymptotic Notations

### Big-O Notation — O(f(n))

Represents the **upper bound** (worst-case growth).

```cpp
// O(n)
for (int i = 0; i < n; i++) {
    work();
}
```

---

### Big-Ω Notation — Ω(f(n))

Represents the **lower bound** (best-case growth).

Example:

* Linear search best case → Ω(1)

---

### Big-Θ Notation — Θ(f(n))

Represents the **tight bound** (exact growth).

Example:

* Binary search → Θ(log n)

---

## Ignoring Constants and Lower-Order Terms

```text
O(5n + 20)  →  O(n)
O(n^2 + n)  →  O(n^2)
O(100)      →  O(1)
```

---

## Common Time Complexities

| Complexity | Description  |
| ---------- | ------------ |
| O(1)       | Constant     |
| O(log n)   | Logarithmic  |
| O(n)       | Linear       |
| O(n log n) | Linearithmic |
| O(n²)      | Quadratic    |
| O(2ⁿ)      | Exponential  |

> Note: Asymptotic notation is a generalization of time and space complexity.
