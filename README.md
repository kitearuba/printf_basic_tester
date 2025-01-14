---

# 🎯 `ft_printf` Tester

Welcome to the **`ft_printf` Tester**! This tool is designed to rigorously test your custom implementation of the `ft_printf` function against the standard `printf` function. With comprehensive test cases, color-coded output, and a detailed summary, this tester ensures your implementation is accurate and reliable.

This project originated from a fellow student, and we've worked together to improve it further. We hope it serves as a valuable resource for others in their journey with `ft_printf`.

## 📋 Table of Contents

- [🎯 Features](#-features)
- [💻 Requirements](#-requirements)
- [⚙️ Installation](#-installation)
- [🚀 Usage](#-usage)
- [🧪 Test Coverage](#-test-coverage)
- [🔍 Understanding the Output](#-understanding-the-output)
- [🔧 Compilation Options](#-compilation-options)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

## 🎯 Features

- **Comprehensive Test Suite**: Tests a wide range of format specifiers and edge cases to ensure your `ft_printf` behaves as expected.
- **🟢🟥 Color-Coded Output**: Easy-to-read results, with green for passed tests 🟢 and red for failed tests 🟥.
- **📝 Summary Report**: A final summary showing the total number of passed and failed tests.
- **📊 Extensible**: Add new test cases easily by modifying `main.c`.

## 💻 Requirements

- A working implementation of the `ft_printf` function.
- A C compiler like `gcc`.
- The `libftprintf.a` static library file generated from your `ft_printf` implementation (if you used `libft`).

## ⚙️ Installation

### 1. **Clone the Repository**
```bash
git clone git@github.com:kitearuba/printf_basic_tester.git printf-tester
cd printf-tester
```

### 2. **Ensure Your `ft_printf` Library is Compiled**
Ensure you have compiled your `ft_printf` implementation and generated the `libftprintf.a` file in the root directory.

### 3. **Prepare the Tester**
Place `main.c`, `libftprintf.a`, and your header files (`ft_printf.h`, `libft.h`) in the appropriate directories.

## 🚀 Usage

### 1. **Compile the Tester**

Depending on whether or not you used `libft` in your project, follow the appropriate compilation steps:

#### 🛠️ **Option 1: With `libft` Library**
If your `ft_printf` implementation relies on functions from the `libft` library:
```bash
gcc printf_main_tester.c -I./include/ -I./libft/ -L. -lftprintf -o tester
```

#### 🛠️ **Option 2: Without `libft` Library**
If your `ft_printf` implementation does not rely on the `libft` library:
```bash
gcc printf_main_tester.c -I./include/ -L. -lftprintf -o tester
```

### 2. **Run the Tester**
```bash
./tester
```

This will execute all the tests and print the results directly in your terminal with color-coded output for easy review.

## 🧪 Test Coverage

The tester includes a variety of test cases designed to thoroughly assess your `ft_printf` implementation:

### 🔤 Character Tests
- **Basic Characters (`%c`)**: Tests the printing of standard characters like `A`.
- **Null Character**: Tests how `ft_printf` handles the null character (`\0`).
- **Special Characters**: Includes newline (`\n`), tab (`\t`), and other escape sequences to ensure correct handling.

### 🔠 String Tests
- **Basic Strings (`%s`)**: Simple strings to check standard output.
- **Empty Strings**: Ensures your implementation handles empty strings (`""`) correctly.
- **Long Strings**: Tests the ability to handle and correctly print long strings.
- **Special Characters in Strings**: Includes escape sequences within strings to check for correct interpretation.

### 🔗 Pointer Tests
- **Valid Pointers (`%p`)**: Tests the correct printing of memory addresses.
- **NULL Pointers**: Ensures `ft_printf` handles `NULL` pointers correctly, typically printing `(nil)` or an equivalent representation.

### 🔢 Integer Tests
- **Positive Integers (`%d` and `%i`)**: Verifies correct printing of standard positive integers.
- **Negative Integers**: Tests the handling of negative values.
- **Edge Cases**: Includes `INT_MAX` and `INT_MIN` to check for boundary conditions.

### 🔣 Unsigned Integer Tests
- **Standard Unsigned Integers (`%u`)**: Verifies the correct printing of unsigned integers.
- **Edge Cases**: Includes `UINT_MAX` to ensure that your implementation handles the upper boundary of unsigned integers.

### ⚙️ Hexadecimal Tests
- **Lowercase Hex (`%x`)**: Tests the conversion of integers to lowercase hexadecimal.
- **Uppercase Hex (`%X`)**: Tests the conversion of integers to uppercase hexadecimal.
- **Zero Value**: Ensures correct handling of zero in hexadecimal format.

### 🧩 Special Cases
- **NULL with `%s`**: Tests how `ft_printf` handles `NULL` pointers with the `%s` format specifier, which should typically print `(null)` or an equivalent.
- **Escape Sequences**: Tests various escape sequences (like `\\n`, `\\t`, `\\r`) to ensure correct output.
- **Complex Format Strings**: Combines various specifiers in one format string to ensure `ft_printf` handles complex scenarios correctly.

## 🔍 Understanding the Output

### Color-Coded Results:
- **🟢 PASS**: The output of `ft_printf` matches the output of `printf`.
- **🟥 FAIL**: The outputs do not match, indicating an issue.

### Example Output:
```bash
🟢 PASS: Basic %c
🟥 FAIL: Null %c
...
Summary:
🟢 Passed: 20
🟥 Failed: 2
```

### Final Summary:
After all tests are executed, you'll see a summary showing how many tests passed and how many failed. This helps you quickly assess the overall accuracy of your `ft_printf` implementation.

## 🔧 Compilation Options

### For Users Who Did Not Use `libft`:
If your `ft_printf` implementation does not rely on the `libft` library, you can compile the tester without linking `libft` by omitting the `-I./libft/` and relying solely on the necessary includes for `ft_printf`.

```bash
gcc main.c -I./include/ -L. -lftprintf -o tester
```

This will ensure that your tester is correctly set up even if you did not incorporate the `libft` library into your project.

## 🤝 Contributing

We welcome contributions! If you find a bug, have suggestions for improvement, or want to add additional test cases, feel free to open an issue or submit a pull request.

### Steps to Contribute:

1. **Fork the Repository**
2. **Create a New Branch**
   ```bash
   git checkout -b feature-or-fix
   ```
3. **Commit Your Changes**
   ```bash
   git commit -m "Add feature or fix"
   ```
4. **Push to Your Branch**
   ```bash
   git push origin feature-or-fix
   ```
5. **Open a Pull Request**

## 📄 License

This project is licensed under the MIT License. For more details, see the [LICENSE](LICENSE) file.

---

### ⚠️ **Important Note**:
Ensure your terminal supports ANSI escape codes for the color coding to display correctly. Most modern terminals do, but if you encounter issues, consider testing in a different terminal environment.

---
