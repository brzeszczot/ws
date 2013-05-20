SRCS     := main.cpp Xml.cpp Logic.cpp Logger.cpp Functions.cpp Engine.cpp Config.cpp Bmysql.cpp
OBJS     := $(SRCS:.cpp=.o)
CXXFLAGS := -Wall
INCPATHS := -I/usr/include
LIBPATHS := -L/usr/lib
LIBS     := -lboost_system -pthread -lboost_thread -lmysqlclient /usr/local/lib/libboost_filesystem.a /usr/lib/libmysqlclient.a
EXE      := ws

$(EXE): $(OBJS)
	$(CXX) $(OBJS) $(LIBPATHS) $(LIBS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCPATHS) -c $< -o $@

clean:
	rm -f *.o *.so
