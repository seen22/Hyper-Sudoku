#include <vector>
#include <string>
#include <iostream>

#include "soduku.hpp"

// @Params: Nutzereingabe als vector @return 2D vector
std::vector <std::vector <char>> filterInput(std::vector <std::string> &file_lines);

//@params: 2D Vector sudoku_map, 2D Vector sudoku_map_original und Nutzereingabe
//@return Überprüfungsergebnis
bool eigenschaftTesten(std::vector <std::vector <char>> &sudoku_map,
                       const std::vector <std::vector <char>> &sudoku_map_original,
                       std::string eingabe);

//@params: eingabe, @return vector mit der gelesenen Datei
std::vector <std::string> dateiLesen(std::string &eingabe);

//@params: 2D Vector sudoku_map
void dateiSchreiben(std::vector <std::vector <char>> &sudoku_map);

//@params: 2D Vector sudoku_map
void printSudoku(std::vector <std::vector <char>> &sudoku_map);

bool eigenschaftTesten_2(std::vector <std::vector <char>> &sudoku_map, std::string eingabe);


