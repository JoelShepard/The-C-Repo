# Comment Style Guide - FI Folder

## Philosophy

Comments should be **light, purposeful, and non-invasive**. The code itself should be the primary documentation. Comments should only explain *why* something is done, not *what* is being done.

**Principle**: If code logic is unclear, improve the code—don't add comments to explain bad code.

---

## Comment Types & Usage

### 1. File Headers ✅
Use a minimal file header only if helpful:

```c
/* temperature.c - Temperature statistics analyzer */
#include <stdio.h>
```

**Guidelines:**
- Single-line format preferred
- Include filename and brief purpose
- Don't repeat the filename
- Optional for very simple files

### 2. Function Documentation ✅ (Minimal)
For **public functions or non-obvious behavior**:

```c
// Returns dynamically allocated reversed string
char* reverseString(char *str){
    // implementation
}

// Finds max element using linear search (not optimal for large arrays)
int findMax(int *arr, int size){
    // implementation
}
```

**Guidelines:**
- Keep to 1-2 lines above the function
- Explain what it returns or its non-obvious behavior
- Don't document parameters that are obvious from the function name
- Don't explain obvious return types

### 3. Algorithm/Logic Comments ✅
For **non-obvious algorithms or tricky code**:

```c
// Circular right shift: a → c, b → a, c → b
a2 = b;
b2 = c;
c2 = a;

// Handle 9 → 0 wrap-around for digit increment
if (digit == 9) {
    digit = 0;
}

// Case-insensitive palindrome check
char* upper = toUppercase(str);
```

**Guidelines:**
- Explain the *why* or the *trick*
- Don't explain obvious operations
- Use on lines before the relevant code
- Be concise (one line when possible)

### 4. Edge Cases & Important Notes ✅
For **constraints, assumptions, or gotchas**:

```c
// Handle newline added by fgets
word[strlen(word) - 1] = '\0';

// Simplified check: doesn't handle case or spacing differences
if(same_letter == strlen(word2) || same_letter == strlen(word1)){ 
    printf("Anagrams\n");
}

// TODO: Optimize with hash table for O(n) instead of O(n²)
```

**Guidelines:**
- Use for actual issues or missing features
- Be specific about the limitation
- Only add TODO/FIXME for genuine future improvements

---

## What NOT to Comment

### ❌ Don't Comment Obvious Code

```c
// WRONG:
x = x + 1;  // Increment x
i = 0;      // Set i to zero
printf("Hello\n");  // Print hello message

// RIGHT:
x++;
i = 0;
printf("Hello\n");
```

### ❌ Don't Use Section Markers

```c
// WRONG:
// === VARIABLES ===
// === INPUT ===
// === OUTPUT ===
// === PROCESSING ===

// RIGHT:
// Just write the code without markers
```

### ❌ Don't Over-Document Simple Functions

```c
// WRONG:
/*
 * Adds two numbers
 * 
 * Parameters:
 *   a - First number
 *   b - Second number
 * 
 * Returns:
 *   Sum of a and b
 */
int add(int a, int b){
    return a + b;
}

// RIGHT:
int add(int a, int b){
    return a + b;
}
```

### ❌ Don't Comment Control Flow

```c
// WRONG:
if (x > 0) {  // Check if x is positive
    doSomething();
}

for (i = 0; i < n; i++) {  // Loop from 0 to n-1
    process(arr[i]);
}

// RIGHT:
if (x > 0) {
    doSomething();
}

for (i = 0; i < n; i++) {
    process(arr[i]);
}
```

---

## Comment Style Rules

### 1. **Single-Line Comments** (`//`)
- Preferred for most comments
- Place before the relevant code
- Use for brief explanations

```c
// Handles wrap-around: 9 becomes 0
if (digit == 9) digit = 0;
```

### 2. **Multi-Line Comments** (`/* */`)
- Use for file headers only
- Avoid for function documentation
- Keep brief

```c
/* q2.c - Recursive digit increment program */
```

### 3. **Spacing**
- One space after `//`
- Don't over-comment
- Leave 1 blank line between comment block and next code section

```c
// Good spacing and minimal comments
int main() {
    float temps[7];
    
    // Read temperatures
    for (int i = 0; i < 7; i++) {
        scanf("%f", &temps[i]);
    }
    
    // Calculate average
    // implementation...
}
```

### 4. **Language**
- Use English for consistency
- Be concise and direct
- Avoid redundancy

---

## Examples: Before & After

### Example 1: Over-Commented
**BEFORE:**
```c
/* *
Function principale per l'analisi delle temperature settimanali
Calcola media, massimo, minimo e mostra un istogramma
 */
int main() {
    // === DICHIARAZIONE VARIABILI ===
    float temperature[NUMGIORNI];
    float sum=0.0, avg, max=0.0, min=__FLT_MAX__;  // Variabili per calcoli
    
    // === INPUT DELLE STRINGHE ===
    for (i = 0; i < NUMGIORNI; i++){
        // Leggi temperatura
        scanf("%f", &temperature[i]);
    }
    
    // === CALCOLO MEDIA ===
    for (i = 0; i < NUMGIORNI; i++){
        // Accumula valori
        sum = sum + temperature[i];
    }
    avg = sum / NUMGIORNI;  // Calcola media
}
```

**AFTER:**
```c
int main() {
    float temperature[NUMGIORNI];
    float sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    
    for (i = 0; i < NUMGIORNI; i++){
        scanf("%f", &temperature[i]);
    }
    
    for (i = 0; i < NUMGIORNI; i++){
        sum = sum + temperature[i];
    }
    avg = sum / NUMGIORNI;
}
```

### Example 2: Meaningful Comments Added
**BEFORE:**
```c
int isPalindromo(char *str){
    int len=strlen(str);
    int lenpos=len-1;
    char* betterstr = toUppercase(str);
    // ... complex logic ...
}
```

**AFTER:**
```c
// Checks if string is palindrome (case-insensitive)
int isPalindromo(char *str){
    int len=strlen(str);
    int lenpos=len-1;
    char* betterstr = toUppercase(str);  // Need case-insensitive comparison
    // ... complex logic ...
}
```

### Example 3: Algorithm Documentation
**BEFORE:**
```c
a2 = b;  // Il nuovo valore di 'a' diventa l'ex valore di 'b'
b2 = c;  // Il nuovo valore di 'b' diventa l'ex valore di 'c'
c2 = a;  // Il nuovo valore di 'c' diventa l'ex valore di 'a'
```

**AFTER:**
```c
// Circular right shift: a → c, b → a, c → b
a2 = b;
b2 = c;
c2 = a;
```

---

## Quick Reference Checklist

When adding a comment, ask yourself:

- [ ] Does this comment explain *why*, not *what*?
- [ ] Would a better variable name eliminate this comment?
- [ ] Is the code unclear, or is the comment just obvious?
- [ ] Does this add real value to understanding?
- [ ] Can I remove this and the code still be clear?

If you answered **NO** to any of these, **consider removing the comment**.

---

## Common Patterns

### ✅ Good Comment Examples
```c
// Remove newline added by fgets
word[strlen(word) - 1] = '\0';

// Simplified anagram check: doesn't handle case or spacing
if(same_letters == strlen(word)){
    printf("Anagrams\n");
}

// Wrap 9 → 0 for digit increment
if (digit == 9) digit = 0;

// Use uppercase for case-insensitive comparison
char *upper = toUppercase(str);

// TODO: Optimize with hash table (currently O(n²))
```

### ❌ Bad Comment Examples
```c
// Set x to 0
x = 0;

// Loop through array
for (i = 0; i < n; i++) {

// Check if i equals N
if (i == N) {

// Print the result
printf("%d\n", result);

// CASE BASE
if (n == 0) {
```

---

## Summary

**The Goal**: Clean, readable code with **minimal, purposeful comments**.

- **Comment less, code better**
- **Explain why, not what**
- **No section markers or decorative comments**
- **Keep comments brief and to the point**
- **Remove obvious comments entirely**

Your code should read like prose—comments should enhance understanding, not clutter it.