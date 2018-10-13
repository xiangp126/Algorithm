## Tenth Line
### Illustrate
<https://leetcode.com/problems/tenth-line>

Given a text file file.txt, print just the 10th line of the file.

### Input- _file.txt_

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

### sed

### Code
```bash
sed -n '10p' file.txt
```