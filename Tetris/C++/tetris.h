/**
 * @file tetris.h
 * @author your name (you@domain.com)
 * @brief Pablo Pérez González (alu0101318318@ull.edu.es)
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

const int M = 20;
const int N = 10;

int field[M][N] = {0};

struct Point {
  int x, y;
}
a[4], b[4];
// b is a copy of a

int figures[7][4] = {
  1, 3, 5, 7,  // I
  2, 4, 5, 7,  // Z
  3, 5, 4, 6,  // S
  3, 5, 4, 7,  // T
  2, 3, 5, 7,  // L
  3, 5, 7, 6,  // J
  2, 3, 4, 5,  // O
};


bool check() {
  for (int i = 0; i < 4; i++) {
    if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) {
      return 0;
    } else if (field[a[i].y][a[i].x]) {
      return 0;
    }
  }
  return 1;
}

#endif  // TETRIS_H_
