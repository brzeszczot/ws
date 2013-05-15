SRCS     := source1.cpp source2.cpp etc.cpp
OBJS     := $(SRCS:.cpp=.o)
CXXFLAGS := -Wall -pedantic
INCPATHS := -I/usr/include/mysql
LIBPATHS := -L/usr/lib/mysql -LotherPath
LIBS     := -static -lmysqlclient -lotherLib
EXE      := MyExecutable

...

$(EXE): $(OBJS)
        $(CXX) $(OBJS) $(LIBPATHS) $(LIBS) -o $@

.cpp.o:
        $(CXX) $(CXXFLAGS) $(INCPATHS) -c $< -o $@





-------------- Build: Debug in ws (compiler: GNU GCC Compiler)---------------

g++ -Wall -Wall -g  -c /var/www/cgi-bin/ws/main.cpp -o obj/Debug/main.o
g++  -o bin/Debug/ws obj/Debug/Bmysql.o obj/Debug/Config.o obj/Debug/Engine.o obj/Debug/Functions.o obj/Debug/Logger.o obj/Debug/Logic.o 
obj/Debug/main.o obj/Debug/Xml.o  -lboost_system -lpthread -static-libgcc  /usr/lib/libboost_filesystem.a /usr/lib/libmysqlclient.a
Output size is 8.55 MB
Process terminated with status 0 (0 minute(s), 3 second(s))
0 error(s), 0 warning(s) (0 minute(s), 3 second(s))
 

-------------- Run: Debug in ws (compiler: GNU GCC Compiler)---------------

Checking for existence: /var/www/cgi-bin/ws/bin/Debug/ws
Executing: xterm -T ws -e /usr/local/bin/cb_console_runner LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. /var/www/cgi-bin/ws/bin/Debug/ws  (in 
/var/www/cgi-bin/ws/.)
Process terminated with status 0 (0 minute(s), 2 second(s))
 

