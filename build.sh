rm main game1.txt game2.txt game3.txt
g++ -std=c++11 -o main main.cpp
./main >> game1.txt
./main >> game2.txt
./main >> game3.txt
