#!/bin/bash

file_to_compile=$1
output=${file_to_compile/.cpp}
g++-11 -std=c++17 -Wshadow -Wall -o $output $file_to_compile -O2 -Wno-unused-result
git add .
git commit -am "Added new solutions"
git pull https://github.com/wechicken456/codeforces.git
git push origin master

