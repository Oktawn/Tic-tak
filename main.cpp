#include "tic_tac.cpp"

int main()
{
    printf("Hello, I invite you to play the game tic-tac-toe\n"
           "To start, select the required field size: ");
    int size;
    std::cin >> size;
    Tic_Tac game(size);
    std::cout << "table created\n";
    game.show_table();
    game.display();
    std::cout << "Bye\n";
    system("pause>nul");
    return 0;
}
