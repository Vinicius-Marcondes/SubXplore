// jogoComput.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// Scroll key tester
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>

void behavior(int key);
void geraMapa(int x, int y);
void printMap();

int mapa[10][10];
int pos[2];

void geraMapa(int x, int y) {
	system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == y && j == x) {
				mapa[i][j] = 1;
			}
			else {
				mapa[i][j] = 0;
			}
		}
	}
	printMap();
}

void printMap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", mapa[i][j]);
		}
		printf("\n");
	}
}

void behavior(int key) {
	int ch1, ch2;
	printf("PRESS A KEY TO CONTINUE \n");
	ch1 = key;
	ch2 = 0;
	if (ch1 == 0xE0) { // a scroll key was pressed
		ch2 = _getch();
		// determine what it was
		switch (ch2)
		{
		case 72:
			printf("UP WAS PRESSED\n");
			if (pos[1] - 1 >= 0) {
				pos[1] -= 1;
				geraMapa(pos[0], pos[1]);
			}
			else {
				printf("n vai dar n");
			}
			break;
		case 80:
			printf("DOWN WAS PRESSED\n");
			if (pos[1] + 1 <= 10) {
				pos[1] += 1;
				geraMapa(pos[0], pos[1]);
			}
			else {
				printf("n vai dar n");
			}
			break;
		case 75:
			printf("LEFT WAS PRESSED\n");
			if (pos[0] - 1 >= 0) {
				pos[0] -= 1;
				geraMapa(pos[0], pos[1]);
			}
			else {
				printf("n vai dar n");
			}
			break;
		case 77:
			printf("RIGHT WAS PRESSED\n");
			if (pos[0] + 1 <= 10) {
				pos[0] += 1;
				geraMapa(pos[0], pos[1]);
			}
			else {
				printf("n vai dar n");
			}
			break;
		default:
			printf("SOME OTHER SCROLL KEY PRESSED: %d %d\n", ch1, ch2); break;
		};
	}
	else
		printf("key pressed: %d %c\n", ch1, ch2);
}
int main() {
	int test = 1;
	int key;
	pos[0] = 0;
	pos[1] = 0;
	geraMapa(pos[0], pos[1]);
	while (true) {
		if (key = _getch()) {
			behavior(key);
		}
	}
	return 0;
}
