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
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk -F " " 'BEGIN { OFS=" " } { print $2, $1}'
```