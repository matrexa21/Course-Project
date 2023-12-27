#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int calculateGridSize(int difficulty) {
    int size;
    if (difficulty == 1) {
        size = 5; // ������ ������� ���������
    }
    else if (difficulty == 2) {
        size = 7; // ������� ������� ���������
    }
    else {
        size = 9; // ������� ������� ���������
    }
    return size;
}

void printGrid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void createRandomGrid(int** grid, int size, int difficulty) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (difficulty == 1) {
                grid[i][j] = rand() % 2; // ������ ������� ���������
            }
            else if (difficulty == 2) {
                grid[i][j] = rand() % 3; // ������� ������� ���������
            }
            else {
                grid[i][j] = rand() % 4; // ������� ������� ���������
            }
        }
    }
    printGrid(grid, size);
}

void fillGridManually(int** grid, int size) {
    printf("������� �������� �������� ����:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printGrid(grid, size);
}
void writeGridToFile(int** grid, int size) {
    FILE* file;
    file = fopen("grid.txt", "w");
    if (file == NULL) {
        printf("������ ��� �������� �����.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", grid[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    int difficulty;
    int size;
    printf("����� ���������� � ����������� �������.\n");
    printf("������ �����������: ���������� ���� ����� ����������� (������ ��� �����) �� ��������.\n");
    printf("��� ������� ����:\n");
    printf("������ ������ �������� �������, ������������ �� ����������� � �� ���������.\n");
    printf("����� ������ ������ ��������� ���������� ������ �����, ������������ �� ���� ��������������� � ��� ��������.\n");
    printf("���� ������ ������ ��� �����, � ��� ����� ������������� ������� ������ ����� ����� �������.\n");

    do {
        printf("�������� ��������:\n");
        printf("1. ������� ��������� ������� ����\n");
        printf("2. ��������� ������� ���� �������\n");
        printf("3. ������� ������� ���������\n");
        printf("4. �����\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("�������� ������� ��������� (1 - ������, 2 - �������, 3 - �������): ");
            scanf("%d", &difficulty);
            size = calculateGridSize(difficulty);
            int** grid = (int**)malloc(size * sizeof(int*));
            for (int i = 0; i < size; i++) {
                grid[i] = (int*)malloc(size * sizeof(int));
            }
            createRandomGrid(grid, size, difficulty);
            writeGridToFile(grid, size); // ���������� ��������������� ������� ���� � ����
            break;
        case 2:
            printf("�������� ������� ��������� (1 - ������, 2 - �������, 3 - �������): ");
            scanf("%d", &difficulty);
            size = calculateGridSize(difficulty);
            int** manualGrid = (int**)malloc(size * sizeof(int*));
            for (int i = 0; i < size; i++) {
                manualGrid[i] = (int*)malloc(size * sizeof(int));
            }
            fillGridManually(manualGrid, size);
            writeGridToFile(manualGrid, size); // ���������� ����������� ������� ������� ���� � ����
            break;
        case 3:
            printf("�������� ������� ��������� (1 - ������, 2 - �������, 3 - �������): ");
            scanf("%d", &difficulty);
            break;
        case 4:
            printf("���� ��������.\n�� ��������.\n");
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    } while (choice != 4);

    return 0;
}