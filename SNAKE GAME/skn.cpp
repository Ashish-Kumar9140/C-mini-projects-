#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
Direction dir;

void Setup()
{
    gameOver = false;
    dir = STOP;

    x = WIDTH / 2;
    y = HEIGHT / 2;

    srand(time(0));
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;

    score = 0;
    nTail = 0;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++)
    {

        for (int j = 0; j < WIDTH; j++)
        {

            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "*";
            else
            {

                bool print = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                        break;
                    }
                }

                if (!print)
                    cout << " ";
            }

            if (j == WIDTH - 1)
                cout << "#";
        }

        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";

    cout << "\nScore : " << score << endl;
    cout << "Press X to Exit\n";
}

void Input() {

    if (_kbhit()) {

        int ch = _getch();

        // Arrow keys
        if (ch == 0 || ch == 224) {

            ch = _getch();

            switch (ch) {

            case 72:   // Up
                if (dir != DOWN)
                    dir = UP;
                break;

            case 80:   // Down
                if (dir != UP)
                    dir = DOWN;
                break;

            case 75:   // Left
                if (dir != RIGHT)
                    dir = LEFT;
                break;

            case 77:   // Right
                if (dir != LEFT)
                    dir = RIGHT;
                break;
            }
        }

        // Exit
        else if (ch == 'x' || ch == 'X') {
            gameOver = true;
        }
    }
}

void Logic()
{

    int prevX = tailX[0];
    int prevY = tailY[0];

    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {

        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {

    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    // Wall Collision
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = true;

    // Self Collision
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Fruit
    if (x == fruitX && y == fruitY)
    {

        score += 10;

        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;

        nTail++;
    }
}

int main()
{

    Setup();
    cout << "=============================\n";
cout << "        SNAKE GAME\n";
cout << "=============================\n\n";

cout << "Controls:\n";
cout << "↑  Move Up\n";
cout << "↓  Move Down\n";
cout << "←  Move Left\n";
cout << "→  Move Right\n";
cout << "X  Exit Game\n\n";

cout << "Press any key to start...";
_getch();

    while (!gameOver)
    {

        Draw();
        Input();
        Logic();

        Sleep(120);
    }

    cout << "\nGame Over!\n";
    cout << "Final Score : " << score << endl;

    return 0;
}