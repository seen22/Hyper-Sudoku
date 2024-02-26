#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "metho.hpp"

using namespace std;

vector <vector <char>> filterInput(vector <string> &file_lines){
  vector <vector <char>> sudoku_map;
  sudoku_map.resize(9);
  for (size_t i = 0; i < file_lines.size(); i++) {
    string zwischen_speicher = file_lines[i];
    for (size_t j = 0; j < zwischen_speicher.size(); j++) {
      if((zwischen_speicher[j] >= '0' && zwischen_speicher[j] <= '9')){
        sudoku_map[i].push_back(zwischen_speicher[j]);
      }
    }
  }

  return sudoku_map;
}

bool eigenschaftTesten(vector <vector <char>> &sudoku_map,
                      const std::vector <std::vector <char>> &sudoku_map_original,
                      string eingabe){
  unsigned long zeile  = static_cast<unsigned long>(eingabe[0] - '0');
  unsigned long spalte = static_cast<unsigned long>(eingabe[1] - '0');
  char wert = eingabe[2];
  bool hat_wert = false;
  for (size_t s_zeile = 0; s_zeile < sudoku_map.size(); s_zeile++) {
    auto sudoku_zeile =  sudoku_map[s_zeile];
    for (size_t s_spalte = 0; s_spalte < sudoku_zeile.size(); s_spalte++) {
      if(((zeile - 1) == s_zeile && (spalte - 1) == s_spalte)){
        for (auto &c : sudoku_zeile){
          if(sudoku_map_original[s_zeile][s_spalte] != '0'){
            hat_wert = true;
            break;
          }
          if( c == wert ){
            hat_wert = true;
            break;
          }
        }
      }
    }
  }

  return hat_wert;
}

vector <string> dateiLesen(std::string &eingabe){
  ifstream target_file(eingabe);
  string user_input,line;
  vector <string> file_lines;

  if (target_file.is_open()){
    while (getline(target_file, line)){
      if(!line.empty()) { file_lines.push_back(line); }
    }
    target_file.close();
  } else {
    cout << "Fehler" << endl;
  }
  vector <vector <char>> sudoku_map = filterInput(file_lines);
  return file_lines;
}

void dateiSchreiben(std::vector <std::vector <char>> &sudoku_map){
  ofstream outfile("sudoku_ausgabe.txt");

  for (size_t i = 0; i < sudoku_map.size(); i++) {
    auto sudoku_zeile =  sudoku_map[i];
    for (size_t j = 0; j < sudoku_zeile.size(); j++) {
      if( j == 3 || j == 6 || j == 9){
        outfile << setw(3);
      }
      outfile << sudoku_zeile[j] << " ";
    }
    if (i == 2 || i == 5 || i == 8){
      outfile << "\n";
    }
    outfile << endl;
  }

  outfile.close();
}

void printSudoku(std::vector <std::vector <char>> &sudoku_map){
  for (size_t i = 0; i < sudoku_map.size(); i++) {
    auto sudoku_zeile =  sudoku_map[i];
    for (size_t j = 0; j < sudoku_zeile.size(); j++) {
      if( j == 3 || j == 6 || j == 9){
        cout << setw(3);
      }
      cout << sudoku_zeile[j] << " ";
    }
    if (i == 2 || i == 5 || i == 8){
      cout << "\n";
    }
    cout << endl;
  }
}

bool eigenschaftTesten_2(vector <vector <char>> &sudoku_map, string eingabe){
  int zeile  = eingabe[0] - '0',
      spalte = eingabe[1] - '0';
  char wert = eingabe[2];
  vector <char> quadrat_1, quadrat_2, quadrat_3,
                quadrat_4, quadrat_5, quadrat_6,
                quadrat_7, quadrat_8, quadrat_9;

  vector <char> hyper_1, hyper_2, hyper_3,hyper_4;

  bool hat_wert = false;

  for (size_t i = 0; i < sudoku_map.size(); i++) {
    auto sudoku_zeile =  sudoku_map[i];
    for (size_t j = 0; j < sudoku_zeile.size(); j++) {
      if((j >= 0 && j < 3) && (i == 0 || i == 1 || i == 2 )){ quadrat_1.push_back(sudoku_zeile[j]); }
      if((j >= 3 && j < 6) && (i == 0 || i == 1 || i == 2 )){ quadrat_2.push_back(sudoku_zeile[j]); }
      if((j >= 6 && j < 9) && (i == 0 || i == 1 || i == 2 )){ quadrat_3.push_back(sudoku_zeile[j]); }

      if((j >= 0 && j < 3) && (i == 3 || i == 4 || i == 5 )){ quadrat_4.push_back(sudoku_zeile[j]); }
      if((j >= 3 && j < 6) && (i == 3 || i == 4 || i == 5 )){ quadrat_5.push_back(sudoku_zeile[j]); }
      if((j >= 6 && j < 9) && (i == 3 || i == 4 || i == 5 )){ quadrat_6.push_back(sudoku_zeile[j]); }

      if((j >= 0 && j < 3) && (i == 6 || i == 7 || i == 8 )){ quadrat_7.push_back(sudoku_zeile[j]); }
      if((j >= 3 && j < 6) && (i == 6 || i == 7 || i == 8 )){ quadrat_8.push_back(sudoku_zeile[j]); }
      if((j >= 6 && j < 9) && (i == 6 || i == 7 || i == 8 )){ quadrat_9.push_back(sudoku_zeile[j]); }

      if((j >= 1 && j < 4) && (i == 1 || i == 2 || i == 3 )){ hyper_1.push_back(sudoku_zeile[j]); }
      if((j >= 5 && j < 8) && (i == 1 || i == 2 || i == 3 )){ hyper_2.push_back(sudoku_zeile[j]); }
      if((j >= 1 && j < 4) && (i == 5 || i == 6 || i == 7 )){ hyper_3.push_back(sudoku_zeile[j]); }
      if((j >= 5 && j < 8) && (i == 5 || i == 6 || i == 7 )){ hyper_4.push_back(sudoku_zeile[j]); }
    }
  }

  std::vector <std::vector <char>> sammler_quadrat_hyper;

  sammler_quadrat_hyper.push_back(hyper_1);
  sammler_quadrat_hyper.push_back(hyper_2);
  sammler_quadrat_hyper.push_back(hyper_3);
  sammler_quadrat_hyper.push_back(hyper_4);

  zeile -= 1;
  spalte -=1;

  if((zeile == 0 || zeile <= 2) && (spalte == 0 || spalte <= 2)){
    for (size_t i = 0; i < quadrat_1.size(); i++) {
      if( quadrat_1[i] == wert ) {
        hat_wert = true;
      }
    }

  } else if((zeile == 0 || zeile <= 2) && (spalte == 3 || spalte <= 5)){
    for (size_t i = 0; i < quadrat_2.size(); i++) {
      if( quadrat_2[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 0 || zeile <= 2) && (spalte == 6 || spalte <= 8)){
    for (size_t i = 0; i < quadrat_3.size(); i++) {
      if( quadrat_3[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 3 || zeile <= 5) && (spalte == 0 || spalte <= 2)){
    for (size_t i = 0; i < quadrat_4.size(); i++) {
      if( quadrat_4[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 3 || zeile <= 5) && (spalte == 3 || spalte <= 5)){
        for (size_t i = 0; i < quadrat_5.size(); i++) {
      if( quadrat_5[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 3 || zeile <= 5) && (spalte == 6 || spalte <= 8)){
    for (size_t i = 0; i < quadrat_6.size(); i++) {
      if( quadrat_6[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 6 || zeile <= 8) && (spalte == 0 || spalte <= 2)){
    for (size_t i = 0; i < quadrat_7.size(); i++) {
      if( quadrat_7[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 6 || zeile <= 8) && (spalte == 3 || spalte <= 5)){
    for (size_t i = 0; i < quadrat_8.size(); i++) {
      if( quadrat_8[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile == 6 || zeile <= 8) && (spalte == 6 || spalte <= 8)){
    for (size_t i = 0; i < quadrat_9.size(); i++) {
      if( quadrat_9[i] == wert ) {
        hat_wert = true;
      }
    }
  }

  if((zeile >= 1 && zeile <= 3) && (spalte >= 1 && spalte <= 3)){
    for (size_t i = 0; i < hyper_1.size(); i++) {
      if( hyper_1[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile >= 1 && zeile <= 3) && (spalte >= 5 && spalte <= 7)){
    for (size_t i = 0; i < hyper_2.size(); i++) {
      if( hyper_2[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile >= 5 && zeile <= 7) && (spalte >= 1 && spalte <= 3)){
    for (size_t i = 0; i < hyper_3.size(); i++) {
      if( hyper_3[i] == wert ) {
        hat_wert = true;
      }
    }

  }else if((zeile >= 6 && zeile <= 8) && (spalte >= 5 && spalte <= 7)){
    for (size_t i = 0; i < hyper_4.size(); i++) {
      if( hyper_4[i] == wert ) {
        hat_wert = true;
      }
    }
  }
  return hat_wert;
}

