CFLAGS=	-W -Wall -I./lib/mongoose/ -pthread -g

all:
	OS=`uname`; \
	  test "$$OS" = Linux && LIBS="-ldl" ; \
	  $(CXX) $(CFLAGS) ./server.cpp ./lib/mongoose/mongoose.c  $$LIBS $(ADD) -o serverJudo
	./serverJudo;

clean:
	rm -rf serverJudo *.dSYM;
