#include <iostream>
using namespace std;
//Hacer el reversi con una matriz de 8x8
//Solo verificar arriba,abajo,izq,der; (Diagonales para los cracks)
//De preferencia hacer que solo se pueda jugar en coordenadas adyacentes

void initializeBoard(int** Tablero) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Tablero[i][j] = 0;
        }
    }
    Tablero[3][3] = 1;
    Tablero[3][4] = 2;
    Tablero[4][3] = 2;
    Tablero[4][4] = 1;
}

void imprimir_tablero(int** Tablero){

    char coords [8]= {'A','B','C','D','E','F','G','H'};
    cout << "  | ";
    for (int x=1 ; x<9 ; x++ ){cout << x << " | ";}
    cout << endl ;
    for (int i=0;i<8;i++){
        cout << coords [i] << " | ";
        for (int j=0;j<8;j++){
            if ( Tablero[i][j] == 0){
                cout << " " << " | ";
            }
            else if ( Tablero[i][j] == 1){
                cout << "X" << " | ";
            }
            else {
                cout << "O" << " | ";
            }
        }
        cout << endl;
    }
}

void makeMove(int ** Tablero, int row, int col, int player) {
    Tablero[row][col] = player;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        bool foundOpponent = false;
        while (x >= 0 && x < 8 && y >= 0 && y < 8 && Tablero[x][y] != 0) {
            if (Tablero[x][y] != player) {
                foundOpponent = true;
            }
            else if (foundOpponent) {
                // Voltear fichas del oponente
                int flipX = row + dx[i];
                int flipY = col + dy[i];
                while (flipX != x || flipY != y) {
                    Tablero[flipX][flipY] = player;
                    flipX += dx[i];
                    flipY += dy[i];
                }
                break;
            }
            else {
                break;
            }
            x += dx[i];
            y += dy[i];
        }
    }
}

bool isValidMove(int** Tablero, int row, int col, int player) {
    if (Tablero[row][col] != 0) {
        return false;
    }

    bool valid = false;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        bool foundOpponent = false;
        while (x >= 0 && x < 8 && y >= 0 && y < 8 && Tablero[x][y] != 0) {
            if (Tablero[x][y] != player) {
                foundOpponent = true;
            }
            else if (foundOpponent) {
                valid = true;
                break;
            }
            else {
                break;
            }
            x += dx[i];
            y += dy[i];
        }
    }

    return valid;
}

bool isBoardFull(int** board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void countPieces(int** Tablero, int& blackCount, int& whiteCount) {
    blackCount = 0;
    whiteCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (Tablero[i][j] == 1) {
                blackCount++;
            }
            else if (Tablero[i][j] == 2) {
                whiteCount++;
            }
        }
    }
}

int main() {
    int ** Tablero = new int *[8];
    for (int i = 0; i < 8; i++) {
        Tablero[i] = new int [8];
    }

    initializeBoard(Tablero);
    imprimir_tablero(Tablero);

    char current_player = 'X';
    int currentPlayer = 1;

    while (!isBoardFull(Tablero)) {

        cout << "JUGADOR -" << current_player << "- ES TU TURNO" << endl;
        char row;
        int col;
        cout << "INGRESA UNA FILA (A-H):";
        cin >> row;
        row = toupper(row) - 'A';
        cout << "INGRESA UNA COLUMNA (1-8):";
        cin >> col;
        col -= 1;

        if (row >= 0 && row < 8 && col >= 0 && col < 8 && isValidMove(Tablero, row, col, currentPlayer)) {
            makeMove(Tablero, row, col, currentPlayer);
            cout << "\n\n";
            imprimir_tablero(Tablero);
            int blackCount, whiteCount;
            countPieces(Tablero, blackCount, whiteCount);
            cout << "*: " << blackCount << endl;
            cout << "O: " << whiteCount << endl;
            currentPlayer = currentPlayer+1;
            if (currentPlayer>2){
                currentPlayer=1;
            }
            if (currentPlayer==1){
                current_player = 'X';
            } else {
                current_player = 'O';
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    int blackCount, whiteCount;
    countPieces(Tablero, blackCount, whiteCount);

    cout << "FIN DEL JUEGO" << endl;
    cout << "Piezas negras: " << blackCount << endl;
    cout << "Piezas blancas: " << whiteCount << endl;
    if (blackCount > whiteCount) {
        cout << "EL JUGADOR X (Negras)  GANA" << endl;
    } else if (whiteCount > blackCount) {
        cout << "EL JUGADOR O (Blancas) GANA" << endl;
    } else {
        cout << "EMPATE" << endl;
    }

    //Delete del los new int
    for (int i = 0; i < 8; i++) {
        delete[] Tablero[i];
    }
    delete[] Tablero;

    return 0;
}