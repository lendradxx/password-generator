#ifndef MENUBAR_H
#define MENUBAR_H

#include <gtk/gtk.h>
#include "utils/core.h"

void initMenuApp(GtkWidget* window, GtkBuilder* builder) {
    GtkMenuItem* quitBtn = GTK_MENU_ITEM(gtk_builder_get_object(builder, "QuitBTN"));
    
    // Signal handlers
    g_signal_connect_swapped(quitBtn, "activate", G_CALLBACK(gtk_widget_destroy), window);
}

void initMenuInfo(GtkWidget* window, GtkBuilder* builder) {
    GtkMenuItem* sourceCodeBtn = GTK_MENU_ITEM(gtk_builder_get_object(builder, "SourceCodeBTN"));

    // Signal Handlers
    g_signal_connect_swapped(sourceCodeBtn, "activate", G_CALLBACK(visitUrl), "https://github.com/lendradxx/password-generator.git");
}

/**
 * Initialize menubar for window
 * @param window The window widget
 * @param builder The builder
 */
void initMenubars(GtkWidget* window, GtkBuilder* builder) {
    initMenuApp(window, builder);
    initMenuInfo(window, builder);
}

#endif