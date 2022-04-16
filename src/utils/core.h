#ifndef CORE_H
#define CORE_H

#include <gtk/gtk.h>

void visitUrl(char* url) {
    gtk_show_uri_on_window(NULL, url, time(0), NULL);
}

#endif