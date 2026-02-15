*This project has been created as part of the 42 curriculum by tokyrand.*

<div align="center">

# 🖨️ ft_printf
### Because ft_putnbr() and ft_putstr() aren’t enough

![C](https://img.shields.io/badge/Language-C%20-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

</div>

---
## 📖 Description

**ft_printf** is a key project in the 42 curriculum that challenges students to recode the famous standard C library function `printf()`. This project serves as an introduction to **variadic functions** in C, teaching how to handle a variable number of arguments efficiently.

> The goal is to create a library `libftprintf.a` containing the `ft_printf` function. This function mimics the original's behavior without implementing buffer management. It handles various format specifiers for characters, strings, pointers, and numbers (decimal and hexadecimal). Once validated, this function becomes a permanent addition to your personal `libft`.

---

## 📐 Technical Approach

To successfully replicate `printf`, a structured approach using variadic arguments is required.

### 🧠 Algorithm & Logic
The function parses the format string character by character:
1.  **Standard Output:** If the character is not `%`, it is written to standard output immediately.
2.  **Format Specifier:** If a `%` is encountered, the next character determines the specific conversion function to call.
3.  **Variadic Handling:** The `stdarg.h` macros (`va_start`, `va_arg`, `va_copy`, `va_end`) are used to access the variable arguments passed to the function sequentially.
4.  **Return Value:** The function counts and returns the total number of characters printed.

### 🏗️ Implementation Details
The project is structured using modular helper functions to handle specific conversions:
*   **Modular Design:** Specific files handle specific types (`ft_print_str.c`, `ft_print_ptr.c`, `ft_print_u.c`).
*   **Edge Case Handling:**
    *   **Strings (`%s`):** Handles `NULL` inputs by printing `(null)`.
    *   **Pointers (`%p`):** Handles `NULL` pointers by printing `(nil)`. Uses `uintptr_t` for safe memory address casting.
    *   **Integers:** Special check for `INT_MIN` (-2147483648) in `ft_putnbr` to prevent overflow errors.
*   **Hexadecimal Conversion:** Uses recursive helper functions (`ft_tohex` and `ft_putnbr_base`) to print numbers in base 16 (uppercase and lowercase).

---

## 📁 Project Structure

The library is built from the following source files:

| File | Description |
| :--- | :--- |
| **ft_printf.c** | Core function logic. Parses the format string and dispatches to helpers. |
| **ft_print_str.c** | Handles `%s` (string) conversion. |
| **ft_print_ptr.c** | Handles `%p` (pointer) conversion. |
| **ft_print_u.c** | Handles `%u` (unsigned integer) conversion. |
| **ft_putnbr.c** | Handles `%d` and `%i` (integer) conversion. |
| **ft_utils.c** | Utility functions: `ft_putchar`, `ft_strlen`, `ft_strdup`, `count_int`, `ft_putnbr_base`. |
| **ft_strlcpy.c** | Helper function to copy strings safely. |
| **ft_printf.h** | Header file containing function prototypes and libraries. |

---

## 🛠 Library Contents

The `ft_printf` function mimics the original `printf()` behavior for the following conversions:

### 🧩 Mandatory Conversions

| Specifier | Description |
| :--- | :--- |
| **%c** | Prints a single character. |
| **%s** | Prints a string (as defined by common C convention). Prints `(null)` if NULL. |
| **%p** | The void * pointer argument is printed in hexadecimal format. Prints `(nil)` if NULL. |
| **%d** | Prints a decimal (base 10) number. |
| **%i** | Prints an integer in base 10. |
| **%u** | Prints an unsigned decimal (base 10) number. |
| **%x** | Prints a number in hexadecimal (base 16) lowercase format. |
| **%X** | Prints a number in hexadecimal (base 16) uppercase format. |
| **%%** | Prints a percent sign. |

---

## ⚙️ Instructions

### 🚀 Compilation
The project includes a `Makefile` that compiles the source files into a static library named `libftprintf.a`.

To compile the library, simply run:
```bash
make
```

### 📋 Makefile Rules

| Rule | Description |
| :--- | :--- |
| `all` | Compiles the library (`libftprintf.a`). |
| `clean` | Removes all object files (`*.o`). |
| `fclean` | Removes object files and the library. |
| `re` | Performs `fclean` followed by `all`. |

### 💻 Usage
To use this function in your own C projects:

1.  Include the `ft_printf.h` header file:
    ```c
    #include "ft_printf.h"
    ```

2.  Compile your project by linking the static library:
    ```bash
    gcc your_main.c -L. -lftprintf -o your_program_name
    ```

---

## 📚 Resources

Here are some useful references that helped during the development of this project:

*   📖 **Variadic Functions (stdarg)**: [cplusplus.com](https://www.cplusplus.com/reference/cstdarg/) — Essential documentation for understanding `va_start`, `va_arg`, `va_copy`, and `va_end`.
*   🖨️ **Printf Man Page**: Use `man 3 printf` to understand the original behavior and edge cases.
*   🎥 **YouTube Tutorials**: Visual explanations on how stack operations work with variadic arguments.
*   📏 **42 Norm**: The coding standard guide.

---

### 🤖 AI Usage

*This section describes how Artificial Intelligence tools were used during the completion of this project.*

*   **Tasks:** AI was used to explain the logic behind pointer casting for `%p` using `uintptr_t`, clarify the correct formatting for `INT_MIN` handling, and structure the recursive logic for `ft_putnbr_base`.
*   **Rationale:** The goal was to ensure robust handling of edge cases (like NULL pointers and string limits) and to verify the correct usage of `va_copy` within the variadic argument flow.
*   **Impact:** No code was directly copied and pasted. The algorithm was designed and written from scratch to ensure a deep understanding of variable argument handling in C.

---
```