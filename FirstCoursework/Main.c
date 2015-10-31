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

	printf("Моля, направете своя избор.\n");
	printf("1 - За четене от файл и записваме във файл.\n");
	printf("2 - За четене от файл и извеждане на екрана.\n");
	printf("3 - За четене от клавиатурата и записваме във файл.\n");
	printf("4 - За четене от клавиатурата и извеждане на екрана.\n");

	
	int choice;
	char file_path[250];
	int equal_sign_count;


	printf("Вашият избор е: ");
	do{
		scanf_s("%d", &choice);		
		switch (choice)
		{
		case 1:
			printf("За четене от файл и записваме във файл.\n");
			break;
		case 2:
			printf("За четене от файл и извеждане на екрана.\n"); // Temp
			//TODO Clear Screen
			
			//TODO Check For Exeption When Reading From File or incorect Input !!! Check scanf return
			printf("Въведете пътя към файла, който искате да отворите (.C) .\n");
			printf("Пътят е: ");
			scanf("%s", &file_path);

			equal_sign_count = count_equal_sign_in_file(file_path);

			printf("\n\n");
			printf("Операцията за присвояване е използвана %d пъти.\n", equal_sign_count);


			break;
		case 3:
			printf("За четене от клавиатурата и записваме във файл.\n");
			break;
		case 4:
			printf("За четене от клавиатурата и извеждане на екрана.\n");
			break;
		default:
			printf("Вашият избор не е от посочените в менюто (1-4): ");
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