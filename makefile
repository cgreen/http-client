CC=gcc
CXX=g++
RM=rm -f

SRCS=HttpClient.cpp HttpClient.h
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend

