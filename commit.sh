#!/bin/bash

file_to_compile=$1
output=${file_to_compile/.cpp}
g++-11 -std=c++17 -Wshadow -Wall -o $output $file_to_compile -Ofast -Wno-unused-result
git remote set-url origin https://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@github.com/wechicken456/codeforces.git/
git add .
git commit -am "Added new solutions"
git pull https://github.com/wechicken456/codeforces.git
git push origin master



