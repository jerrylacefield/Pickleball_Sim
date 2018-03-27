#rm main game1.txt game2.txt game3.txt
g++ -std=c++11 -o main main.cpp

for run in {1..3}
do
  ./main
  sleep 1
done
