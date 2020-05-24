#include<iostream>
#include<conio.h>
#include<ctime>

using namespace std;
bool GameOver;
const int  width = 20;
const int  height = 20;
int tailx[100], taily[100];
int nT=2;
int x, y, fx, fy, score;


enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;


void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fx = rand() % width;
	fy = rand() % height;
	score = 0;
}
void Draw() {
	system("cls");
	for (int i = 0; i < width+2; i++)
		cout <<"#" ;
	cout << endl;	
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "#";
			}
			if (i == y && j == x) {
				cout << 'O';
			}
			else if (i == fy && j == fx) {
				cout << 'F';
			}
			else {
				bool print = false;
				for (int k = 0; k < nT; k++) {
					if (tailx[k] == j && taily[k] == i) {
						cout << 'o';
						print = true;
					}

				}
				if (!print)
				{
                  cout << " ";
				}
		         
			}

			if (j == width - 1) {
				cout << "#";
			}
		}
			cout << endl;
		
	}
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << "\n" << "score" << score;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'q':
			GameOver=true;
			break;
			
		}
	}
}
void Logic() {
	int a = x;
	int b = y;
    	int px = tailx[2];
		int py = taily[2];
		int pr2x, pr2y;
	    tailx[0] = a;
	    taily[0] = b;
		tailx[1] = tailx[0];
		taily[1] = taily[0];
		for (int i = 1; i < nT; i++)
		{
			pr2x = tailx[i];
			pr2y = taily[i];
			tailx[i] = px;
			taily[i] = py;
			px = pr2x;
			py = pr2y;


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
	if (x > width ) 
		x = 0;
	
	if (y > height)
		y = 0;
	if (x < 0)
		x = width;
	if (y < 0)
		y = height;
	if (x == fx && y == fy) {
		score += 10;
		fy = rand() % height;
		fx = rand() % width;
		nT++;

	}
}
int main() {
	srand(time(0));
    Setup();
	while (!GameOver)
	{
		Draw();
		Logic();
		Input();
		
	}

}
