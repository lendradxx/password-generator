#ifndef SECTIONS_H
#define SECTIONS_H

#include <gtk/gtk.h>
#include <stdbool.h>
#include "utils/core.h"

void generate(GtkBuilder *builder) {
    GtkCheckButton *numberOpt = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "NumberOption"));
    GtkCheckButton *symbolOpt = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "SymbolOption"));
    GtkEntry *passwordLengthEntry = GTK_ENTRY(gtk_builder_get_object(builder, "LengthPassword"));
    GtkTextBuffer *resultText = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "resultText"));

    bool numberOption = false;
    bool symbolOption = false;
    int length = 1;
    char *result = malloc(length * sizeof(char*));

    // int passwordLength = atoi(gtk_entry_get_text(passwordLengthEntry)) || 0;
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(numberOpt))) {
        numberOption = true;
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(symbolOpt))) {
        symbolOption = true;
    }

    generatePassword(length, numberOption, symbolOption, result);
    gtk_text_buffer_set_text(resultText, "Hello Worlds", -1);

    // Free memory
    free(result);
}

void initSections(GtkWidget *window, GtkBuilder *builder) {
    GtkButton *generateBtn = GTK_BUTTON(gtk_builder_get_object(builder, "generateBtn"));

    // Signal handlers
    g_signal_connect_swapped(generateBtn, "clicked", G_CALLBACK(generate), builder);
}

#endif