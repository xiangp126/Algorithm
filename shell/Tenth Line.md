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
```bash
sed -n '10p' file.txt
```

### Code - _using awk_
```bash
cat file.txt | awk '{if (NR == 10) {print $0}}'
# or shorter
cat file.txt | awk 'NR == 10
```