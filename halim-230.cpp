// C-style coding study
// Reference: https://blog.csdn.net/mobius_strip/article/details/79827926

#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct book {
	char title[99];
	char author[99];
	bool operator < (book other) const {
		if (strcmp(author, other.author))
			return strcmp(author, other.author) < 0;
		else return strcmp(title, other.title) < 0;
	}
};

book Book[1111];
map<string, string> book_state;

int main() {
	char buf[256], title[99];
	int book_size = 0;
	book_state.clear();
	while (gets(buf) && strcmp(buf, "END")) {
		int position = strchr(buf + 1, '"') - buf;
		strncpy(Book[book_size].title, buf, position + 1);
		strcpy(Book[book_size].author, buf + position + 5);
		book_state[Book[book_size].title] = "SHELVE";
		book_size++;
	}
	sort(Book, Book + book_size);
	while (gets(buf) && strcmp(buf, "END")) {
		if (buf[0] == 'B') {
			strcpy(title, buf + strlen("BORROW "));
			book_state[title] = "BORROW";
		}
		else if (buf[0] == 'R') {
			strcpy(title, buf + strlen("RETURN "));
			book_state[title] = "RETURN";
		}
		else if (buf[0] == 'S') {
			for (int i = 0; i < book_size; ++i) {
				if (book_state[Book[i].title] == "RETURN") {
					book_state[Book[i].title] = "SHELVE";
					int index = -1;
					for (int j = i - 1; j >= 0; --j) {
						if (book_state[Book[j].title] == "SHELVE") {
							index = j;
							break;
						}
					}
					if (index == -1) printf("Put %s first\n", Book[i].title);
					else printf("Put %s after %s\n", Book[i].title, Book[index].title);
				}
			}
			printf("END\n");
		}
	}
}
