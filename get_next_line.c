#include "get_next_line.h"
#include <stdio.h>

void *myfree(void *f)
{
	free(f);
	return (NULL);
}

char *get_next_line(int fd)
{
	char *ret = (char *)malloc(sizeof(char) * 9999);
	char buffer = 0;
	int i = 1;
	int j = 0;
    
    if (BUFFER_SIZE <= 0)
        return (myfree(ret));
	while(i > 0)
	{
		i = read(fd, &buffer, 1);
		if(i <= 0)
			break ;
		ret[j++] = buffer;
		if(buffer == '\n')
			break ;
	}
	ret[j] = 0;
	if(!*ret)
		return(myfree(ret));
	return (ret);
}

