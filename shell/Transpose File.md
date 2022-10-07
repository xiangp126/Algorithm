## Transpose File
### Illustrate
<https://leetcode.com/problems/transpose-file>

Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the ' ' character.

### Input- _transpose.txt_

```
name age
alice 21
ryan 30
```

### Output
```
name alice ryan
age 21 30
```

### Code
```bash
# Read from the file file.txt and print its transposed content to stdout.
awk -F " " '{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) {
            s[i] = $i
        } else {
            s[i] = s[i] " " $i
        }
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i]
    }
}' file.txt

# NF = 2, NR = 3 in this example
```

Here're some quick notes to help you understand:

- The code block with an "END" prefix is only executed after the last line is read; similarly, a code block with a "BEGIN" prefix will be executed before any line reads.

- AWK is **line-based**: the main code block (the code block without prefix) processes one line of input at a time.

- The index starts from `1` not `0`.

- `NR`: a variable indicating the number of records (i.e. current line number) that's accumulated across multiple files read. FNR is similar to NR, but is reset for each file read. Since we only need to deal with one file in this question, either is fine to use.

- `NF`: a variable indicating the number of fields (i.e. number of "columns") on an input line.

- `$i`: the i-th field of the input line.

- `t[]`: an array for saving the transposed table. More on awk arrays here: <http://www.grymoire.com/Unix/Awk.html#uh-22>

### Test the code
```bash
# Always remember that AWK is line-based.
awk -F ' ' '{
    for (i = 1; i <= NF ; ++i) {
        s[i] = s[i] " " $i;
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' transpose.txt
```

yields:

```bash
 name alice ryan
 age 21 30
```

Then update the code to the desired one.