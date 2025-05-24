//没读题导致的
#include<bits/stdc++.h>
using namespace std;

typedef struct skill
{
	int t;
	int c;
} S;

void quickSort(vector<S> &Skills, int start, int end) {
    if (start < end) {
		S base_element = Skills[start];
        int base = Skills[start].c;
        int left = start;
        int right = end;
        while (left < right) {
            while (left< right && Skills[right].c >= base) {
                right--;
            }
            Skills[left] = Skills[right];
            while (left < right && Skills[left].c <= base){
                left++;
            }
            Skills[right] = Skills[left];
        }
        Skills[left] = base_element;
        quickSort(Skills, start, left - 1);
        quickSort(Skills, left + 1, end);
    }
}

int TotalCd(vector<S> &Skills)
{
	int sum = 0;
	for (S a : Skills) sum += a.t;
	return sum;
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<S> Skills(n);
	for(int i = 0; i < n; i++) {
		cin >> Skills[i].t >> Skills[i].c;
	}
	quickSort(Skills, 0, Skills.size() - 1);

	for(int i = 0; i < n; i++) {
		while(Skills[i].t > k) {
			if(m >= Skills[i].c) {
				m -= Skills[i].c;
				Skills[i].t--;
			}
			else {
				cout << TotalCd(Skills);
				system("pause");
				return 0;
			}
		}
	}
	cout << k * n;
	system("pause");
	return 0;
}