#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>



#define MAZE_SIZE 41 // �̷� ũ��   �ݵ�� Ȧ��
#define MIX_COUNT 3  // ���� Ƚ��   �������� �̷ΰ� �������
#define CROSS_PERCENT 35 // ������ Ȯ��(�и�)   �������� �������� ������

using namespace std;

enum {
	OUTER_WALL = -1,
	WALL = 0,
	ROAD = 1,
	FLAG = 2,
	EXIT = 5,
	PLAYER = 10
};
enum {
	EAST = 0,
	WEST,
	SOUTH,
	NORTH
};

int maze[MAZE_SIZE][MAZE_SIZE] = { WALL, };


void CreateMaze();
void dfs(int, int);
void ShowMaze();
void PlayMaze();

int main()
{
	srand((unsigned int)time(NULL));

	CreateMaze();
	PlayMaze();
}


void CreateMaze()
{
	maze[MAZE_SIZE - 2][MAZE_SIZE - 1] = EXIT;
	for (int i = 1; i < MAZE_SIZE; i += 2) // ���ľ� �ϴ� ����Ʈ ����  ������� ����Ʈ ���θ� �����ߵ�
	{
		for (int j = 1; j < MAZE_SIZE; j += 2)
		{
			maze[i][j] = FLAG;
		}
	}

	dfs(1, 1);
}


void dfs(int y, int x) // ��մ� �Լ�
{
	int d1[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //������, ����, �Ʒ�, ��
	int d2[4][2] = { {0,2},{0,-2},{2,0},{-2,0} };


	int dir[4] = { EAST, WEST, SOUTH, NORTH };  // ������ ���� ����
	int i = MIX_COUNT;
	while (i--)  // �� �մ� ������ �������� �ϱ� ���� �������� ����
	{
		swap(dir[rand() % 4], dir[rand() % 4]);
	}


	for (int j = 0; j < 4; j++)
	{
		int dy1 = d1[dir[j]][1], dx1 = d1[dir[j]][0]; // �������� �Ǵ� �Ÿ�
		int dy2 = d2[dir[j]][1], dx2 = d2[dir[j]][0];



		if (x + dx2 >= MAZE_SIZE || x + dx2 < 0 || y + dy2 >= MAZE_SIZE || y + dy2 < 0)   // �迭 ���� �ʰ��� ��ŵ
			continue;

		if (maze[y + dy2][x + dx2] == FLAG) // ���� �ش� ���⿡ ������ ���� ����Ʈ�� �������
		{

			maze[y + dy1][x + dx1] = ROAD; // ���̿� �ִ� ���� ����
			maze[y + dy2][x + dx2] = ROAD;	// ����Ʈ�� ��� �ٲ� 
			dfs(y + dy2, x + dx2);
		}
		else if (maze[y + dy2][x + dx2] == ROAD)
		{
			if (rand() % CROSS_PERCENT == 0) // Ȯ�������� ���� �ִ� ��� ����� (������ ����)
			{
				maze[y + dy1][x + dx1] = ROAD;
			}
		}


	}
	return;
}


void ShowMaze()
{
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			switch (maze[i][j])
			{
			case WALL: cout << "��";
				break;
			case ROAD: cout << "  ";
				break;
			case FLAG: cout << "��";
				break;
			case PLAYER: cout << "��";
				break;
			default: cout << "  ";
			}
		}
		cout << endl;
	}
}


void PlayMaze()
{
	int player_x = 1;
	int player_y = 1;
	maze[player_y][player_x] = PLAYER;

	ShowMaze();
	while (1)
	{
		int key = _getch();
		maze[player_y][player_x] = ROAD;
		switch (key)
		{
		case 'a':
		case 75:
			if (maze[player_y][player_x - 1] == ROAD) player_x--;
			break;
		case 'd':
		case 77:
			if (maze[player_y][player_x + 1] == ROAD) player_x++;
			break;
		case 'w':
		case 72:
			if (maze[player_y - 1][player_x] == ROAD) player_y--;
			break;
		case 's':
		case 80:
			if (maze[player_y + 1][player_x] == ROAD) player_y++;
			break;
		default:
			break;
		}
		maze[player_y][player_x] = PLAYER;
		system("cls");
		ShowMaze();
	}
}