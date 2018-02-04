template<typename T>
int compare(T value1,T value2){
	if(value1 < value2)
		return -1;
	else if(value1 == value2)
		return 0;
	else if(value1 > value2)
		return 1;
}
