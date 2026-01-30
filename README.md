# push_swap - Efficient Stack Sorting Algorithm

A sorting program that uses two stacks and a limited set of operations to sort integers with minimum instructions, implementing an optimized algorithm for the classic push_swap problem.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Limitations & Notes](#limitations--notes)
- [License](#license)

## Overview

**push_swap** is a sorting algorithm project that takes a list of integers and sorts them using two stacks (A and B) with a restricted set of operations. The goal is to minimize the number of operations required to achieve a sorted stack.

**Problem Statement**: Given a random list of integers in stack A, sort them in ascending order using the smallest number of allowed operations. Stack B is used as auxiliary storage.

This project demonstrates:
- Algorithm optimization and complexity analysis
- Stack data structure manipulation
- Operation cost calculation and greedy algorithms
- Input validation and error handling

The **bonus** program (`checker`) validates whether a given sequence of operations correctly sorts the input.

## Features

### Mandatory Program (`push_swap`)
- **Efficient Sorting Algorithm**: Optimized for different input sizes (3, 5, 100, 500+ elements)
- **Cost-Based Operation Selection**: Calculates cheapest move to minimize total operations
- **Target Finding**: Identifies optimal insertion positions using binary search logic
- **Dual Stack Management**: Coordinates operations between stack A and B
- **Operation Optimization**: Uses combined operations (rr, rrr, ss) when beneficial
- **Input Validation**: Handles duplicates, overflow, non-numeric input, and empty strings

### Bonus Program (`checker`)
- **Operation Validator**: Reads operations from stdin and executes them
- **Correctness Verification**: Outputs "OK" if sorted, "KO" otherwise
- **Same Operation Set**: Supports all 11 push_swap operations
- **Interactive Testing**: Integrates with get_next_line for stdin reading
- **Error Detection**: Validates operation syntax and stack states

### Common Features
- **Robust Input Parsing**: Handles space-separated and multi-argument formats
- **Memory Safety**: Proper allocation/deallocation without leaks
- **Integer Overflow Protection**: Validates against INT_MAX/INT_MIN boundaries
- **Edge Case Handling**: Single element, already sorted, reverse sorted inputs

## Project Structure

```
push_swap/
├── push_swap.c                 # Main entry point for sorting program
├── push_swap.h                 # Header with data structures and prototypes
├── checker_bonus.c             # Bonus: operation validator
├── push_swap_bonus.h           # Bonus: header file
│
├── data_parser.c               # Input validation and stack initialization
├── operation.c                 # Cost calculation and execution logic
├── transaction.c               # Target finding algorithms (min/max)
├── stack_help.c                # Stack preparation and sorting helpers
├── help.c                      # Utility functions (array management)
├── target.c                    # Target node identification
│
├── swap_operations.c           # sa, sb, ss implementations
├── push_operations.c           # pa, pb implementations
├── rotate_operations.c         # ra, rb, rr implementations
├── r_rotate_operations.c       # rra, rrb, rrr implementations
│
├── ft_stacknew.c               # Stack creation
├── ft_stackpush.c              # Push element to stack
├── ft_stackpop.c               # Pop element from stack
├── ft_stackclear.c             # Free all stack memory
├── ft_lstsort.c                # Check if list is sorted
├── ft_atol.c                   # String to long conversion
│
├── libft/                      # Custom C library (linked lists, strings)
├── printf/                     # Custom printf implementation
├── get_next_line/              # Read line from file descriptor (bonus)
└── Makefile                    # Build configuration
```

### Key Files

#### Core Algorithm
- **[push_swap.c](push_swap.c)**: Entry point with error handling and stack initialization
- **[operation.c](operation.c)**: Implements `op_a()` and `op_b()` - core operation selection logic
- **[transaction.c](transaction.c)**: Target finding functions (`transaction_a`, `transaction_b`)
- **[stack_help.c](stack_help.c)**: Cost calculation, median detection, cheapest operation selection

#### Data Structures
- **[push_swap.h](push_swap.h)**: Defines `t_stack` (stack container) and `t_swap` (node with metadata)
  - `t_swap` contains: `nbr` (value), `index` (position), `cost` (operation count), `is_cheapest` (flag), `is_above_median` (optimization flag), `target` (insertion point)

#### Operations (11 Total)
- **Swap**: `sa`, `sb`, `ss` - Swap first two elements
- **Push**: `pa`, `pb` - Move top element between stacks
- **Rotate**: `ra`, `rb`, `rr` - Shift all elements up (first becomes last)
- **Reverse Rotate**: `rra`, `rrb`, `rrr` - Shift all elements down (last becomes first)

## Installation

### Prerequisites
- **GCC** or compatible C compiler
- **Make** utility
- **POSIX-compliant OS** (Linux, macOS)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/push_swap.git
cd push_swap

# Build mandatory program
make

# Build bonus checker
make bonus

# Build both
make all

# Clean build artifacts
make clean      # Remove .o files
make fclean     # Remove .o files and executables
make re         # Rebuild from scratch
```

**Compiler Flags**: `-Wall -Wextra -Werror`

### Dependencies
The project includes custom implementations of:
- **libft**: Custom C standard library functions
- **ft_printf**: Custom printf implementation
- **get_next_line**: Line reading utility (bonus)

These are compiled automatically during the build process.

## Usage

### push_swap (Mandatory)

#### Command Syntax
```bash
./push_swap [integers...]
```

**Arguments**: Space-separated integers or quoted string with spaces

#### Examples

**Basic Usage**:
```bash
./push_swap 3 2 1 0
# Output: series of operations (sa, pb, ra, etc.)

./push_swap "5 8 3 1 2"
# Same as: ./push_swap 5 8 3 1 2
```

**Already Sorted** (no output):
```bash
./push_swap 1 2 3 4 5
# Output: (nothing - already sorted)
```

**Random Large Input**:
```bash
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
# Outputs number of operations (typically < 700 for 100 numbers)
```

**Error Cases**:
```bash
./push_swap 1 2 2 3
# Output: Error (duplicate)

./push_swap 1 abc 3
# Output: Error (non-numeric)

./push_swap 2147483648
# Output: Error (overflow)

./push_swap "  "
# Output: Error (empty string)
```

### checker (Bonus)

#### Command Syntax
```bash
./checker [integers...]
# Then enter operations (one per line)
# Press Ctrl+D (EOF) to finish
```

#### Examples

**Valid Operations**:
```bash
./checker 3 2 1 0
sa
pb
pb
pa
pa
^D
# Output: OK (if sorted) or KO (if not)
```

**Pipe from push_swap**:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Output: OK
```

**Invalid Operation**:
```bash
./checker 3 2 1
invalid_op
^D
# Output: Error
```

### Testing Strategy

**Small Inputs** (3 elements):
```bash
./push_swap 2 1 3
# Expected: ≤ 3 operations
```

**Medium Inputs** (5 elements):
```bash
./push_swap 5 4 3 2 1
# Expected: ≤ 12 operations
```

**Large Inputs** (100 elements):
```bash
# Generate 100 random numbers
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
OPERATIONS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPERATIONS"
# Expected: < 700 operations (5 points), < 900 (4 points), < 1100 (3 points)
```

**Verification**:
```bash
ARG="3 0 9 1"
./push_swap $ARG | ./checker $ARG
# Should output: OK
```

## Technical Details

### Algorithm Overview

The implementation uses a **cost-based greedy algorithm** with target node optimization:

1. **Initial Phase**: Push first 2 elements to stack B (if size > 3)
2. **Main Loop**: For each element in A, calculate cost to push to B at optimal position
3. **Target Finding**: Use binary search logic to find insertion point in B
4. **Operation Optimization**: Combine operations (rr, rrr) when both stacks rotate same direction
5. **Final Phase**: Push all from B back to A in optimal order
6. **Alignment**: Rotate A to bring minimum element to top

### Core Data Structures

**Stack Container** (`t_stack`):
```c
typedef struct s_stack {
    int     count;      // Number of elements
    t_list  *top;       // Pointer to top node (linked list)
} t_stack;
```

**Node Metadata** (`t_swap`):
```c
typedef struct s_swap {
    long    nbr;              // Integer value
    long    index;            // Current position (0-based)
    long    cost;             // Operation cost to move
    bool    is_cheapest;      // True if lowest cost
    bool    is_above_median;  // Position optimization flag
    t_list  *target;          // Target insertion node
} t_swap;
```

### Cost Calculation

**Cost Formula**:
- If element and target both above median: `max(element_index, target_index)`
- If both below median: `max(stack_size - element_index, stack_size - target_index)`
- Mixed positions: `element_cost + target_cost`

**Example**:
```
Stack A: [5, 3, 7, 1] (indices 0, 1, 2, 3)
Stack B: [6, 4, 2]     (indices 0, 1, 2)
Median: 2

To push 7 (index 2, below median) to target 6 (index 0, above median):
Cost = (4 - 2) + 0 = 2 operations (rra, rra)
```

### Operation Optimization

**Combined Operations**:
- `rr`: When both A and B need `ra` and `rb`
- `rrr`: When both need `rra` and `rrb`
- `ss`: When both need `sa` and `sb`

**Rotation Direction**:
- `is_above_median == true`: Use `ra`/`rb` (forward rotation)
- `is_above_median == false`: Use `rra`/`rrb` (reverse rotation)

### Target Finding Algorithm

**For push to B** (`transaction_a`):
```
1. Find largest element smaller than current (closest match)
2. If no smaller element exists, target = max(B)
3. Binary search through B to find optimal position
```

**For push to A** (`transaction_b`):
```
1. Find smallest element larger than current
2. If no larger element exists, target = min(A)
3. Optimize for final sorted position
```

### Memory Management

**Allocation Strategy**:
- Stack nodes: `malloc(sizeof(t_swap))` for each integer
- Linked list: Custom `t_list` structure from libft
- Parsed arrays: Temporary allocation with `ft_split`, freed immediately

**Cleanup Order**:
1. Clear stack B: `ft_stackclear(b, free)`
2. Clear stack A: `ft_stackclear(a, free)`
3. Free temporary split arrays after parsing

**Leak Prevention**:
- All `malloc` calls paired with `free`
- Error paths free allocated memory before exit
- Linked list nodes freed recursively

### Input Validation

**Checks Performed**:
1. **Numeric Validation**: Only digits, '+', '-' allowed
2. **Overflow Detection**: Values must fit in `int` (INT_MIN to INT_MAX)
3. **Duplicate Detection**: No repeated values allowed
4. **Empty String**: Rejects pure whitespace input
5. **Sign Validation**: '+'/'-' only at start, not standalone

**Parsing Logic**:
```c
// Handles both formats:
./push_swap 1 2 3        // Multi-argument
./push_swap "1 2 3"      // Single quoted argument

// Implementation uses ft_split on each argv[i]
```

### Algorithm Complexity

**Time Complexity**:
- Best case: O(1) - Already sorted, no operations
- Average case: O(n²) - Cost calculation for each element
- Worst case: O(n²) - Reverse sorted input

**Space Complexity**: O(n) - Two stacks storing n elements total

**Operation Counts** (empirical):
- 3 elements: ≤ 3 operations
- 5 elements: ≤ 12 operations
- 100 elements: ~500-700 operations (optimal implementations)
- 500 elements: ~5500-7000 operations

### Special Cases

**3 Elements** (`sort_three`):
- Optimized function with fixed decision tree
- Maximum 2 operations needed (sa, ra, rra combinations)

**Single Philosopher** (1 element):
- Returns immediately (already sorted)

**2 Elements**:
- Single `sa` if unsorted, nothing if sorted

## Limitations & Notes

### Known Limitations

1. **Non-Optimal for Small Inputs**:
   - Current implementation optimized for 100+ elements
   - 3-element sort uses dedicated function (optimal)
   - 5-element sort could be more optimized

2. **Operation Count Variability**:
   - Same input size may produce different operation counts
   - Depends on initial order and distribution
   - Not deterministic for identical random seeds

3. **No Parallel Operations**:
   - Operations executed sequentially
   - Cannot combine unrelated operations (e.g., sa while rotating)

4. **Fixed INT Range**:
   - Only accepts values within INT_MIN to INT_MAX
   - No support for unsigned or long long values

5. **No Dynamic Optimization**:
   - Algorithm decided at compile time
   - Cannot switch strategies based on runtime analysis

### Edge Cases Handled

- ✅ Empty input (argc == 1): Exits gracefully
- ✅ Already sorted: No operations printed
- ✅ Reverse sorted: Handles worst-case
- ✅ Duplicates: Error message
- ✅ Quoted arguments with spaces: Parsed correctly
- ✅ Mixed positive/negative numbers: Supported
- ✅ Leading zeros: Accepted (e.g., "007" → 7)
- ✅ Multiple spaces between numbers: Handled by ft_split

### Not Implemented

- ❌ Graphical visualization of operations
- ❌ Operation count comparison with other algorithms
- ❌ Benchmarking mode
- ❌ Undo operation for checker
- ❌ Step-by-step execution mode

### Testing Tips

**Automated Testing**:
```bash
# Generate random test cases
for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker $ARG)
    echo "Test $i: $OPS ops, Result: $CHECK"
done
```

**Stress Testing**:
```bash
# Test maximum operations (500 elements)
ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

**Valgrind (Memory Leaks)**:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 2 8 1 3
```

**Error Handling**:
```bash
# Test invalid inputs
./push_swap 1 2 2 3          # Duplicate
./push_swap 1 2147483648     # Overflow
./push_swap 1 abc            # Non-numeric
./push_swap ""               # Empty string
```

## License

This project is for educational purposes as part of the 42 School curriculum.

**Academic Use**: This implementation is provided as a reference. If you are a 42 student, you must write your own code according to the school's academic integrity policies.

---

**Key Concepts Demonstrated**:
- Algorithm optimization and complexity analysis
- Stack data structure implementation
- Greedy algorithms and cost calculation
- Memory management in C
- Input validation and error handling
- Linked list manipulation
- Modular code design and separation of concerns
- Makefile build automation
