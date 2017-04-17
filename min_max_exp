//字符串的最大最小表示法 true = min,  false = max;
int min_max_exp(char b[], int lenb, bool flag) {
	int i = 0, j = 1, k = 0;
	while(i < lenb && j < lenb && k < lenb){
		int t = b[(j + k) % lenb] - b[(i + k) % lenb];
		if(t == 0) k++;
		else {
			if(flag){
				if(t > 0) j += k + 1;
				else i += k + 1;
			}
			else {
				if(t > 0) i += k + 1;
				else j += k + 1;
			}
			if(i == j) j++;
			k = 0;
		}
	}
	return min(i, j);
}
