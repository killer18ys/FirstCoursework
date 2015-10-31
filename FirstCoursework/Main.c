#include<stdio.h>
#include<windows.h>
#include<math.h>

#pragma warning(disable:4996)

FILE * fr;

int count_equal_sign_in_line(char line[]);
int count_equal_sign_in_file(char filename[]);


int main(){
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("����, ��������� ���� �����.\n");
	printf("1 - �� ������ �� ���� � ��������� ��� ����.\n");
	printf("2 - �� ������ �� ���� � ��������� �� ������.\n");
	printf("3 - �� ������ �� ������������ � ��������� ��� ����.\n");
	printf("4 - �� ������ �� ������������ � ��������� �� ������.\n");

	
	int choice;
	char file_path[250];
	int equal_sign_count;


	printf("������ ����� �: ");
	do{
		scanf_s("%d", &choice);		
		switch (choice)
		{
		case 1:
			printf("�� ������ �� ���� � ��������� ��� ����.\n");
			break;
		case 2:
			printf("�� ������ �� ���� � ��������� �� ������.\n"); // Temp
			//TODO Clear Screen
			
			//TODO Check For Exeption When Reading From File or incorect Input !!! Check scanf return
			printf("�������� ���� ��� �����, ����� ������ �� �������� (.C) .\n");
			printf("����� �: ");
			scanf("%s", &file_path);

			equal_sign_count = count_equal_sign_in_file(file_path);

			printf("\n\n");
			printf("���������� �� ����������� � ���������� %d ����.\n", equal_sign_count);


			break;
		case 3:
			printf("�� ������ �� ������������ � ��������� ��� ����.\n");
			break;
		case 4:
			printf("�� ������ �� ������������ � ��������� �� ������.\n");
			break;
		default:
			printf("������ ����� �� � �� ���������� � ������ (1-4): ");
			break;
		}
	} while (choice <= 0 || choice > 4);

}


int count_equal_sign_in_file(char filename[]){
	char line[90];
	int total_counter = 0;
	fr = fopen(filename, "rt");

	while (fgets(line, 90, fr) != NULL)
	{
		total_counter += count_equal_sign_in_line(line);
	}

	fclose(fr);
	return total_counter;
}

int count_equal_sign_in_line(char line[]){
	int counter = 0;

	for (int i = 0; line[i] != '\0'; ++i)
	{
		//TODO
		if (line[i] == ' ' && line[i + 1] == '=' && line[i + 2] == ' '){
			counter++;
		}
	}

	return counter;
}