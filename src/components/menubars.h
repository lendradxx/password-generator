#ifndef MENUBAR_H
#define MENUBAR_H

#include <gtk/gtk.h>
#include "utils/core.h"

void fullscreenMode(GObject* data) {
    GtkWindow* window = g_object_get_data(data, "window");
    GtkMenuItem* fullscreenbtn = g_object_get_data(data, "button");
    char* status = g_object_get_data(data, "status");

    if (status == "full") {
        g_object_set_data(data, "status", "unfull");
        gtk_window_unfullscreen(window);
        gtk_menu_item_set_label(fullscreenbtn, "Fullscreen");
    } else {
        g_object_set_data(data, "status", "full");
        gtk_window_fullscreen(window);
        gtk_menu_item_set_label(fullscreenbtn, "Leave Fullscreen");
    }
}

void initMenuApp(GtkWidget* window, GtkBuilder* builder) {
    GtkMenuItem* quitBtn = GTK_MENU_ITEM(gtk_builder_get_object(builder, "QuitBTN"));
    GtkMenuItem* fullscreenBtn = GTK_MENU_ITEM(gtk_builder_get_object(builder, "FullscreenToggle"));
    g_object_set_data(G_OBJECT(fullscreenBtn), "button", fullscreenBtn);
    g_object_set_data(G_OBJECT(fullscreenBtn), "window", window);
    g_object_set_data(G_OBJECT(fullscreenBtn), "status", "unfull");

    // Signal handlers
    g_signal_connect_swapped(quitBtn, "activate", G_CALLBACK(gtk_widget_destroy), window);
    g_signal_connect(fullscreenBtn, "activate", G_CALLBACK(fullscreenMode), NULL);
}

void initMenuView(GtkWidget* window, GtkBuilder* builder) {

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
    initMenuView(window, builder);
}

#endif