#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "soduku.hpp"
#include "metho.hpp"
#include <iomanip>

using namespace std;

int main() {
  string eingabe_datei = "sudoku.txt";
  Sudoku sudoku;
  vector <string> file_lines = dateiLesen(eingabe_datei);

  vector <vector <char>> sudoku_map = filterInput(file_lines);
  sudoku.setSudoku(sudoku_map);
  vector <vector <char>> const sudoku_map_original = sudoku.getSudoku();

  cout << "Das Spiel wird mit der Eingabe 'exit' beendet\n" << endl;

  printSudoku(sudoku_map);
  string eingabe;
  unsigned long zeile, spalte;
  do{
    cout << "Eingabe ";
    cin >> eingabe;
    zeile  = static_cast<unsigned long>(eingabe[0] - '0');
    spalte = static_cast<unsigned long>(eingabe[1] - '0');

    char wert = eingabe[2];

    bool hat_wert = eigenschaftTesten(sudoku_map, sudoku_map_original,eingabe);
    bool hat_wert_2 = eigenschaftTesten_2(sudoku_map, eingabe);

    if(!hat_wert && !hat_wert_2 && eingabe != "exit"){
      sudoku_map[zeile - 1][spalte - 1] = wert;
    } else {
      cout << "Das geht nicht\n" << endl;
    }

    printSudoku(sudoku_map);
  } while (eingabe != "exit");

  cout << "Speichern?[ja/nein] ";
  cin >> eingabe;

  if(eingabe == "ja"){ dateiSchreiben(sudoku_map); }

  return 0;
}
