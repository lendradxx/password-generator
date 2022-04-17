#ifndef CORE_H
#define CORE_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visitUrl(char* url) {
    gtk_show_uri_on_window(NULL, url, time(0), NULL);
}

int randomNumber(int minimum, int maximum) {
    srand(time(0));
    return (rand() % (maximum - minimum)) + 1;
}

#endif