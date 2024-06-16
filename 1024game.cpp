#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

char run = 'q';
int a[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

/***********Instructions**********/
void instructions() {
    cout << endl << "Welcome to the 1024 game.";
    cout << endl << "\tBest of luck and Enjoy :)" << endl;
    cout << endl << "INSTRUCTIONS: " << endl;
    cout << "1. Use arrow keys for movement" << endl;
    cout << "2. Press 'q' anytime to quit the game" << endl;
}

/**********Print Grid*************/
void grid() {
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] > 0) {
                cout << "|\t" << a[i][j] << "\t";
            } else {
                cout << "|\t\t";
            }
        }
        cout << "|" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
}

/**********NEW RANDOM NUMBER FORMATION AT EVERY MOVE*******/
void newR() {
    int p, q;
    while (true) {
        p = rand() % 4;
        q = rand() % 4;
        if (a[p][q] == 0) {
            a[p][q] = (rand() % 2 + 1) * 2;
            break;
        }
    }
}

/********MAIN GRID WITH TWO RANDOM NUMBERS*********/
void display() {
    int k = rand() % 4;
    int l = rand() % 4;
    int m = rand() % 4;
    int n = rand() % 4;
    cout << endl << "\t########### YOU CAN START PLAYING YOUR GAME ###########" << endl << endl;
    cout << "-----------------------------------------------------------------" << endl;
    a[k][l] = (rand() % 2 + 1) * 2;
    if (k != m || l != n) {
        a[m][n] = (rand() % 2 + 1) * 2;
    }
    grid();
}

/******** selection of buttons *********/
/*******LEFT KEY PRESSED*****/
void left() {
    cout << endl << "Left key pressed." << endl;
    for (int i = 0; i < 4; i++) {
        int k = i, l = 0;
        for (int j = 1; j < 4; j++) {
            if (a[i][j] != 0) {
                if (a[i][j - 1] == a[i][j] || a[i][j - 1] == 0) {
                    if (a[i][j] == a[k][l]) {
                        a[k][l] *= 2;
                        a[i][j] = 0;
                    } else {
                        if (a[k][l] == 0) {
                            a[k][l] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[k][++l] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else l++;
            }
        }
    }
    newR();
    grid();
}

/*******RIGHT KEY PRESSED*****/
void right() {
    cout << endl << "Right key pressed." << endl;
    for (int i = 0; i < 4; i++) {
        int k = i, l = 3;
        for (int j = 2; j >= 0; j--) {
            if (a[i][j] != 0) {
                if (a[i][j + 1] == a[i][j] || a[i][j + 1] == 0) {
                    if (a[i][j] == a[k][l]) {
                        a[k][l] *= 2;
                        a[i][j] = 0;
                    } else {
                        if (a[k][l] == 0) {
                            a[k][l] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[k][--l] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else l--;
            }
        }
    }
    newR();
    grid();
}

/*******UP KEY PRESSED*****/
void up() {
    cout << endl << "Up key pressed." << endl;
    for (int j = 0; j < 4; j++) {
        int k = 0, l = j;
        for (int i = 1; i < 4; i++) {
            if (a[i][j] != 0) {
                if (a[i - 1][j] == a[i][j] || a[i - 1][j] == 0) {
                    if (a[i][j] == a[k][l]) {
                        a[k][l] *= 2;
                        a[i][j] = 0;
                    } else {
                        if (a[k][l] == 0) {
                            a[k][l] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[++k][l] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else k++;
            }
        }
    }
    newR();
    grid();
}

/*******DOWN KEY PRESSED*****/
void down() {
    cout << endl << "Down key pressed." << endl;
    for (int j = 0; j < 4; j++) {
        int k = 3, l = j;
        for (int i = 2; i >= 0; i--) {
            if (a[i][j] != 0) {
                if (a[i + 1][j] == a[i][j] || a[i + 1][j] == 0) {
                    if (a[i][j] == a[k][l]) {
                        a[k][l] *= 2;
                        a[i][j] = 0;
                    } else {
                        if (a[k][l] == 0) {
                            a[k][l] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[--k][l] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else k--;
            }
        }
    }
    newR();
    grid();
}

/*********LOSE GAME FUNCTION******/
int lose() {
    for (int rows = 0; rows < 4; rows++) {
        for (int cols = 0; cols < 4; cols++) {
            if (a[rows][cols] == 0) {
                return 0;
            }
        }
    }
    for (int rows = 0; rows < 4; rows++) {
        for (int cols = 0; cols < 4; cols++) {
            if ((rows > 0 && a[rows][cols] == a[rows - 1][cols]) ||
                (cols > 0 && a[rows][cols] == a[rows][cols - 1]) ||
                (rows < 3 && a[rows][cols] == a[rows + 1][cols]) ||
                (cols < 3 && a[rows][cols] == a[rows][cols + 1])) {
                return 0;
            }
        }
    }
    return 1;
}

/*********WIN FUNCTION*********/
int win() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 1024) {
                return 1;
            }
        }
    }
    return 0;
}

/***********SELECT ANY ARROW KEY TO MOVE**********/
void button() {
    int b;
    while (true) {
        b = _getch();
        if (b == 75) {
            left();
        } else if (b == 80) {
            down();
        } else if (b == 77) {
            right();
        } else if (b == 72) {
            up();
        } else if (b == 113) {
            break;
        }

        if (win()) {
            cout << "You Won :)" << endl;
            break;
        }

        if (lose()) {
            cout << "You lost the game :(" << endl;
            break;
        }
    }
}

int main() {
    srand(time(0));
    instructions();
    display();
    button();
    system("pause");
    return 0;
}
