#!/bin/bash

createDiff() {
  awk -F ' ' '{print $2}' $1
}

make
./account > my.log

createDiff 19920104_091532.log > diff_org.txt
createDiff my.log > diff_my.txt

diff --color diff_org.txt diff_my.txt > tmp.txt
if [[ -s tmp.txt ]]; then
  echo "there is diff"
  cat tmp.txt
else
  echo "no diff!"
fi
rm tmp.txt diff_org.txt diff_my.txt my.log