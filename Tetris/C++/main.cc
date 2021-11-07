/**
 * @file main.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief Main del juego del Tetris en C++
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "./tetris.h"


int main() {
  srand(time(0));
  sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");
  sf::Texture t1, t2, t3;
  t1.loadFromFile("images/tiles.png");
  t2.loadFromFile("images/background.png");
  t3.loadFromFile("images/frame.png");
  sf::Sprite s(t1), background(t2), frame(t3);
  // dx is de x movement
  int dx = 0, colorNum = 1 + rand() % 7;
  bool rotate = 0;
  float timer = 0, delay = 0.3;
  sf::Clock clock;
  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    sf::Event e;
    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed) {
        window.close();
      }
      if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Up) {
          rotate = true;
        } else if (e.key.code == sf::Keyboard::Left) {
          dx =- 1;
        } else if (e.key.code == sf::Keyboard::Right) {
          dx = 1;
        }
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      delay = 0.05;
    }

    //// <- Move -> ///
    for (int i = 0; i < 4; i++) {
      b[i] = a[i];
      a[i].x += dx;
    }
    if (!check()) {
      for (int i = 0; i < 4; i++) {
        a[i] = b[i];
      }
    }

    ////// Rotate//////
    if (rotate) {
      Point p = a[1];  // center of rotation
      for (int i = 0; i < 4; i++) {
        int x = a[i].y - p.y;
        int y = a[i].x - p.x;
        a[i].x = p.x - x;
        a[i].y = p.y + y;
      }
      if (!check()) {
        for (int i = 0; i < 4; i++) {
          a[i] = b[i];
        }
      }
    }

    /////// Tick//////
    if (timer > delay) {
      for (int i = 0; i < 4; i++) {
        b[i] = a[i];
        a[i].y += 1;  // Go down 1 position by time
      }
      if (!check()) {
        for (int i = 0; i < 4; i++) {
          field[b[i].y][b[i].x] = colorNum;
        }
        colorNum = 1 + rand() % 7;
        int n = rand() % 7;
        for (int i = 0; i < 4; i++) {
          a[i].x = figures[n][i] % 2;
          a[i].y = figures[n][i] / 2;
        }
      }
      timer = 0;
    }

    /////// check lines//////////
    int k = M - 1;
    for (int i = M - 1; i > 0; i--) {
      int count = 0;
      for (int j = 0; j < N; j++) {
        if (field[i][j]) {
          count++;
        }
        field[k][j] = field[i][j];
      }
      if (count < N) {
        k--;
      }
    }

    dx = 0;
    rotate = 0;
    delay = 0.3;

    ///////// draw//////////
    window.clear(sf::Color::White);
    window.draw(background);

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (field[i][j] == 0) {
          continue;
        }
        s.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
        s.setPosition(j * 18, i * 18);
        s.move(28, 31);  // offset
        window.draw(s);
      }
    }
    for (int i = 0; i < 4; i++) {
      s.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
      s.setPosition(a[i].x * 18, a[i].y * 18);
      s.move(28, 31);  // offset
      window.draw(s);
    }

    window.draw(frame);
    window.display();
  }
  return 0;
}
