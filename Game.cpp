#include <cassert>
#include "Game.h"
#include <raylib.h>

#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
  :
  board(settings::boardPosition,
        settings::boardWidthHeight,
        settings::cellSize,
        settings::padding),
  tetromino(board)
// Assert
{
  assert(!GetWindowHandle()); // If assertion triggers : Window is already opened
  SetTargetFPS(fps);
  InitWindow(width, height, title.c_str());
  // tetromino.RotateClockwise();
}

Game::~Game() noexcept {
  assert(GetWindowHandle()); // If assertion triggers : Window is already closed
  CloseWindow();
}

bool Game::GameShouldClose() const {
  return WindowShouldClose();
}

void Game::Tick() {
  BeginDrawing();
  Update();
  Draw();
  EndDrawing();
}

void Game::Draw() {
  ClearBackground(BLACK);
  board.Draw();
  tetromino.Draw();
}

void Game::Update() {
  if (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_UP)) {
    tetromino.RotateClockwise();
  }
  if (IsKeyPressed(KEY_Q)) {
    tetromino.RotateCounterClockwise();
  }
}
