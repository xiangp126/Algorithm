## Word Frequency
### Illustrate
<https://leetcode.com/problems/word-frequency>

Write a bash script to calculate the frequency of each word in a text file words.txt.

For simplicity sake, you may assume:

- words.txt contains only lowercase characters and space ' ' characters.
- Each word must consist of lowercase characters only.
- Words are separated by one or more whitespace characters.

Note:

- Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
- Could you write it in one-line using Unix pipes?

### Input- _words.txt_

```
the day is sunny the the
the sunny is is
```

### Output
Your script should output the following, sorted by **descending frequency**:

```
the 4
is 3
sunny 2
day 1
```

### awk
FS : (input) field separator<br>
OFS:  output field separator

### Code
```bash
cat words.txt | tr -s " " "\n" | sort | uniq -c | sort -r | awk -F " " 'BEGIN{OFS = " "}{print $2, $1}'
# or simplify
cat words.txt | tr -s " " "\n" | sort | uniq -c | sort -r | awk '{print $2, $1}'
# or use complicated sort
cat words.txt | tr -s " " "\n" | sort | uniq -c | awk '{print $2, $1;}' | sort -t'' -k2 -rn
```

### Test the code
```bash
corsair@Giggle:shell$ cat words.txt | tr -s " " "\n"
the
day
is
sunny
the
the
the
sunny
is
is

corsair@Giggle:shell$ cat words.txt | tr -s " " "\n" | sort | uniq -c
   1 day
   3 is
   2 sunny
   4 the

# re-sort by descending frequency
corsair@Giggle:shell$ cat words.txt | tr -s " " "\n" | sort | uniq -c | sort -r
   4 the
   3 is
   2 sunny
   1 day

corsair@Giggle:shell$ cat words.txt | tr -s " " "\n" | sort | uniq -c | sort -r | awk '{print $2, $1;}'
the 4
is 3
sunny 2
day 1

# or
cat words.txt | tr -s " " "\n" | sort | uniq -c | awk '{print $2, $1;}' | sort -t'' -k2 -rn
the 4
is 3
sunny 2
day 1
```

#### sort
```
     -t char, --field-separator=char
             Use char as a field separator character.  The initial char is not considered to be part of a field when determining
             key offsets.  Each occurrence of char is significant (for example, ``charchar'' delimits an empty field).  If -t is
             not specified, the default field separator is a sequence of blank space characters, and consecutive blank spaces do
             not delimit an empty field, however, the initial blank space is considered part of a field when determining key
             offsets.  To use NUL as field separator, use -t '\0'.

     -k field1[,field2], --key=field1[,field2]
             Define a restricted sort key that has the starting position field1, and optional ending position field2 of a key
             field.  The -k option may be specified multiple times, in which case subsequent keys are compared when earlier keys
             compare equal.  The -k option replaces the obsolete options +pos1 and -pos2, but the old notation is also sup-
             ported.

    -n, --numeric-sort, --sort=numeric
             Sort fields numerically by arithmetic value.  Fields are supposed to have optional blanks in the beginning, an
             optional minus sign, zero or more digits (including decimal point and possible thousand separators).

    -r, --reverse
             Sort in reverse order.
```

#### tr
```
NAME
     tr -- translate characters

SYNOPSIS
     tr [-Ccsu] string1 string2
     tr [-Ccu] -d string1
     tr [-Ccu] -s string1
     tr [-Ccu] -ds string1 string2

DESCRIPTION
     The tr utility copies the standard input to the standard output with substitution or deletion of selected characters.
```

#### tr -s string1 string2
```bash
 -s Squeeze multiple occurrences of the characters
    listed in the last operand (either string1 or string2)
    in the input into a single instance of the character.

    This occurs after all deletion and translation is completed.
```
Test

```bash
corsair@Giggle:shell$ cat words.txt
the day is sunny the the
the sunny is is
Honey  Honey    is

corsair@Giggle:shell$ cat words.txt | tr ' ' '\n'
the
day
is
sunny
the
the
the
sunny
is
is
Honey

Honey



is

corsair@Giggle:shell$ cat words.txt | tr -s ' ' '\n'
the
day
is
sunny
the
the
the
sunny
is
is
Honey
Honey
is
```
