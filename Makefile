# Scott Fusilier 2012

CC=c++
CFLAGS=-DGSEAL_ENABLE -D_REENTRANT -D_THREAD_SAFE 
BINDIR=BIN/
SRCDIR=SRC/
EXECUTABLE=$(BINDIR)app
SOURCES=$(SRCDIR)*.cpp
OBJS=*.o
LIBS=-I/usr/local/include/gtkmm-3.0 -I/usr/local/lib/gtkmm-3.0/include -I/usr/local/include/atkmm-1.6 -I/usr/local/include/giomm-2.4 -I/usr/local/lib/giomm-2.4/include -I/usr/local/include/pangomm-1.4 -I/usr/local/lib/pangomm-1.4/include -I/usr/local/include/gtk-3.0 -I/usr/local/include/cairomm-1.0 -I/usr/local/lib/cairomm-1.0/include -I/usr/local/include/gdk-pixbuf-2.0 -I/usr/local/include/gtk-3.0/unix-print -I/usr/local/include/gdkmm-3.0 -I/usr/local/lib/gdkmm-3.0/include -I/usr/local/include/atk-1.0 -I/usr/local/include/glibmm-2.4 -I/usr/local/lib/glibmm-2.4/include -I/usr/local/include/glib-2.0 -I/usr/local/include/sigc++-2.0 -I/usr/local/lib/sigc++-2.0/include -I/usr/local/include/pango-1.0 -I/usr/local/include/cairo -I/usr/local/include/pixman-1 -I/usr/local/include -I/usr/local/include/freetype2 -I/usr/local/include/gio-unix-2.0/  -pthread -L/usr/local/lib -lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lgtk-3 -lglibmm-2.4 -lcairomm-1.0 -lgdk-3 -latk-1.0 -lpangocairo-1.0 -lXext -lXinerama -lXi -lXrandr -lXcursor -lXcomposite -lXdamage -lgdk_pixbuf-2.0 -lcairo-gobject -lpangoft2-1.0 -lgio-2.0 -lXfixes -lX11 -lpango-1.0 -lfreetype -lfontconfig -lcairo -lgobject-2.0 -lgmodule-2.0 -lpng -lz -lm -lgthread-2.0 -lglib-2.0 -lsigc-2.0   -I/usr/local/include -L/usr/local/lib -lmysqlcppconn
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
 
 
$(EXECUTABLE) : $(SRCS)
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS) $(LIBS)

