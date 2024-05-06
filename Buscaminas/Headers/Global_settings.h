#pragma once
/* ---------- Size of the window ---------- */
//Window size in EASY mode
constexpr unsigned int e_heigth = 260;
constexpr unsigned int e_width = 260;
//Window size in Medium mode
constexpr unsigned int m_heigth = 325;
constexpr unsigned int m_width = 325;
//Window size in HARD mode
constexpr unsigned int h_heigth = 385;
constexpr unsigned int h_width = 385;

/* ---------- GAME GRID ---------- */
/*
 *Define the number of COLUMNS and ROWS base on game difficulty
 *
 * Easy: 6 COLS and 6 ROWS
 * MEDIUM: 8 COLS and 8 ROWS
 * HARD: 12 COLS and 12 ROWS
 */

// Grid for EASY mode
constexpr unsigned int E_COLMS = 6;
constexpr unsigned int E_ROWS = 6;
// Grid for MEDIUM mode
constexpr unsigned int M_COLMS = 8;
constexpr unsigned int M_ROWS = 8;
// Grid for HARD mode
constexpr unsigned int H_COLMS = 10;
constexpr unsigned int H_ROWS = 10;
