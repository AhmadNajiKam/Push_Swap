# 🌪️ Push_Swap: Sorting the Unsortable

Welcome to **Push_Swap**, where we take a chaotic pile of numbers and meticulously organize them using two stacks, a highly restricted set of operations, and an unhealthy amount of caffeine. 

The goal? Sort the numbers in Stack A in ascending order with the absolute minimum number of moves. Arrays are banned (by us ofc), efficiency is everything, and the checker is unforgiving.

---

## 🚀 Instructions

### 🛠️ Bringing it to Life (Compilation)

Summon the executable using the `Makefile`:
```bash
make

```

Purge the object files (keep your workspace clean):

```bash
make clean
make fclean

```

### 🎮 Running the Program (Execution)

Feed the beast a list of integers:

```bash
./push_swap 42 13 99 -5 0

```

**The Ultimate Vibe Check:**
Pipe your output into the OS checker to see if you actually sorted it or just shuffled it into a new disaster:

```bash
./push_swap 42 13 99 -5 0 | ./checker_os 42 13 99 -5 0

```

* ✨ **OK** → Big brain energy. You survived.
* 💥 **KO** → Back to the drawing board. Don't look at the norminette right now, it can smell fear.

---

## 🕹️ The Control Panel (Allowed Operations)

We only have two stacks (`A` and `B`) and a few highly specific moves to sort our mess.

| Command | Action | Code Functions
| --- | --- | --- |
| **`sa`** | 🔀 Swap the top two elements of Stack A | called `swap` in our code
| **`sb`** | 🔀 Swap the top two elements of Stack B | called `swap` in our code
| **`ss`** | 🔀 `sa` and `sb` at the exact same time | called `swap_both` in our code
| **`pa`** | 📥 Pop from B and Push to the top of A | called `push_a` in our code
| **`pb`** | 📤 Pop from A and Push to the top of B | called `push_b` in our code
| **`ra`** | 🎡 Rotate Stack A (top element goes to the bottom) | called `shift_up` in our code
| **`rb`** | 🎡 Rotate Stack B (top element goes to the bottom) | called `shift_up` in our code
| **`rr`** | 🎡 `ra` and `rb` simultaneously | called `shift_up_both` in our code
| **`rra`** | 🎢 Reverse rotate Stack A (bottom element goes to the top) | called `shift_down` in our code
| **`rrb`** | 🎢 Reverse rotate Stack B (bottom element goes to the top) | called `shift_down` in our code
| **`rrr`** | 🎢 `rra` and `rrb` simultaneously | called `shift_down_both` in our code

---

## Description

## 🏗️ Architecture: Why Linked Lists?

Since contiguous memory (arrays) is strictly forbidden by the subject, we built our stacks using **Linked Lists**.

```c
typedef struct s_list
{
    int             content;
    int             index;
    int             pos;
    struct s_list  *next;
    struct s_list  *prev;
}   t_list;

```

* **Pros:** Dynamic sizing, easy to push/pop, no annoying reallocations.
* **Cons:** Traversing takes $O(n)$, and memory management requires strict discipline (we check our `malloc`s around here).

---

## 🧠 The Brains of the Operation (Algorithms)

You can't use one algorithm to rule them all. What works for 5 numbers is a disaster for 500. We divided our strategy into three distinct tiers:

### 🥉 The "Keep It Simple" Protocol (Selection Sort)

* **Target:** Tiny inputs (≤ 5 numbers).
* **How it works:** Scan Stack A for the absolute minimum value, push it to Stack B. Repeat until Stack A is empty, then push everything back.
* **The Verdict:** It's practically brute force, but for less than 5 numbers, it guarantees an incredibly low operation count.

### 🥈 The "Divide and Conquer" Tactic (Chunk Sort)

* **Target:** Medium inputs (up to ~500 numbers).
* **How it works:** We group the numbers into dynamic "chunks" based on their values. We toss these chunks over to Stack B, essentially pre-sorting them into rough segments. Then, we intelligently pull the largest numbers back to Stack A one by one.
* **The Verdict:** Prevents the dreaded $O(n^2)$ nightmare of basic sorting algorithms. It's scalable and smart.

### 🥇 The "Heavy Artillery" (Radix Sort)

* **Target:** Massive inputs (500+ numbers).
* **How it works:** Base-2 bitwise magic.

Instead of comparing numbers to each other, we simplify their values into contiguous indexes (0 to N). Then, we look at the binary representation of each index. Bit by bit (starting from the least significant bit), if the bit is `0`, we push to B (`pb`). If it's `1`, we rotate A (`ra`).

* **The Verdict:** Predictable, incredibly fast, and scales beautifully at $O(n \log n)$. This is what gets us full marks on the massive lists.

---

## 📚 Resources

Shoutout to the sacred texts that got us through this:

* 📖 **The Push_Swap Subject Guide:** (You know where to find it).
* 🧮 **Visualizing Radix Sort:** [GeeksForGeeks - Radix Sort](https://www.geeksforgeeks.org/radix-sort/)
* ⏱️ **Time Complexity Cheat Sheet:** [Big O Cheat Sheet](https://www.bigocheatsheet.com/)

*Disclaimer: AI was utilized as a sparring partner to help format this README and explain some complex bitwise theory. Zero code was blindly copy-pasted. Every pointer was manually lost, found, and freed by us.*

---

## 🧼 Code Hygiene

* ✔️ **Norminette:** Passed. Every space, tab, and line limit respected.
* ✔️ **Memory:** 100% Leak-free. Valgrind is our best friend.

---

## 👨‍💻 The Architects

Built with sweat, tears, and lots of segfaults at **42 Irbid** by:

* **`mal-jama`** * **`akamamji`** > *"It's not a bug, it's just an undocumented sorting feature."* 🐛✨

> *"0 memory leaks, 100% sorted, infinite caffeine."* ☕
```
