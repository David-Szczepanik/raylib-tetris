#include "Board.h"
#include <cassert>

Board::Cell::Cell()
  :
  bExists(false),
  c(WHITE) {
}

void Board::Cell::SetColor(Color c_in) {
  c = c_in;
  bExists = true;
}

void Board::Cell::Remove() {
  bExists = false;
}

Color Board::Cell::GetColor() const {
  return c;
}

bool Board::Cell::Exists() const {
  return bExists;
}



Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize, int padding) :
  width(widthHeight.GetX()),
  height(widthHeight.GetY()),
  cellSize(cellsize),
  padding(padding),
  screenPos(screenPos)
// ASSERT
{
  assert(width > 0 && height > 0); // If triggers : The width or height is smaller than 1
  assert(cellSize > 0); // If triggers : The cell size is smaller than 1
  cells.resize(width * height);
}

void Board::SetCell(Vec2<int> pos, Color c) {
  assert(pos.GetX() >= 0 && pos.GetY()>= 0 && pos.GetX() < width&& pos.GetY() < height); // x or y is out of bounds
  cells[pos.GetY() * width + pos.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos) const {
  Color color = cells[pos.GetY() * width + pos.GetX()].GetColor();
  DrawCell(pos,color);
}

void Board::DrawCell(Vec2<int> pos, Color color) const {
  assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height);
  Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
  raycpp::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, color);
}

void Board::DrawBorder() const {
  raycpp::DrawRectangleLinesEx(screenPos - (cellSize / 2), Vec2{width * cellSize, height * cellSize} + cellSize,
                               cellSize / 2, WHITE);
}

void Board::Draw() const {
  for (int iY = 0; iY < height; ++iY) {
    for (int iX = 0; iX < width; ++iX) {
      if (CellExists({iX, iY}))
        DrawCell({iX, iY});
    }
  }
  DrawBorder();
}

bool Board::CellExists(Vec2<int> pos) const {
  return cells[pos.GetY() * width + pos.GetX()].Exists();
}

int Board::GetWidth() const {
  return width;
}

int Board::GetHeight() const {
  return height;
}
