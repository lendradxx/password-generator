#ifndef APP_H
#define APP_H

#include <gtk/gtk.h>

void launchApp(GtkApplication* app, gpointer userData) {
    GtkWidget* window;
    GtkBuilder *builder;
    builder = gtk_builder_new_from_resource("/res/ui/app.ui");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main"));

    // Show all widget
    gtk_application_add_window(app, GTK_WINDOW(window));
    gtk_widget_show_all(window);
}

int initApp(int argc, char* argv[]) {
    GtkApplication* app;
    int status;
    app = gtk_application_new("lendradxx.app.passwordgenerator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(launchApp), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

#endif