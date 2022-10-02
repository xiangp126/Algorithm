## Valid Phone Numbers
### Illustrate
<https://leetcode.com/problems/valid-phone-numbers/>

Given a text file file.txt that contains a list of phone numbers (one per line), write a one-liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

### Input - `file.txt`
```
987-123-4567
123 456 7890
(123) 456-7890
```

### Output
```
987-123-4567
(123) 456-7890
```

### Regex
_for `extended regex`, `()` is `catch`_

```bash
[0-9]{3}
[0-9]{m,n}
[0-9]
```

### Concept
```bash
'[0-9]{3}-'
'\([0-9]{3}\) '
=>
([0-9]{3}-|\([0-9]{3}\) )
```

### Code

`-E, -r, --regexp-extended`


```bash
# Do not replace [0-9] with \d.
# Sometimes they didn't mean the same thing
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
```
