#include <gtkmm.h>
#include "viewertagger.h"

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);
  ViewerTagger vt;
  Gtk::Main::run(vt);
  return EXIT_SUCCESS;
}
