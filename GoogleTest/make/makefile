GTEST_DIR = /Users/joh/Documents/מטלות/2017-2018/C++/cpp-3/GoogleTest
USER_DIR = $(GTEST_DIR)/unit_test
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS=-std=c++11 

CXX = g++


TESTS = test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)



CircularInt.o : $(USER_DIR)/CircularInt.cpp $(USER_DIR)/CircularInt.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/CircularInt.cpp

test.o : $(USER_DIR)/test.cpp \
                     $(USER_DIR)/CircularInt.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test.cpp

test : CircularInt.o test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) gtest_main.a -lpthread $^ -o $@
	./test


clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
