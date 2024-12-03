#!/bin/sh


# Part 1:
VAR=$(rg -P -o -e "mul\([0-9]+,[0-9]+\)" input.txt | sed 's/,/*/g' | rg -P -o -e '[0-9]+[*][0-9]+')
PLUS=$(echo $VAR | sed "s/ /+/g")
echo $(($PLUS))


# Part 2:
SUM=0
STATE="do"
while read -r LINE; do
    if echo "$LINE" | rg -q "do\\(\\)"; then
        STATE="do"
    elif echo "$LINE" | rg -q "don't\\(\\)"; then
        STATE="don't"
    fi

    if [ "$STATE" = "do" ] && echo "$LINE" | rg -q "mul\\([0-9]+,[0-9]+\\)"; then
        NUMBERS=$(echo "$LINE" | sed 's/mul(\([0-9]\+\),\([0-9]\+\))/\1*\2/')
        RESULT=$(echo "$NUMBERS" | bc)
        SUM=$((SUM + RESULT))
    fi
done < <(rg -o "mul\\([0-9]+,[0-9]+\\)|do\\(\\)|don't\\(\\)" input.txt)
echo "Final sum: $SUM"
