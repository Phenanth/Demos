#include "head1.h"

int main() {
	int num = InputData();
	while (num != -1) {
		STACKPOINTER result = Conversion(num);
		PrintStack(result);
		num = InputData();
	}
	printf("%s\n", "Bye!");
	return 0;
}
