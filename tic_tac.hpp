#pragma once
#include <iostream>
#include <string>
#include <vector>

class Tic_Tac
{
private:
    std::vector<std::vector<char>> table;
    static int win_x;
    static int win_o;
    int count;
    std::string step(short x, short y) noexcept;
    bool check_win(char &ch) noexcept;
    bool check_draw() noexcept;

public:
    explicit Tic_Tac(int size);
    void show_table() noexcept;
    void display();
};
