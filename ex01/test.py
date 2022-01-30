#!/usr/bin/env python3
from subprocess import run

# First name, Last name, Nickname, Telephone, Deepest Secret
data = [
    ["Maribel", "Hearn", "mary", "010-123-4567", "may be Yuk"],
    ["Renko", "Usami", "renko", "010-987-6543", "is lazy"],
    ["Sumirenko", "Usami", "sumi", "010-occ-ults", "is edgy"],
    ["Yukari", "Yakumo", "yuk", "010-gap-haxx", "is lazy"],
    ["Reimu", "Hakurei", "reimu", "010-giv-mony", "is broke as hell"],
    ["Keine", "Kamishirasawa", "Ke-Ne", "010-his-tory", "wikipedia addict"],
]


def add(contact: list[str]):
    return "ADD\n" + "\n".join(contact) + "\n"


commands = (
    "\n".join(add(d) for d in data)
    + """SEARCH
EXIT
"""
)
run(["./phonebook"], input=str.encode(commands))
