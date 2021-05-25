
$file_to_compile = $1
$output = ${file_to_compile/.cpp}
clang++ -std=c++17 -o $output $file_to_compile
git add .
git commit -am "Added new solutions"
git pull https://github.com/wechicken456/codeforces.git
git push origin master

