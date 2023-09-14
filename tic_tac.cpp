#include "tic_tac.hpp"

Tic_Tac::Tic_Tac(int size)
{
    table.resize(size);
    for (auto &i : table)
        i.resize(size, ' ');
    count = 0;
}

void Tic_Tac::show_table() noexcept
{
    for (auto i = 0; i < table.size(); i++)
    {
        for (auto j = 0; j < table.size(); j++)
        {
            if (j != table.size())
                std::cout << std::left << table[i][j] << "|";
            else
                std::cout << std::left << table[i][j];
        }
        std::cout << '\n'
                  << std::left << std::string(table.size() * 2, '-') << "\n";
    }
}

void Tic_Tac::display()
{
    char steps = 'X';
    int x, y;
    while (!check_draw())
    {
        std::cout << "\nstep: " << steps << '\n';
        std::cout << "enter the coordinates of the field where you want to go\n";
        std::cout << "x and y: ";
        std::cin >> x >> y;
        if (step(x, y).compare(""))
        {
            std::cout << step(x, y);
            std::cout << "try again\n";
            continue;
        }
        else
        {
            if (steps == 'X')
            {
                table[x][y] = steps;
            }
            else
            {
                table[x][y] = 'O';
            }
        }
        if (check_win(steps))
        {
            std::cout << "the player won by playing for " << steps << '\n';
            return;
        }
        steps = steps == 'X' ? 'O' : 'X';
        show_table();
    }
    std::cout << "the game ended in a draw\n";
}

std::string Tic_Tac::step(short x, short y) noexcept
{
    if ((x < 0 || x > (table.size() - 1)) || (y < 0 || (y > table.size() - 1)))
        return "error index\n";
    else if (table[x][y] != ' ')
        return "the field is already occupied\n";
    count++;
    return "";
}

bool Tic_Tac::check_win(char &ch) noexcept
{
    int sizes = table.size();
    bool flag = true;
    // check win rows
    for (int row = 0; row < sizes; row++)
    {
        for (int col = 0; col < sizes; col++)
        {
            if (table[row][col] != ch)
                flag = false;
        }
        if (flag)
            return true;
    }

    // check win colomns
    for (int col = 0; col < sizes; col++)
    {
        for (int row = 0; row < sizes; row++)
        {
            if (table[row][col] != ch)
                flag = false;
        }
        if (flag)
            return true;
    }
    // check win main diagonal
    for (int i = 0; i < sizes; i++)
        if (table[i][i] != ch)
            flag = false;
    if (flag)
        return true;

    // check win second diagonal
    for (int i = 0, j = sizes - 1; i < sizes; i++, j--)
    {
        if (table[i][j] != ch)
            return false;
    }
    if (flag)
        return true;
    return flag;
}

bool Tic_Tac::check_draw() noexcept
{
    int max = table.size() * table.size();
    if (count == max)
        return true;
    return false;
}
