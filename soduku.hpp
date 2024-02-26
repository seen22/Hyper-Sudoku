#include <iostream>
#include <vector>

#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku{
  public:
    Sudoku(std::vector <std::vector <char>> eingabe_sudoku);
    Sudoku();

    std::vector <std::vector <char>> getSudoku() const;
    void setSudoku(std::vector <std::vector <char>> eingabe_sudoku);

  private:
    std::vector <std::vector <char>> eingabe;
};
#endif


