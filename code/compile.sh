g++ -g -O2 -std=gnu++17 -Wextra -Wall -fsanitize=address -fno-omit-frame-pointer -o $1 $1.cpp

echo "Compiled "$1"."
