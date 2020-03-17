#include <stdio.h>

int main() {
	char sentence[] = "date : 06-06-2020";
	char str[50];
	int year, month, day;

	sscanf(sentence, "%s : %2d-%2d-%4d", str, &day, &month, &year);
	printf("%s -> %02d-%02d-%4d\n", str, day, month, year);
	return 0;
}