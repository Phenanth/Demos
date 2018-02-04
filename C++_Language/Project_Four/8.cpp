int f(int x){
	return x*x;
}
int sum(int (*fp)(int), int start, int end){
	int n = start, temp=0;
	while(n <= end)
		temp += f(n++);
	return temp;
}