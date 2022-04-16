#include <gtk/gtk.h>
#include "components/menubars.h"
#include "utils/core.h"

void launchApp(GtkApplication* app, gpointer userData) {
    GtkWidget* window;
    GtkBuilder* builder;
    builder = gtk_builder_new_from_resource("/res/ui/app.ui");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main"));

    // Setup window
    gtk_window_set_title(GTK_WINDOW(window), "Password Generator");
    gtk_window_set_default_size(GTK_WINDOW(window), 812, 412);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_application_add_window(app, GTK_WINDOW(window));
    initMenubars(window, builder);

    // Show all widget
    gtk_widget_show_all(window);
}

int main(int argc, char* argv[]) {
    GtkApplication* app;
    int status;
    app = gtk_application_new("lendradxx.app.passwordgenerator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(launchApp), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}