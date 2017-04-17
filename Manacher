//Manacher算法 最长回文子串 MP数组存的是该点为中心的回文串长度+1
char MA[maxn << 1]; int MP[maxn << 1];
void Manacher(char s[], int len) {
	int l = 0;
	MA[l++] = '$'; MA[l++] = '#';
	for(int i = 0; i < len; i++){
		MA[l++] = s[i];
		MA[l++] = '#';
	}
	MA[l] = 0;
	int mx = 0, id = 0;
	for(int i = 0; i < l; i++){
		MP[i] = mx > i ? min(MP[2 * id - 1], mx - i) : 1;
		while(MA[i + MP[i]] == MA[i - MP[i]]) MP[i]++;
		if(i + MP[i] > mx){
			mx = i + MP[i];
			id = i;
		}
	}
}
