awk -F ' ' '{
    for (i = 1; i <= NF ; ++i) {
        s[i] = s[i] " " $i;
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' transpose.txt
