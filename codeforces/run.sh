clang++ -std=c++17 -O2 -Wall -fsanitize=undefined -o sol sol.cpp && time ./sol < test_input.txt > test_output.txt

