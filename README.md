# 🧩 push_swap

> A sorting algorithm challenge from **42 School** — implemented entirely in **C**, under strict operational constraints.

---

## 🧠 Overview
`push_swap` is a program that sorts a stack of integers using **two stacks (A and B)** and a **limited set of operations**.  
The challenge lies in **minimizing the number of moves**, pushing algorithmic efficiency and optimization to the limit.

---

## ⚙️ Implementation Details
My approach focused on **cost-based optimization** — for each element, I computed the number of operations needed to move it to the correct position, then executed the minimal-cost path.  
This hybrid strategy allowed the program to achieve:

- 🏅 **5/5** performance score (100 numbers)  
- 🥈 **4/5** performance score (500 numbers)

---

## 🔄 Available Operations

| Operation | Description |
|------------|-------------|
| `sa`, `sb`, `ss` | Swap top elements of A, B, or both |
| `pa`, `pb` | Push from one stack to another |
| `ra`, `rb`, `rr` | Rotate stack(s) upwards |
| `rra`, `rrb`, `rrr` | Rotate stack(s) downwards |

---

## 🧩 Key Idea
The algorithm combines:
- **Greedy insertion sorting**  
- **Rotation cost balancing**  
- **Simultaneous stack movement** (`rr` and `rrr` optimizations)

---

## 📎 Resources
- [Algorithm's logic](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Tester by gemartin](https://github.com/gemartin99/Push-Swap-Tester)
