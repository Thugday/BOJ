#include <iostream>
#include <string>
#define MAX_WORD 1000001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int count(1);
	int i(0);
	char str[MAX_WORD];

	cin.getline(str, MAX_WORD);
	
	while (str[i] != '\0') {
		if (str[i] == ' ' && str[i + 1] != '\0') {
			count++;
		}
		i++;
	}

	if (str[0] == '\0' || str[0] == ' ') {
		count--;
	}

	cout << count << "\n";
}