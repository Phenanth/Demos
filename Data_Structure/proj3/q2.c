#include "head2.h"


int main() {
	char str[MAX_TERMS];
	char* stkp = Create();
	printf("%s", "Please input the expression: ");
	scanf("%s", str);
	while (strcmp(str, "-1")) {
		printf("%s", "The bracket of the expression is matching ");
		if (Matching(str)) {
			printf("%s\n", "OK!");
		}
		else printf("%s\n", "ERROR!");
		printf("%s", "Please input the expression: ");
		scanf("%s", str);
	}
	if (strcmp(str, "-1") == 0) {
		printf("%s\n", "Bye!");
	}
	return 0;
}

