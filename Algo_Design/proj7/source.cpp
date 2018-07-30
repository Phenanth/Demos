#define PART 10000
#define BPART 10000000

// Big number multiply algorithm for a number range from 10000000 to 99999999.
void bigmul_8(long num1, long num2, int x[]) {

	int x1 = num1 % PART;
	int x2 = num1 / PART;
	int y1 = num2 % PART;
	int y2 = num2 / PART;

	int c0 = x1 * y1;
	int c2 = x2 * y2;
	int c1 = (x1 + x2) * (y1 + y2) - c2 - c0;

	x[3] = c0 % PART;
	x[2] = c0 / PART + c1 % PART;
	x[1] = c1 / PART + c2 % PART;
	x[0] = c2 / PART;

	printf("%s\n", "Result of the big number multiply algorithm(8 bit):");
	printArray(x, 4);

}

void printArray(int x[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}

// ```````````````````````````````````````````````````````

string bigmul_recur(string num1, string num2) {

	// Judge if the result is minus.
	bool flag1 = false;
    bool flag2 = false;
    bool flag;

    //cout << num1 << ", " << num2 << endl;

    if (num1.at(0) == '-') {
        flag1 = true;
        num1 = num1.substr(1);
    }
    if (num2.at(0) == '-') {
        flag2 = true;
        num2 = num2.substr(1);
    }
    if ((flag1 && flag2) || (!flag1 && !flag2)) {
        flag = false;
    } else {
        flag = true;
    }

	// Adjust the length of two numbers.
	int minlen = 4;
	
	if (num1.length() > 2 || num2.length() > 2) {
		if (num1.length() > num2.length()) {
			while (num1.length() > minlen) {
				minlen *= 2;
			}
			if (num1.length() != minlen) {
				adjLength(num1, minlen - num1.length());
			}
			adjLength(num2, minlen - num2.length());
		} else {
			while (num2.length() > minlen) {
				minlen *= 2;
			}
			if (num2.length() != minlen) {
				adjLength(num2, minlen - num2.length());
			}
			adjLength(num1, minlen - num1.length());
		}
	}

	if (num1.length() == 1) {
		adjLength(num1, 1);
	}
	if (num2.length() == 1) {
		adjLength(num2, 1);
	}

	// Judge & Calculate.
	int n = num1.length();
	string result;
	string a1, a0, b1, b0;

	if (n > 1) {
        a1 = num1.substr(0, n / 2);
        a0 = num1.substr(n / 2, n);
        b1 = num2.substr(0, n / 2);
        b0 = num2.substr(n / 2, n);
	}
	if (n == 2) {
		int x1 = stringToInt(a1);
		int x2 = stringToInt(a0);
		int y1 = stringToInt(b1);
		int y2 = stringToInt(b0);
        int z = (x1 * 10 + x2) * (y1 * 10 + y2);
		result = intToString(z);
	} else {
		string c2 = bigmul_recur(a1, b1);
        string c0 = bigmul_recur(a0, b0);
        string temp_c1_1 = add(a0, a1);
        string temp_c1_2 = add(b1, b0);
        string temp_c1_3 = add(c2, c0);
        string temp_c1 = bigmul_recur(temp_c1_1, temp_c1_2);
        string c1 = sub(temp_c1, temp_c1_3);
        string s1 = addZero(c1, n / 2);
        string s2 = addZero(c2, n);
        result = add(add(s1, s2), c0);
	}

	if (flag) {
		result.insert(0, "-");
	}

	//cout << "part of the result: " << result << endl;
	
	return result;

}

// Add zeros in front of the string to adjust the length.
void adjLength(string &str, int n) {

	for (int i = 0; i < n; i++) {
		str.insert(0, "0");
	}

}

// Add zeros at the end of the string.
string addZero(string str, int n) {

    string result = str;
    for (int i = 0; i < n; i++)
    	result += "0";

    //cout << "addlastzero:" << result << endl;
    return result;

}

// Remove the front zeros of a string.
void removeZero(string &str) {
	if (str.length() == 1) {
		return;
	}
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '0') {
			cnt++;
		} else {
			break;
		}
	}

	if (cnt == str.length()) {
		str = "0";
	} else {
		str = str.substr(cnt);
	}
}

// Transform a string to an integer.
string intToString(int value) {
	string result;
	stringstream stream;
	stream << value;
	stream >> result;
	return result;
}

// Transform an integer to a string.
int stringToInt(string str) {
	int result;
	stringstream stream(str);
	stream >> result;
	return result;
}

// Add two big numbers.
string add(string x, string y) {

	string result = "";

	removeZero(x);
	removeZero(y);

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	for (int i = 0, j = 0; i < max(y.length(), x.length()) || j; i++) {
		int temp = j;
		if (i < x.length()) {
			temp += (x.at(i) - '0');
		}
		if (i < y.length()) {
			temp += (y.at(i) - '0');
		}
		int q = temp % 10;
		result.insert(0, intToString(q));
		j = temp / 10;
	}

	return result;

}

// Subtrack two big numbers;
string sub(string &x, string &y) {

	string result = "";

	removeZero(x);
	removeZero(y);

	int len1 = x.length();
	int len2 = y.length();
	int len = len1 > len2 ? len1 : len2;
	int *temp = (int *)malloc(sizeof(int) * len);

	string s;
	if (len1 > len2) {
		s = "+";
	} else if(len1 < len2) {
		s = "-";
	} else {
		int i;
		for (i = 0; i < len1; i++) {
			if (x.at(i) == y.at(i)) {
				continue;
			} else if (x.at(i) < y.at(i)) {
				s = "-";
				break;
			} else {
				s = "+";
				break;
			}
		}
		if (i == len1) {
			return "0";
		}
	}

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int q = 0; // Don't forget initilization.
	for (int i = 0; i < len; i++) {
		int a = i < len1 ? x.at(i) - '0' : 0; // Transform to a int.
		int b = i < len2 ? y.at(i) - '0' : 0;

		if (s.at(0) == '+') {
			temp[q++] = a - b;
		} else {
			temp[q++] = b - a;
		}
	}

	for (int i = 0; i < q; i++) {
		if (temp[i] < 0) {
			temp[i + 1] -= 1;
			temp[i] += 10;
		}
	}
	
	q -= 1;
	while (temp[q] == 0) {
		q -= 1;
	}
	for (int i = q; i >= 0; i--) {
		result += intToString(temp[i]);
	}

	if (s.at(0) == '-') {
		return s + result;
	}

	//cout << "sub result: " << result << endl;
	return result;

}
