//KMP算法
<a href = "http://blog.csdn.net/sr_19930829/article/details/44492631#"> kmp </a>
char a[maxn];//主串  
char b[maxm];//模式串  
int lena,lenb;  
int nex[maxm]; 

void kmp_pre(){
	int i, j;
	j = nex[0] = -1;
	i = 0;
	while(i < lenb){
		while(j != -1 && b[i] != b[j]) j = nex[j];
		nex[++i] = ++j;
	}
}
int kmp_count(){
	int i, j;
	int ans = 0;
	kmp_pre();
	i = j = 0;
	while(i < lena){
		while(j != -1 && a[i] != b[j])
			j = nex[j];
		i++, j++;
		if(j >= lenb){
			ans++; 
			j = 0;//不可重叠
			j = nex[j];//可重叠
	
			return i - lenb + 1;//输出最小位置
		}
	}
	return ans;
}
	
//扩展kmp算法
int ex[maxn];
void pre_ekmp() {
	nex[0] = lenb;
	int j = 0;
	while(j + 1 < lenb && b[j] == b[j + 1]) j++;
	nex[1] = j;
	int k = 1;
	for(int i = 2; i < lenb; i++) {
		int p = nex[k] + k;
		int l = nex[i - k];
		if(i + l < p) nex[i] = l;
		else {
			j = max(0, p - i);
			while(i + j < lenb && b[i + j] == b[j]) j++;
			nex[i] = j;
			k = i;
		}
	}
}
void ekmp() {
	pre_ekmp();
	int j = 0;
	while(j < lena & j < lenb && a[j] == b[j]) j++;
	ex[0] = j;
	int k = 0;
	for(int i = 1; i < lena; i++) {
		int p = ex[k] + k;
		int l = nex[i - k];
		if(i + l < p) ex[i] = l;
		else {
			j = max(0, p - i);
			while(i + j < lena && j < lenb && a[i + j] == b[j]) j++;
			ex[i] = j;
			k = i;
		}
	}
}
	
