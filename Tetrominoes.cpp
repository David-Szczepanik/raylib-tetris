#include "Tetrominoes.h"

#include <iostream>

Tetromino::Tetromino(const bool* shape, int dimension, Color color, const Board& board)
  :
  shape(shape),
  dimension(dimension),
  color(color),
  boardPos(board.GetWidth() / 2 - dimension / 2, 0),
  board(board),
  currentRotation(Rotation::UP) {
}

void Tetromino::RotateClockwise() {
  currentRotation = Rotation((int(currentRotation) + 1) % 4);
}

void Tetromino::RotateCounterClockwise() {
  currentRotation = Rotation((int(currentRotation) + 3) % 4);
}

void Tetromino::MoveDown() {
  boardPos = boardPos + Vec2<int>(0, 1);
}

void Tetromino::MoveLeft() {
  boardPos = boardPos + Vec2<int>(-1, 0);
}

void Tetromino::MoveRight() {
  boardPos = boardPos + Vec2<int>(1, 0);
}

void Tetromino::Draw() const {
  for (int y = 0; y < dimension; ++y) {
    for (int x = 0; x < dimension; ++x) {
      bool cell = false;
      switch (currentRotation) {
      case Rotation::UP:
        cell = shape[y * dimension + x];
        break;
      case Rotation::RIGHT:
        cell = shape[dimension * (dimension - 1) - dimension * x + y];
        break;
      case Rotation::DOWN:
        cell = shape[(dimension * dimension - 1) - dimension * y - x];
        break;
      case Rotation::LEFT:
        cell = shape[dimension - 1 + dimension * x - y];
        break;
      default:
        break;
      }
      if (cell) {
        board.DrawCell(boardPos + Vec2<int>{x, y}, color);
      }
    }
  }
}
