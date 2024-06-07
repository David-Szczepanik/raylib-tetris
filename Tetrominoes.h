#pragma once
#include <cassert>
#include "Vec2.h"
#include "raylibCpp.h"
#include "Board.h"

class Tetromino {
public:
  enum class Rotation {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

public:
  // Pointers to arrays is not safe as std::vectors
  Tetromino(const bool* shape, int dimension, Color color, const Board& board);
  void RotateClockwise();
  void RotateCounterClockwise();
  void Draw() const;
  void MoveDown();
  void MoveLeft();
  void MoveRight();
  Vec2<int> boardPos;

private:
  // Vec2<int> boardPos;
  Rotation currentRotation;
  const bool* shape;
  const int dimension;
  const Color color;
  const Board& board;
};

class Straight : public Tetromino {
public:
  Straight(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  // Static one copy in whole program
  static constexpr bool shape[] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
  };
  static constexpr int dimension = 4;
  static constexpr Color color = SKYBLUE;
};

class Square : public Tetromino {
public:
  Square(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    1, 1,
    1, 1
  };
  static constexpr int dimension = 2;
  static constexpr Color color = YELLOW;
};

class Tee : public Tetromino {
public:
  Tee(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    0, 1, 0,
    1, 1, 1,
    0, 0, 0
  };
  static constexpr int dimension = 3;
  static constexpr Color color = MAGENTA;
};

class Jay : public Tetromino {
public:
  Jay(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    1, 0, 0,
    1, 1, 1,
    0, 0, 0
  };
  static constexpr int dimension = 3;
  static constexpr Color color = DARKBLUE;
};

class El : public Tetromino {
public:
  El(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    0, 0, 1,
    1, 1, 1,
    0, 0, 0
  };
  static constexpr int dimension = 3;
  static constexpr Color color = ORANGE;
};

class SkewS : public Tetromino {
public:
  SkewS(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    0, 1, 1,
    1, 1, 0,
    0, 0, 0
  };
  static constexpr int dimension = 3;
  static constexpr Color color = GREEN;
};

class SkewZ : public Tetromino {
public:
  SkewZ(const Board& board)
    :
    Tetromino(shape, dimension, color, board) {
    static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
  }

private:
  static constexpr bool shape[] = {
    1, 1, 0,
    0, 1, 1,
    0, 0, 0
  };
  static constexpr int dimension = 3;
  static constexpr Color color = RED;
};
