#include <iostream>
#include <fstream>
#include "soduku.hpp"
#include "soduku.hpp"


using namespace std;

Sudoku::Sudoku(std::vector <std::vector <char>> eingabe_sudoku) {
  eingabe = eingabe_sudoku;
}
Sudoku::Sudoku() { }

std::vector <std::vector <char>> Sudoku::getSudoku() const {
  return eingabe;
}

void Sudoku::setSudoku(std::vector <std::vector <char>> eingabe_sudoku){
  eingabe = eingabe_sudoku;
}


