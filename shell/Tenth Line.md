## Tenth Line
### Illustrate
<https://leetcode.com/problems/tenth-line>

Given a text file file.txt, print just the 10th line of the file.

### Input - `file.txt`

```
Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
```

### Output
```
Line 10
```

### Code - _using sed_
The sed -n '10p' file.txt command prints the 10th line of the file named file.txt. The -n option tells sed not to print anything by default, and the 10p command tells sed to print the 10th line.

```bash
sed -n '10p' file.txt
```

### Code - _using awk_
```bash
# The variable "$0" refers to the entire line that AWK reads in
cat file.txt | awk '{if (NR == 10) print $0;}'
# or shorter
awk '{if (NR == 10) print $0;}' file.txt
# or even shorter
awk 'NR == 10' file.txt
```

#### Question/Answer awk
- [What does it mean when an awk script has code outside curly braces?](https://stackoverflow.com/questions/38596130/what-does-it-mean-when-an-awk-script-has-code-outside-curly-braces)
- Answer: in the answer section.

If you have:

```bash
{ action }
```

...then that action runs on every line. By contrast, if you have:

```bash
# There's no semicolon after condition!!
condition { action }
```

...then that action runs only against lines for which the condition is true.

Finally, if you have only a condition, then the **default action is print**:

```bash
NR % 2 == 0
```
...will thus print every other line.

You can similarly have multiple pairs in a single script:

```bash
condition1 { action1 }
condition2 { action2 }
{ unconditional_action }
```

...and can also have `BEGIN` and `END` blocks, which run at the start and end of execution.

--
- [What does the semicolon represent in an awk action?](https://stackoverflow.com/questions/11078585/what-does-the-semicolon-represent-in-an-awk-action)
- Answer: in the answer section.

In awk, you can write two statements in one line separated by ;(semi-colon)

```bash
{ num_gold++; wt_gold += $2 }
Otherwize, you should put them into separated lines:

{
    num_gold++
    wt_gold += $2
}
```

To print the variables, you just add print before the variables:

```bash
{
    num_gold++
    wt_gold += $2

    print num_gold
    print wt_gold
}
```

As I said, you can put them all in one line:

```bash
{ num_gold++; wt_gold += $2; print num_gold; print wt_gold; }
```
It's too long!

print also accepts multiple arguments, so try

```bash
print num_gold, wt_gold.
```
