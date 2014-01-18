ADD_DEFINITIONS(-Wall -O2)

# ADD_EXECUTABLE(clablibtest 
# 	list_test.c
# 	random_test.c
# 	test_suite.c)

# ADD_EXECUTABLE(clablibtest random_test.c)
# TARGET_LINK_LIBRARIES(clablibtest cunit)
# TARGET_LINK_LIBRARIES(clablibtest clablib)

ADD_EXECUTABLE(clablib_test clablib_test.c)
TARGET_LINK_LIBRARIES(clablib_test clablib)
