#!/usr/bin/env python3

from os import system

tests = [
    '"shhhhh... I think the students are asleep..."',
    'Damnit " ! " "Sorry students, I thought this thing was off."',
    "",
]

for i, test in enumerate(tests):
    print(f"[case {i}]\n{test}")
    system(f"valgrind ./megaphone {test}")
