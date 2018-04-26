# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is the longest word in the dictionaries.

## According to its man page, what does `getrusage` do?

It gets resource usage measures for a process(es), like CPU time and memory used.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

It's a good design, it saves memory and calculate() need latest variables values.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

1. main() checks if arguments are valid and correct. By default, it uses large dictionaries, but the user
has an ability to choose smaller one. 

2. It calls getrusage() and calculate() to measure load times before and after reading a text.

3. The 'for' loop in main() is reading the words (string of chars ended by space or newline) symbol-by-symbol. 
If it contains a digit or string ends up being too long, it traverses this word and doesn't check it for misspelling.
If not, it checks word for misspellings, reset the word index to zero, and continue the symbol reading loop.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

'fscanf' causing problems with digits and words with some funky characters and errors.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Because we want to protect them from modifying (accidentally or maliciously). And because it's just good design.
