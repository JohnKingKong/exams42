#include <unistd.h>
#include <stdlib.h>

// char *get_next_line(int fd)
// {
// 	int i = 0, j = 0;
// 	char c;
// 	char *buf = malloc(10000);

// 	while ((i = read(fd, &c, 1)) > 0) {
// 		buf[j++] = c;
// 		if (c == '\n')
// 			break;
// 	}
// 	if ((!buf[i - 1] && !i) || i == -1) {
// 		free(buf);
// 		return NULL;
// 	}
// 	buf[j] = '\0';
// 	return buf;
// }


char *get_next_line(int fd) {
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}
