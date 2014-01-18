ADD_DEFINITIONS(-Wall -O2)

ADD_LIBRARY(clablib SHARED 
	list.c
	map.c
	sort.c
	random.c
	math.c
	clock.c
	stack.c
	temp.c
	text.c)
